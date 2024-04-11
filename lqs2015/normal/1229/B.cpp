#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,x,y,an[111111][22],ans,cur,dep[111111],fuck;
long long a[111111],gd[111111][22],cgcd;
vector<int> g[111111];
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
void dfs(int i,int fa)
{
	an[i][0]=fa;gd[i][0]=a[i];dep[i]=dep[fa]+1;
	for (int j=1;j<=19;j++)
	{
		an[i][j]=an[an[i][j-1]][j-1];
		gd[i][j]=gcd(gd[i][j-1],gd[an[i][j-1]][j-1]);
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		cgcd=a[i];cur=i;
		while(cur)
		{
			fuck=cur;
			for (int j=18;j>=0;j--)
			{
				if (!cur) break;
				if (!cgcd)
				{
					if (gd[cur][j]==0) cur=an[cur][j];
				}
				else
				{
					if (gd[cur][j]%cgcd==0) cur=an[cur][j];
				}
			}
			ans=(1ll*(cgcd%mod)*(dep[fuck]-dep[cur])+ans)%mod;
			cgcd=gcd(cgcd,a[cur]);
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}