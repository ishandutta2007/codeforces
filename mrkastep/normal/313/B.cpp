#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>
#include <string>
#define For(i,n) for(i=0;i<n;i++)

int max(int x,int y){
	if(x>y) return x;
	return y;
}

int a[100100];

void solve(char s[]){
	int i,n,l,r;
	a[0]=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]==s[i+1]) a[i+1]=a[i]+1;
		else a[i+1]=a[i];
	}
	scanf("%d",&n);
	For(i,n){
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r-1]-a[l-1]);
	}
}

void main(){
#pragma comment (linker,"/STACK:67108864")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n,m;
	char s[100100];
	while(scanf("%s",&s)!=EOF) solve(s);
}