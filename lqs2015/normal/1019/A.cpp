#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,p[3333],c[3333],l,r,mid,cnt,ct,ans,num[3333],b[3333],cur;
vector<long long> a[3333];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&p[i],&c[i]);
		a[p[i]].push_back(c[i]); 
	}
	for (long long i=1;i<=m;i++)
	{
		sort(a[i].begin(),a[i].end());
	}
	ans=1e18;
	for (long long i=1;i<=n;i++)
	{
		cnt=0;ct=a[1].size();
		memset(num,0,sizeof(num));
		for (long long j=2;j<=m;j++)
		{
			for (long long k=0;k<=(int)(a[j].size())-i;k++)
			{
				num[j]++;cnt+=a[j][k];
				ct++;
			}
		}
		if (ct>=i) ans=min(ans,cnt);
		else
		{
			cur=0;
			for (long long j=2;j<=m;j++)
			{
				for (long long k=num[j];k<a[j].size();k++)
				{
					b[++cur]=a[j][k];
				}
			}
			sort(b+1,b+cur+1);
			for (long long j=1;j<=i-ct;j++) cnt+=b[j];
			ans=min(ans,cnt);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}