// Lynkcat.
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 200005
using namespace std;
int n,m;
int fa[N];
int id[N],id1[N];
vector<pa>G[N];
int f[N],gg[N];
poly g[N],g1[N];

int ggg[N];
int dep[N];
int ffa[N],du[N];
int Dp[125][125][2];
int Dp1[125][2];
int siz[N];

int ans,fac[N];
int tot_Id;map<int,int>Id;
struct node
{
	int x,y,val;
	node(int xx=0,int yy=0,int vval=0)
	{
		x=xx,y=yy,val=vval;
	}
};
vector<node>E;

int gf(int x)
{
    if (x==fa[x]) return x;
    return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
    x=gf(x),y=gf(y);
    if (x==y) return;
    if (x<y) swap(x,y);
    fa[x]=y;
}
void dfs(int k,int fa)
{
	// if (fa!=0)
	// cout<<k<<","<<fa<<endl;
	if (!Id.count(k)) Id[k]=++tot_Id;
	ffa[k]=fa;
	dep[k]=dep[fa]+1;
	for (auto [u,w]:G[k])
	{
		if (u==fa) continue;
		if (dep[u])
		{
			if (dep[u]<dep[k])
			E.push_back(node(k,u,w));
		}
		else
		{
			dfs(u,k);
		}
	}
}
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
void dfs1(int kk,int fa)
{
	int k=Id[kk];
	siz[k]=1;
	Dp[k][0][0]=1;
	Dp[k][1][1]=1;
	if (du[kk]) Dp[k][0][0]=0;
	else Dp[k][1][1]=0;
	for (auto [uu,w]:G[kk])
	{
		if (ffa[uu]!=kk) continue;
		dfs1(uu,kk);
		int u=Id[uu];
		for (int i=0;i<=siz[k];i++)
			for (int o=0;o<=1;o++)
				for (int j=0;j<=siz[u];j++)
					for (int l=0;l<=1;l++)
					{
						if (o==l&&o==0&&i+j+2<=siz[k]+siz[u])
						{
							ad(Dp1[i+j+2][1],Dp[k][i][o]*Dp[u][j][l]%mod*w%mod);
						}
						ad(Dp1[i+j][o],Dp[k][i][o]*Dp[u][j][l]%mod);
					}
					
		for (int j=0;j<=siz[u];j++)
			for (int l=0;l<=1;l++)
				Dp[u][j][l]=0;
				
		siz[k]+=siz[u];
		for (int i=0;i<=siz[k];i++)
			for (int j=0;j<=1;j++)
				Dp[k][i][j]=Dp1[i][j],Dp1[i][j]=0;
	}
}			
void BellaKira()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        id[i]=i;
    for (int i=1;i<=n;i++)
        id1[i]=n+i;
    for (int i=1;i<=2*n;i++)
        fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        if (w!=1)
        {
            G[id[x]].push_back(mp(id1[y],w-1));
            G[id1[y]].push_back(mp(id[x],w-1));
            merge(id[x],id1[y]);
        }
    }
    for (int i=1;i<=n;i++)
        g[gf(i)].push_back(i);
    for (int i=n+1;i<=2*n;i++)
        g1[gf(i)].push_back(i);
    int lst=0;
    f[0]=1;
    for (int i=1;i<=n;i++)
    {
    	if ((g[i].size()+g1[i].size())<=1) continue;
        int tot=0,toteg=0;
        if (g[i].size()>g1[i].size()) swap(g[i],g1[i]);
        for (auto u:g[i])
        	toteg+=G[u].size();
	    for (auto u:g[i])
	        id[u]=tot++;
	    tot+=g1[i].size();
        if (tot<=toteg*2/3)
        {
	        int len=g[i].size();
	        poly dp((1<<len),0),dp1((1<<len),0);
	        dp[0]=1;
	        for (auto u:g1[i])
	        {
	            for (auto &now:dp1) now=0;
	            for (int j=0;j<(1<<len);j++)
	            {
	                dp1[j]=(dp1[j]+dp[j])%mod;
	                for (auto U:G[u])
	                {
	                    int v=U.fi,w=U.se;
	                    v=id[v];
	                    if ((j>>v)&1)
	                        dp1[j]=(dp1[j]+dp[j^(1<<v)]*w%mod)%mod;
	                }
	            }
	            dp.swap(dp1);
	        }
	        poly now(len+1,0);
	        for (int ii=0;ii<(1<<len);ii++)
	        {
	            now[__builtin_popcount(ii)]=(now[__builtin_popcount(ii)]+dp[ii])%mod;
	        }
	        for (int x=0;x<=lst;x++)
	            for (int y=0;y<=len;y++)
	                gg[x+y]=(gg[x+y]+f[x]*now[y]%mod)%mod;
	        for (int x=0;x<=lst+len;x++) f[x]=gg[x],gg[x]=0;
	        lst+=len;
	    } else
	    {
	    	E.clear();
	    	int rt=0;
	    	if (g[i].size()) rt=g[i][0];
	    	else rt=g1[i][0];
	    	dfs(rt,0);
	    	int len=E.size();
	    	int nn=Id[rt];
	    	for (int st=0;st<(1<<len);st++)
	    	{
	    		for (auto u:g[i])
	    		{
	    			du[u]=0;
	    		}
	    		for (auto u:g1[i])
	    		{
	    			du[u]=0;
	    		}
	    		int ad=1;
	    		for (int j=0;j<len;j++)
	    			if ((st>>j)&1)
	    				du[E[j].x]++,du[E[j].y]++,ad=ad*E[j].val%mod;
	    		bool bl=1;
	    		for (auto u:g[i])
	    			if (du[u]>1) bl=0;
	    		for (auto u:g1[i])
	    			if (du[u]>1) bl=0;
	    		if (!bl) continue;
	    		// cout<<len<<" "<<tot<<" "<<toteg<<endl;
	    		dfs1(rt,0);
	    		for (int ii=0;ii<=siz[nn];ii+=2)
	    		{
	    			ggg[ii/2]=(ggg[ii/2]+(Dp[nn][ii][0]+Dp[nn][ii][1])%mod*ad%mod)%mod;
	    		}
	    		// memset(Dp,0,sizeof(Dp));
	    		for (int ii=0;ii<=siz[nn];ii++)
	    			Dp[nn][ii][0]=Dp[nn][ii][1]=0;
	    	}
	    	len=siz[nn]/2;
	        for (int x=0;x<=lst;x++)
	            for (int y=0;y<=len;y++)
	                gg[x+y]=(gg[x+y]+f[x]*ggg[y]%mod)%mod;
	        for (int x=0;x<=lst+len;x++) f[x]=gg[x],gg[x]=ggg[x]=0;	
	        lst+=len;
	    }
    }
    fac[0]=1;
    for (int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%mod;
    for (int i=0;i<=lst;i++)
    {
        ans=(ans+f[i]*fac[n-i]%mod)%mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}