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
#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N<<2][4];
int tag[N<<2];
int lstx;
int siz[N];
int tot0,tot1;
int ffa[N];
int fb[N];
int Top[N];
int vis[N];
int totsm;
int U[N];
int idfn[N];
int son[N];
int dfn[N];
poly vec;
int DFN;
vector<int>G[N];
int n;
void dfs(int k,int fa)
{
	siz[k]=1;
	ffa[k]=fa;
	for (auto u:G[k])
	{
		int to=U[u]^k;
		if (to==fa) continue;
		fb[to]=u;
		dfs(to,k);
		siz[k]+=siz[to];
		if (siz[to]>siz[son[k]]) son[k]=to;
	}
}
void dfs1(int k,int tp,int fffa)
{
	dfn[k]=++DFN;
	idfn[DFN]=k;
	Top[k]=tp;
	if (son[k]) dfs1(son[k],tp,k);
	for (auto u:G[k])
	{
		int to=U[u]^k;
		if (to==ffa[k]||to==son[k]) continue;	
		dfs1(to,to,k);
		siz[k]+=siz[to];
	}
}
void pushup(int k)
{
	for (int i=0;i<=3;i++)
		tr[k][i]=tr[k<<1][i]+tr[k<<1|1][i];
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k][0]=1;
		tr[k][1]=0;
		tr[k][2]=0;
		tr[k][3]=fb[idfn[l]];
		// cout<<l<<" "<<fb[idfn[l]]<<endl;
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void pushdown(int k)
{
	if (!tag[k]) return;
	swap(tr[k<<1][0],tr[k<<1][1]);
	swap(tr[k<<1|1][0],tr[k<<1|1][1]);
	swap(tr[k<<1][2],tr[k<<1][3]);
	swap(tr[k<<1|1][2],tr[k<<1|1][3]);
	tag[k<<1]^=1;
	tag[k<<1|1]^=1;
	tag[k]=0;
}
void update(int k,int l,int r,int L,int R)
{
	if (L>R) return;
	if (l>R||r<L) return;
	if (L<=l&&r<=R)
	{
		// if (lstx!=563)
		// {
// 			
// 			
		tot0-=tr[k][0],tot1-=tr[k][1];
		totsm-=tr[k][2];
		
		swap(tr[k][0],tr[k][1]);
		swap(tr[k][2],tr[k][3]);
		
		tot0+=tr[k][0],tot1+=tr[k][1];
		totsm+=tr[k][2];
		tag[k]^=1;
		
		
		// }
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid) update(k<<1,l,mid,L,R);
	if (R>mid) update(k<<1|1,mid+1,r,L,R);
	pushup(k);
}
int query(int k,int l,int r,int t)
{
	if (l==r)
	{
		// cout<<"???"<<l<<" "<<r<<" "<<tr[k][0]<<" "<<tr[k][1]<<endl;
		return tr[k][1];
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (t<=mid) return query(k<<1,l,mid,t);
	return query(k<<1|1,mid+1,r,t);
}
void update(int x)
{
	// if (lstx==563)return;
	while (x>0)
	{
		// cout<<"??"<<x<<" "<<Top[x]<<" "<<dfn[Top[x]]<<" "<<dfn[x]<<endl;
		update(1,1,n,dfn[Top[x]],dfn[x]);
		// cout<<"upd "<<Top[x]<<" "<<dfn[x]<<endl;
		// cout<<"??"<<x<<" "<<Top[x]<<" "<<dfn[Top[x]]<<" "<<dfn[x]<<endl;
		if (Top[x]==1) return;
		x=ffa[Top[x]];
	}
}
void dfs2(int k,int fa)
{
	siz[k]=1;
	for (auto u:G[k])
	{
		int to=U[u]^k;
		if (to==fa||!vis[to]) continue;
		dfs2(to,k);
		siz[k]=siz[k]+siz[to];
	}
	if (siz[k]%2==1) vec.push_back(fb[k]);
	// cout<<k<<" "<<siz[k]<<endl;
}
void BellaKira()
{
	cin>>n;
	lstx=0;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
			if (!lstx) lstx=x;
		U[i]=x^y;
		G[x].push_back(i);
		G[y].push_back(i);
	}
	dfs(1,0);
	dfs1(1,1,0);
	build(1,1,n);
	++tot0;
	update(1,1,n,dfn[1],dfn[1]);
	int p=0;
	while(1)
	{
		int opt;
		cin>>opt;
		if (opt==1)
		{
			int x;
			cin>>x;
			++tot0;
			// if (lstx!=563)
			update(x);
			vis[x]=1;
			if (tot0==tot1) cout<<totsm<<endl;
			else cout<<"0"<<endl;
		}
		else
		if (opt==2)
		{
			if (tot0!=tot1) 
			{
				cout<<"0"<<endl;
				continue;
			}
			vec.clear();
			dfs2(1,0);
			cout<<tot0<<" ";
			sort(vec.begin(),vec.end());
			for (auto u:vec) cout<<u<<" ";
			cout<<endl;
		}
		else
		{
			return;
		}
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