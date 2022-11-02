#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>

const int mod=1000000007;

long long int deg[10000000],func;

void solve(int n){
	int i;
	long long int f,d;
	func=0;
	deg[0]=1;
	for(i=2;i<n+1;i++){
		d=deg[i-2]*3;
		f=d-func;
		func=f%mod;
		deg[i-1]=d%mod+mod;
	}
	printf("%I64d\n",func);
}

int main(){
#pragma comment (linker,"/STACK:16777216")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n;
	while(scanf("%d",&n)!=EOF) solve(n);
}