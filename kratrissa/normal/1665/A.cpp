#include<bits/stdc++.h>
using namespace std;
const int N=205;
int T,n,t;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),t=1;
		if(n%4==0){printf("%d %d %d %d\n",n>>2,n>>2,n>>2,n>>2);continue;}
		if(n%6==0){printf("%d %d %d %d\n",n/6,n/2,n/6,n/6);continue;}
		while(n&1^1)n>>=1,t<<=1;
		printf("%d %d %d %d\n",(n-1>>1)*t,(n-3>>1)*t,t,t);
	}
	return 0;
}