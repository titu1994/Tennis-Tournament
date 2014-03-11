/*
 ============================================================================
 Name        : Tennis.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void tennisTournament(int n);
int main(void) {
	int n;
	setbuf(stdout, NULL);
	printf("Enter no of players : ");
	scanf("%d",&n);
	tennisTournament(n);
	return EXIT_SUCCESS;
}

void tennisTournament(int n){
	int i,j,curPos, *rank = NULL, *match = NULL, count,temp,lastPos;
	match = (int*) calloc(n, sizeof(int));
	rank = (int*) calloc(n, sizeof(int));
	curPos = 0;
	count = 0;
	for(i = 0; i < n; i++){
		match[i] = i+1;
		rank[i] = -1;
	}
	int half = (n);
	for(i = 1; i < n; i*=2){
		printf("Match %d:\n",++count);
		for(j = 0; j < half; j+=2){
			if(match[j] > match[j+1]){
				printf("%d Vs %d. Winner : %d\n", match[j], match[j+1], match[j]);
				match[j/2] = match[j];
				rank[curPos++] = match[j];
			}
			else{
				printf("%d Vs %d. Winner : %d\n", match[j], match[j+1], match[j+1]);
				match[j/2] = match[j+1];
				rank[curPos++] = match[j+1];
			}
		}
		half /= 2;
	}
	for(i = 0; i < n; i++)
		printf("%d  ",rank[i]);
	printf("\n");

	curPos = n-2;
	lastPos = curPos-2;
	temp = rank[curPos];

	printf("%d -> %d", rank[curPos], rank[lastPos]);
	for(i = 2; i <= (n/2)-1; i++){
		for(j = lastPos-1; j > 0; j--){
			if(rank[j] == temp){
				temp = rank[j-1];
				lastPos = j-1;
				break;
			}
		}
		if(j == 0){
			printf(" - > %d", rank[lastPos]-1);
			break;
		}
		curPos = lastPos;
		if(curPos >= 0){
			printf(" - > %d", rank[curPos]);
		}
	}
	free(match);
	free(rank);
}
