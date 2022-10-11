#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define MX 10000000
int nrm[MX+5],lp[MX+5],a[200005];
int main()
{
	nrm[1]=1;
	for (int i=2;i<=MX;i++)
	{
		if (!lp[i])
		{
			for (int j=i;j<=MX;j+=i)
			{
				if (!lp[j])
				lp[j]=i;
			}
		}
		if ((i/lp[i])%lp[i]==0)
		nrm[i]=nrm[i/(lp[i]*lp[i])];
		else
		nrm[i]=nrm[i/lp[i]]*lp[i];
	}
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,k,ans=0;
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=nrm[a[i]];
		}
		for (int i=0;i<n;)
		{
			ans++;
			set<int> s;
			int j=i;
			while (j<n)
			{
				s.insert(a[j]);
				if ((int)s.size()!=(j-i+1))
				break;
				j++;
			}
			i=j;
		}
		printf("%d\n",ans);
	}
}