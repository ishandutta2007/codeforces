//~~
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
#define mod 998244353
//#define int ll
#define N 400005
#define M N*4
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int id[N][27];
int ru[M],Dfn[M],low[M],sta[M],tp;
bitset<M>ins;
int scc[M];
poly G[M];
int ffa[N];
int tot;
int X[N],Y[N];
string ST[N];
poly gg[M];
poly E[N];
bitset<M>ky;
int dfn[N],rdfn[N];
int cnt;
int DFN;
int n,q;
int p[N][2];
int Bl[M];

void dfs(int k,int fa)
{
	ffa[k]=fa;
	dfn[k]=++DFN;
	for (auto u:E[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
	rdfn[k]=DFN;
}
void ad(int x,int &y)
{
	if (!x) return;
	if (!y) y=++cnt;
	G[x].push_back(y);
}
void Tarjan(int k)
{
	Dfn[k]=++DFN;
	low[k]=DFN;
	sta[++tp]=k;
	ins[k]=1;
	for (auto u:G[k])
	{
		if (!Dfn[u])
		{
			Tarjan(u);
			low[k]=min(low[k],low[u]);
		} else
			if (ins[u]) low[k]=min(low[k],Dfn[u]);
	}
	if (low[k]==Dfn[k])
	{
		tot++;
		while (sta[tp+1]!=k)
		{
			scc[sta[tp]]=tot;
			ins[sta[tp]]=0;
			tp--;
		}
		// cout<<endl;
	}
}
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,0);
	// return;
	for (int i=1;i<=q;i++)
		cin>>X[i]>>Y[i]>>ST[i];
	for (int i=1;i<=q;i++)
	{
		p[i][0]=++cnt;
		p[i][1]=++cnt;
		int x=X[i],y=Y[i];
		string st=ST[i];
		string st1=st;
		reverse(st1.begin(),st1.end());
		
		
		int l=0,r=st.size()-1;
		while (!(dfn[x]<=dfn[y]&&dfn[y]<=rdfn[x]))
		{
			for (int j=1;j<=26;j++)
				if (j==st[l]-'a'+1)
				{
					ad(p[i][0],id[x][j]);
				}
			for (int j=1;j<=26;j++)
				if (j==st1[l]-'a'+1)
				{
					ad(p[i][1],id[x][j]);
				}
			l++;
			x=ffa[x];
		}
		while (1)
		{
			for (int j=1;j<=26;j++)
				if (j==st[r]-'a'+1)
				{
					ad(p[i][0],id[y][j]);
				}
			for (int j=1;j<=26;j++)
				if (j==st1[r]-'a'+1)
				{
					ad(p[i][1],id[y][j]);
				}
			r--;
			if (x==y) break;
			y=ffa[y];
		}
	}
	for (int i=1;i<=q;i++)
	{
		int x=X[i],y=Y[i];
		string st=ST[i];
		string st1=st;
		reverse(st1.begin(),st1.end());
		
		
		int l=0,r=st.size()-1;
		while (!(dfn[x]<=dfn[y]&&dfn[y]<=rdfn[x]))
		{
			for (int j=1;j<=26;j++)
				if (j!=st[l]-'a'+1)
				{
					ad(id[x][j],p[i][1]);
				}
			for (int j=1;j<=26;j++)
				if (j!=st1[l]-'a'+1)
				{
					ad(id[x][j],p[i][0]);
				}
			l++;
			x=ffa[x];
		}
		while (1)
		{
			for (int j=1;j<=26;j++)
				if (j!=st[r]-'a'+1)
				{
					ad(id[y][j],p[i][1]);
				}
			for (int j=1;j<=26;j++)
				if (j!=st1[r]-'a'+1)
				{
					ad(id[y][j],p[i][0]);
				}
			r--;
			if (x==y) break;
			y=ffa[y];
		}
	}
	
	
	for (int i=1;i<=cnt;i++)
		if (!Dfn[i])
		{
			Tarjan(i);
		}
	for (int i=1;i<=cnt;i++)
		for (auto u:G[i])
		{
			if (scc[i]!=scc[u]) 
			{
				gg[scc[i]].push_back(scc[u]),ru[scc[u]]++;
			}
		}
		
	for (int i=1;i<=q;i++)
	{
		if (scc[p[i][0]]==scc[p[i][1]]) 
		{
			cout<<"NO"<<endl;
			return;
		}
		int x=p[i][0],y=p[i][1];
		if (scc[x]<scc[y])
		{
			ky[scc[x]]=1;
		} else ky[scc[y]]=1;
	}
	queue<int>q;
	for (int i=1;i<=tot;i++)
		if (!ru[i]) q.push(i);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (auto u:gg[x])
		{
			ky[u]=ky[u]|ky[x];
			ru[u]--;
			if (!ru[u])
				q.push(u);
		}
	}
	for (int i=1;i<=n;i++)
	{
		int x=0;
		for (int j=1;j<=26;j++)
			if (ky[scc[id[i][j]]]) 
			{
				if (!x) x=j;
				else return cout<<"NO"<<endl,void();
			}
	}
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
	{
		int x=1;
		for (int j=1;j<=26;j++)
			if (ky[scc[id[i][j]]]) 
			{
			    x=j;
			}
		cout<<char(x+'a'-1);
	}
			
			
			
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/