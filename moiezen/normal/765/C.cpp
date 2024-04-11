#include <cstdio>
#include <iostream>
#include <algorithm>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
int main(){
	int k,a,b;
	scanf("%d%d%d",&k,&a,&b);
	int ans=a/k+b/k;
	if(a<k&&b%k) ans=-1;
	if(b<k&&a%k) ans=-1;
	printf("%d",ans);
}