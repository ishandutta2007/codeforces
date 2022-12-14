#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7;
int n,m;
struct linear
{
	int arr[5];
	bool flag;
	void clear()
	{
		memset(arr,0,sizeof(arr));
		flag=0;
	}
	void add(int x)
	{
		for (int i=4;i>=0;i--)
		{
			if (x&(1<<i))
			{
				if (!arr[i]) 
				{
					for (int j=i-1;j>=0;j--)
					{
						if ((x&(1<<j)) && arr[j]) x^=arr[j];
					}
					arr[i]=x;
					for (int j=i+1;j<=4;j++)
					{
						if (arr[j]&(1<<i)) arr[j]^=arr[i];
					}
					return;
				}
				x^=arr[i];
			}
		}
		flag=1;
	}
	int to_msk()
	{
		int res=0;
		for (int i=0;i<=4;i++)
		{
			res=(res<<5)+arr[i];
		}
		return res;
	}
	void to_linear(int msk)
	{
		for (int i=4;i>=0;i--)
		{
			arr[i]=msk&31;
			msk>>=5;
		}
		flag=0;
	}
	void out()
	{
		for (int i=4;i>=0;i--)
		{
			for (int j=4;j>=0;j--)
			{
				if (arr[i]&(1<<j)) putchar('1');
				else putchar('0');
			}
			putchar('\n');
		}
		putchar('\n');
	}
}a,b,c;
int dp[1<<21],pos[1111],ad[1<<21],cp;
bool f[1<<21];
int x,y,z,dep[111111],pa[111111],dfn[111111],cnt,fake,msk,vl,ans;
vector<pair<int,int> > g[111111];
vector<int> ng[111111];
void dfs(int i,int fa,int d)
{
	pa[i]=fa;
	dep[i]=d;dfn[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		if (!dfn[to])
		{
			ng[i].push_back(to);
			dfs(to,i,d^val);
		}
	}
}
void dft(int i)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second,len;
		if (dfn[to]>dfn[i]) continue;
		if (pa[i]==to || pa[to]==i) continue;
		len=dep[to]^dep[i]^val;
		if (to==1) fake=len;
		else 
		{
			a.add(len);
		}
	}
	for (int j=0;j<ng[i].size();j++)
	{
		dft(ng[i][j]);
	}
}
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	dfs(1,0,0);
	dp[0]=1;cp=1;pos[1]=0;f[0]=1;
	for (int i=0;i<ng[1].size();i++)
	{
		a.clear();fake=-1;
		dft(ng[1][i]);
		if (a.flag) continue;
		int rp=cp;
		for (int k=1;k<=rp;k++)
		{
			msk=pos[k];vl=dp[pos[k]];b.to_linear(msk);
			if (!~fake)
			{
				for (int j=0;j<5;j++)
				{
					if (a.arr[j]) b.add(a.arr[j]);
				}
				if (!b.flag) 
				{
					int tt=b.to_msk();
					if (!f[tt]) 
					{
						pos[++cp]=tt;
						f[tt]=1;
					}
					add(ad[tt],vl);
				}
			}
			else
			{
				c=b;
				for (int j=0;j<5;j++)
				{
					if (a.arr[j]) c.add(a.arr[j]);
				}
				if (!c.flag) 
				{
					int tt=c.to_msk();
					if (!f[tt]) 
					{
						f[tt]=1;
						pos[++cp]=tt;
					}
					add(ad[tt],(vl+vl)%mod);
				}
				b.add(fake);
				if (b.flag) continue;
				c=b;
				for (int j=0;j<5;j++)
				{
					if (a.arr[j]) c.add(a.arr[j]);
				}
				if (!c.flag) 
				{
					int tt=c.to_msk();
					if (!f[tt])
					{
						f[tt]=1;
						pos[++cp]=tt;
					}
					add(ad[tt],vl);
				}
			}
		}
		for (int j=1;j<=cp;j++)
		{
			add(dp[pos[j]],ad[pos[j]]);
			ad[pos[j]]=0;
		}
	}
	for (int i=1;i<=cp;i++)
	{
		add(ans,dp[pos[i]]);
	}
	printf("%d\n",(ans+mod)%mod);
	return Accepted;
}