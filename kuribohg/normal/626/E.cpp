#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n,ansi,ansl;
long double ans;
LL a[MAXN],s[MAXN];
long double calc(int x,int len)
{
	return (long double)(s[x]-s[x-len-1]+s[n]-s[n-len])/(len+len+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ansi=1,ansl=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=min(i-1,n-i);
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			double x=calc(i,mid)-calc(i,mid-1);
			if(x>=0) l=mid;
			else r=mid-1;
		}
		if(l==r&&calc(i,l)-a[i]>ans) ans=calc(i,l)-a[i],ansi=i,ansl=l;
	}
	printf("%d\n",ansl+ansl+1);
	printf("%d ",a[ansi]);
	for(int i=1;i<=ansl;i++)
		printf("%d ",a[ansi-i]);
	for(int i=1;i<=ansl;i++)
		printf("%d ",a[n+1-i]);
	return 0;
}