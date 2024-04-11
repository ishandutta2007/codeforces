#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 
main(int argc, char **argv) { 
	int a;
	int day[7];
	scanf("%d", &a);
	int sum = 0;
	for (int i = 0; i < 7; i++){
		scanf("%d", &day[i]);
		sum += day[i];
	}	  
	a = a % sum;
	if(a == 0){
		for(int i = 6; i >= 0; i--){
			if(day[i] != 0){
				printf("%d\n", i+1);
				exit(0);
			}
		}	
	}	
	for(int i = 0; i < 7; i++){
		a -= day[i];
		if(a <= 0){
			printf("%d\n", i + 1);
			exit(0);
		}
	}	
 
}