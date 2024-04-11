#include<bits/stdc++.h>
using namespace std;
const int c=(1<<7)-1;
int main(){
	printf("?");
	for(int i=0;i<100;i++){
		printf(" %d",i);
	}
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	printf("?");
	for(int i=0;i<100;i++){
		printf(" %d",(i<<7)+c);
	}
	printf("\n");
	fflush(stdout);
	int y;
	scanf("%d",&y);
	printf("! %d\n",(x&~c)|((y&c)^c));
	fflush(stdout);
	return 0;
}