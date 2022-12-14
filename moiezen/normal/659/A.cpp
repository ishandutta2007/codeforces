#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
int n,m,i,j,k,ans;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	ans=(k+m)%n;
	ans=(ans+n)%n;
	if(ans==0) ans=n;
	printf("%d",ans);
}