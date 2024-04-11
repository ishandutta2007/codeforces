#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define pb push_back
#define SZ(x) ((int)x.size())
using namespace std;

const int maxn = 5100;
const int maxc = 2100000;

int n,A,B;
int s[maxn],Real[maxn],mx[maxn],mn[maxn];
vector<int>c[maxn];

namespace Task1
{		
	inline void down(int &a,const int &b){if(a>b)a=b;}
	inline int gcd(int a,int b){return !a?b:gcd(b%a,a);}
	
	
	struct edge{int y,nex;}a[maxn*maxn]; int len,fir[maxn];
	inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}
	
	int dfn[maxn],low[maxn],id;
	int bel[maxn],g[maxn],cnt;
	vector<int>V[maxn];
	int t[maxc],insta[maxn],tp;
	void tarjan(const int x)
	{
		dfn[x]=low[x]=++id; insta[t[++tp]=x]=1;
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y)
		{
			if(!dfn[y]) tarjan(y),down(low[x],low[y]);
			else if(insta[y]) down(low[x],dfn[y]);
		}
		if(dfn[x]==low[x])
		{
			g[++cnt]=0;
			int la=0;
			while(la!=x)
			{
				insta[la=t[tp--]]=0;
				V[bel[la]=cnt].pb(la);
				g[cnt]=gcd(g[cnt],s[la]);
			}
		}
	}
	vector<int>scc[maxn];
	vector<int>E[maxn];
	queue<int>q; int ind[maxn];
	void Solve()
	{
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
		for(int i=1;i<=cnt;i++)
		{
			for(int j=0;j<g[i];j++) t[j]=0;
			for(int j=0;j<SZ(V[i]);j++)
			{
				int x=V[i][j];
				for(int k=0;k<s[x];k++) t[k%g[i]]|=c[x][k];
			}
			for(int j=0;j<g[i];j++) scc[i].pb(t[j]);
		}
		
		for(int x=1;x<=n;x++)
		{
			for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(bel[y]!=bel[x])
				ind[bel[y]]++,E[bel[x]].pb(bel[y]);
		}
		for(int i=1;i<=cnt;i++) if(!ind[i]) q.push(i);
		int las=0;
		while(!q.empty())
		{
			int x=q.front(); q.pop();
			for(int j=0;j<SZ(E[x]);j++)
			{
				int y=E[x][j];
				ind[y]--; if(!ind[y]) q.push(y);
			}
			if(las)
			{
				int tmp=gcd(g[las],g[x]);
				for(int j=0;j<tmp;j++) t[j]=0;
				for(int j=0;j<g[las];j++) t[j%tmp]|=scc[las][j];
				for(int j=0;j<g[x];j++) scc[x][j]|=t[j%tmp];
			}
			las=x;
		}
		
		for(int i=1;i<=n;i++)
		{
			mx[i]=mn[i]=Real[i];
			for(int j=0;j<s[i];j++) if(!c[i][j]&&scc[bel[i]][j%g[bel[i]]])
				mx[i]++;
		}
	}
}
namespace Task2
{
	const int mod = 1e9+7;
	inline void add(int &a,const int &b){a+=b;if(a>=mod)a-=mod;}
	
	
	int C[maxn][maxn],use[maxc];
	
	void Cal()
	{
		C[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			C[i][0]=1;
			for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
		
		int ans=0;
		for(int i=1;i<=n;i++) if(!use[mx[i]])
		{
			use[mx[i]]=1;
			int sx=0,sn=0,sa=0;
			for(int j=1;j<=n;j++)
			{
				if(mn[j]>mx[i]) sn++;
				else if(mx[j]>mx[i]) sx++;
				else if(mx[j]==mx[i]) sa++;
			}
			for(int j=0;j<=sn;j++)
			{
				if(sn+B-j>A) continue;
				for(int k=1;k<=sa&&j+k<=B;k++)
				{
					int oth=B-j-k;
					add(ans,(ll)C[sn][j]*C[sx][oth]%mod*C[sa][k]%mod);
				}
			}
		}
		printf("%d\n",ans);
		return;
	}
}
char str[maxc];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		for(int j=1;j<=n;j++) if(str[j-1]=='1') Task1::ins(i,j);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		scanf("%s",str);
		for(int j=0;j<s[i];j++)
		{
			int tc=str[j]-'0';
			Real[i]+=tc,c[i].pb(tc);
		}
	}
	
	Task1::Solve();
	
	Task2::Cal();
	
	return 0;
}