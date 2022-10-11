#include <iostream>
#include <vector>
using namespace std;
#define mx 5032107
int lp[mx+5],last[15][mx+5],dp[15][200005],sp[15][20][200005];
vector<int> get(int x)
{
	vector<int> v;
	while (x!=1)
	{
		bool cnt=0;
		int cur=lp[x];
		while (lp[x]==cur)
		x/=lp[x],cnt^=1;
		if (cnt)
		v.push_back(cur);
	}
	return v;
}
int main()
{
	for (int i=2;i<=mx;i++)
	{
		if (!lp[i])
		{
			for (int j=i;j<=mx;j+=i)
			{
				if (!lp[j])
				lp[j]=i;
			}
		}
	}
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		auto v=get(a);
		for (int mask=0;mask<(1<<v.size());mask++)
		{
			int need=v.size(),pro=1;
			for (int j=0;j<v.size();j++)
			{
				if (mask&(1<<j))
				{
					need--;
					pro*=v[j];
				}
			}
			for (int j=need;j<=14;j++)
			dp[j][i]=max(dp[j][i],last[j-need][pro]);
			last[need][pro]=i;
		}
	}
	for (int i=0;i<=14;i++)
	{
		for (int k=1;k<=n;k++)
		sp[i][0][k]=dp[i][k];
		for (int j=1;j<20;j++)
		{
			for (int k=1;k<=n;k++)
			{
				sp[i][j][k]=sp[i][j-1][k];
				int ind=k+(1<<(j-1));
				if (ind<=n)
				sp[i][j][k]=max(sp[i][j][k],sp[i][j-1][ind]);
			}
		}
	}
	while (q--)
	{
		int l,r,len=0;
		scanf("%d%d",&l,&r);
		while ((1<<len)<=r-l+1)
		len++;
		len--;
		for (int i=0;i<=14;i++)
		{
			if (max(sp[i][len][l],sp[i][len][r-(1<<len)+1])>=l)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}