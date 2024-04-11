#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>

const int mod=1000000007;

long long int r[101],fr[101];

void solve(int n,int k,int d){
	int i,j;
	fr[0]=1;
	for(i=1;i<n+1;i++){
		fr[i]=0;
		for(j=1;j<k+1&&j<i+1;j++){
			fr[i]+=fr[i-j];
		}
		fr[i]=fr[i]%mod+mod;
	}
	for(i=0;i<d;i++) r[i]=0;
	for(i=d;i<n+1;i++){
		for(j=1;j<i+1&&j<d;j++){
			r[i]+=r[i-j];
		}
		for(j=d;j<i+1&&j<k+1;j++){
			r[i]+=fr[i-j];
		}
		r[i]=r[i]%mod+mod;
	}
	printf("%I64d",r[n]%mod);
}

int main(){
#pragma comment (linker,"/STACK:16777216")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n,k,d;
	while(scanf("%d%d%d",&n,&k,&d)!=EOF) solve(n,k,d);
}