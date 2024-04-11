#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,l[111111],r[111111],q[111111],t[111111],ans[111111],res[111111],rres[111111],p;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&l[i],&r[i],&q[i]);
	}
	p=1;
	for (int i=0;i<30;i++)
	{
		memset(res,0,sizeof(res));
		memset(rres,0,sizeof(rres));
		for (int j=1;j<=m;j++)
		{
			t[j]=q[j]%2;
			q[j]/=2;
		}
		for (int j=1;j<=m;j++)
		{
			if (t[j])
			{
				res[l[j]]++;
				res[r[j]+1]--;
			}
		}
		for (int j=1;j<=n;j++)
		{
			res[j]+=res[j-1];
		}
		for (int j=1;j<=n;j++)
		{
			if (res[j]>1) res[j]=1;
		}
		for (int j=1;j<=n;j++)
		{
			rres[j]=rres[j-1]+res[j];
		}
		for (int j=1;j<=m;j++)
		{
			if (!t[j]) 
			{
				if (rres[r[j]]-rres[l[j]-1]==r[j]-l[j]+1)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
		for (int j=1;j<=n;j++)
		{
			ans[j]=ans[j]+p*res[j];
		} 
		p<<=1;
	}
	printf("YES\n");
	for (int i=1;i<=n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;
}