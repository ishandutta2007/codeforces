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

int ans[20000];

void solve(int n){
	int a,b,c,i,s,m;
	scanf("%d%d%d",&a,&b,&c);
	s=a+b+c;
	For(i,s+n)ans[i]=0;
	For(i,s)ans[i]=-1;
	for(i=s;i<s+n+1;i++){
		if(i-s==a||i-s==b||i-s==c){
			ans[i]=1;
			ans[i]=max(ans[i],ans[i-a]+1);
			ans[i]=max(ans[i],ans[i-b]+1);
			ans[i]=max(ans[i],ans[i-c]+1);
		}
		else{
			ans[i]=max(ans[i],ans[i-a]+1);
			ans[i]=max(ans[i],ans[i-b]+1);
			ans[i]=max(ans[i],ans[i-c]+1);
			if(ans[i]==0) ans[i]=-1;
		}
	}
	printf("%d",ans[s+n]);
}

void main(){
#pragma comment (linker,"/STACK:67108864")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	int n,m;
	char s[100100];
	while(scanf("%d",&n)!=EOF) solve(n);
}