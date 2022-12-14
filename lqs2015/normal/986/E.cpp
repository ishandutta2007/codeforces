#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3,mod=1e9+7;
int n,x,y,a[111111],prime[11111],cnt,mn[11111111],an[111111][22],dep[111111],beg[111111],en[111111],crt;
int q,ans[111111],u[111111],v[111111],lc[111111],bit[222222],sz;
vector<int> g[111111];
vector<int> v1[11111111],v2[11111111];
bool f[11111],used[111111];
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=maxn;j++)
		{
			f[i*prime[j]]=0;
			if (i%prime[j]==0) break;
		}
	}
}
void dfs(int i,int fa)
{
	beg[i]=++crt;
	dep[i]=dep[fa]+1;
	an[i][0]=fa;
	for (int j=1;j<=17;j++) an[i][j]=an[an[i][j-1]][j-1];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
	en[i]=crt;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=17;i>=0;i--)
	{
		if (dep[an[x][i]]>=dep[y]) x=an[x][i];
	}
	if (x==y) return x;
	for (int i=17;i>=0;i--)
	{
		if (an[x][i]!=an[y][i])
		{
			x=an[x][i];
			y=an[y][i];
		}
	}
	return an[x][0];
}
void update(int p,int x)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	Init();
	dfs(1,0);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		x=a[i];
		for (int j=1;j<=cnt;j++)
		{
			if (x%prime[j]==0)
			{
				crt=0;
				while(x%prime[j]==0) 
				{
					crt++;
					x/=prime[j];
				}
				y=1;
				for (int k=1;k<=crt;k++)
				{
					y*=prime[j];
					mn[y]=prime[j];
					v1[y].push_back(i);
				}
			}
		}
		if (x>1)
		{
			mn[x]=x;
			v1[x].push_back(i);
		}
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		ans[i]=1;
		scanf("%d%d%d",&u[i],&v[i],&x);
		lc[i]=lca(u[i],v[i]);
		for (int j=1;j<=cnt;j++)
		{
			if (x%prime[j]==0)
			{
				crt=0;
				while(x%prime[j]==0) 
				{
					crt++;
					x/=prime[j];
				}
				y=1;
				for (int k=1;k<=crt;k++)
				{
					y*=prime[j];
					mn[y]=prime[j];
					v2[y].push_back(i);
				}
			}
		}
		if (x>1)
		{
			mn[x]=x;
			v2[x].push_back(i);
		}
	}
	sz=1;
	while(sz<=n) sz<<=1;
	for (int i=2;i<=10000000;i++)
	{
		if (v1[i].empty() && v2[i].empty()) continue;
		for (int j=0;j<v1[i].size();j++)
		{
			update(beg[v1[i][j]],1);
			update(en[v1[i][j]]+1,-1);
			used[v1[i][j]]=1;
		}
		for (int j=0;j<v2[i].size();j++)
		{
			int id=v2[i][j];
			crt=query(beg[u[id]])+query(beg[v[id]])-(query(beg[lc[id]])<<1)+used[lc[id]];
			ans[id]=1ll*ans[id]*binpow(mn[i],crt)%mod;
		}
		for (int j=0;j<v1[i].size();j++)
		{
			update(beg[v1[i][j]],-1);
			update(en[v1[i][j]]+1,1);
			used[v1[i][j]]=0;
		}
	}
	for (int i=1;i<=q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}