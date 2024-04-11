#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int INF=1000000001;
int n,T,a[MAXN],c[MAXN],pre[MAXN],suf[MAXN],f[MAXN];
void LIS(int a[],int f[],int n)
{
	for(int i=1;i<=n;i++) c[i]=INF;
	for(int i=1;i<=n;i++)
	{
		int x=upper_bound(c+1,c+n+1,a[i])-c;
		f[i]=x;
		c[f[i]]=a[i];
	}
}
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(T<=n+n)
	{
		for(int i=1;i<T;i++)
			for(int j=1;j<=n;j++)
				a[i*n+j]=a[j];
		LIS(a,f,n*T);
		printf("%d\n",*max_element(f+1,f+n*T+1));
	}
	else
	{
		for(int i=1;i<n;i++)
			for(int j=1;j<=n;j++)
				a[i*n+j]=a[j];
		LIS(a,pre,n*n);
		reverse(a+1,a+n*n+1);
		for(int i=1;i<=n*n;i++) a[i]=301-a[i];
		LIS(a,suf,n*n);
		reverse(suf+1,suf+n*n+1);
		for(int i=1;i<=n*n;i++) a[i]=301-a[i];
		reverse(a+1,a+n*n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x=0;
			for(int j=1;j<=n;j++)
				if(a[j]==a[i]) x++;
			for(int j=1;j<=n;j++)
				if(a[j]>=a[i]) ans=max(ans,x*(T-n-n)+pre[n*(n-1)+i]+suf[j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}