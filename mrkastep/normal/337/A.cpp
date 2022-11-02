#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>
#define For(i,n) for(i=0;i<n;i++)

std::vector<std::vector<int>> v(10000);

int st[10000],d[10000],dm;

int max(int x,int y){
	if(x>y) return x;
	return y;
}

void solve(int n,int m){
	int a[55],i,min;
	For(i,m) scanf("%d",&a[i]);
	std::sort(a,a+m);
	min=a[m-1];
	For(i,m-n+1) if(a[i+n-1]-a[i]<min) min=a[i+n-1]-a[i];
	printf("%d",min);
}

void main(){
#pragma comment (linker,"/STACK:67108864")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF) solve(n,m);
}