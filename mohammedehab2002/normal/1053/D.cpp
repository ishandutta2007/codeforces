#include <bits/stdc++.h>
using namespace std;
#define MX 2000000
#define mod 1000000007
vector<int> d[MX+5];
int p[200005],expo[MX+5],sp[MX+5];
bool need[200005];
int main()
{
	for (int i=2;i<=MX;i++)
	{
		if (d[i].empty())
		{
			for (int j=i;j<=MX;j+=i)
			d[j].push_back(i);
		}
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&p[i]);
	sort(p,p+n);
	memset(sp,-1,sizeof(sp));
	for (int i=n-1;i>=0;i--)
	{
		if (!expo[p[i]])
		{
			expo[p[i]]=1;
			sp[p[i]]=i;
		}
		else
		{
			int tmp=p[i]-1;
			for (int j:d[tmp])
			{
				int cnt=0;
				while (tmp%j==0)
				{
					cnt++;
					tmp/=j;
				}
				if (cnt>expo[j])
				{
					expo[j]=cnt;
					sp[j]=i;
				}
				else if (cnt==expo[j])
				sp[j]=-1;
			}
		}
	}
	for (int i=2;i<=MX;i++)
	{
		if (sp[i]!=-1)
		need[sp[i]]=1;
	}
	long long ans=1;
	for (int i=2;i<=MX;i++)
	{
		while (expo[i])
		{
			ans=(ans*i)%mod;
			expo[i]--;
		}
	}
	if (count(need,need+n,0))
	ans=(ans+1)%mod;
	printf("%I64d",ans);
}