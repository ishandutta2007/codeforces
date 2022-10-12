#include<bits/stdc++.h>
using namespace std;
int main(){
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	for(int i=123; i>=0; i--)
		if(i <= A && i+1 <= B && i+2 <= C){
			printf("%d\n",3*i+3);
			return 0;
		}
	return 0;
}