#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define N 300005
int n,cur,t,a[N];
int main(){
	scanf("%d",&n);
	int cur=n+1;
	printf("1");
	rep(i,1,n){
		scanf("%d",&t);a[t]=1;
		while (a[cur-1]==1) cur--;
		printf(" %d",i+cur-n);
	}
	puts("");
}