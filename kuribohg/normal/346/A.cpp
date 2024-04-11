#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int n,g,m;
int a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),m=max(m,a[i]);
	g=gcd(a[1],a[2]);
	for(int i=3;i<=n;i++) g=gcd(a[i],g);
	if((m/g-n)&1) puts("Alice");
	else puts("Bob");
	return 0;
}