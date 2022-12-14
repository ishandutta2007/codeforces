#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,k,p,l,r,a[1111],b[2222],mid,mxj,mx;
bool used[2222];
long long Abs(long long x)
{
	return max(-x,x);
}
bool check(int dist)
{
	int pos=1;
	for (int i=1;i<=n;i++)
	{
		while(Abs(a[i]-b[pos])+Abs(b[pos]-p)>dist && pos<=k) pos++;
		if (pos>k) return 0;
		pos++;
	}
	return 1;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&k,&p);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=k;i++) scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+k+1); 
	l=0;r=2e9; 
	while(l<=r)
	{
		mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",l);
	return 0;
}