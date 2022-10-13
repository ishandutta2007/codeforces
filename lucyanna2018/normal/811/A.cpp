#include<stdio.h>
int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	for(int i = 1; true; i += 2){
		if(A - i < 0){
			puts("Vladik");
			return 0;
		}
		A -= i;
		if(B - (i+1) < 0){
			puts("Valera");
			return 0;
		}
		B -= (i+1);
	}
}