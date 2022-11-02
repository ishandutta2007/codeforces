#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>

int a[100001];
long long int r[100001];

long long int max(long long int x,long long int y){
	if(x>y) return x;
	return y;
}

void solve(int n){
	int i,t,x,m;
	for(i=0;i<100001;i++) a[i]=0;
	m=0;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;
		if(x>m) m=x;
	}
	r[0]=0;
	r[1]=a[1];
	for(i=2;i<m+1;i++){
		r[i]=max(r[i-2]+((long long int)a[i])*i,r[i-1]);
	}
	printf("%I64d\n",r[m]);
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