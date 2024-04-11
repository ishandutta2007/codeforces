#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 10005
#define oo 1000000000
int n,m,i,j,k,p,q,ans;
int a[N];
int main(){
	scanf("%d",&n);
	if(n&1) printf("0");
	else printf("%d",(n-2)/4);
	return 0;
}