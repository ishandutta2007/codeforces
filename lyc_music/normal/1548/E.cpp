//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 200005
#define lowbit(x) (x&-x)
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int a[N],b[N],c[N],d[N],sta[N][25],stb[N][25],sck[N];
int k,ans;
int tp;
vector<pair<pa,int>>g;
bool cmp(pair<pa,int> x,pair<pa,int> y)
{
	return x.fi.se-x.fi.fi>y.fi.se-y.fi.fi;
}
struct
{
	int c[N],P;
	void init(int x)
	{
		P=x;
		memset(c,0,sizeof(c));
	}
	void update(int x,int y)
	{
		while (x<=P)
		{
			c[x]+=y;
			x+=lowbit(x);
		}
	}
	int query(int x)
	{
		if (x<=0) return 0;
		int res=0;
		while (x)
		{
			res+=c[x];
			x-=lowbit(x);
		}
		return res;
	}
}tree[2];
int querya(int x,int y)
{
	if (x>y) return inf;
	int t=log2(y-x+1);
	return max(sta[x][t],sta[y-(1<<t)+1][t]);
}
int queryb(int x,int y)
{
	if (x>y) return inf;
	int t=log2(y-x+1);
	return max(stb[x][t],stb[y-(1<<t)+1][t]);
}
signed main()
{
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),sta[i][0]=a[i];
	for (int i=1;i<=m;i++)	
		b[i]=read(),stb[i][0]=b[i];
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1ll<<i)-1<=n;j++)
			sta[j][i]=max(sta[j][i-1],sta[j+(1ll<<(i-1))][i-1]);
	
	for (int i=1;i<=20;i++)
	{
		for (int j=1;j+(1ll<<i)-1<=m;j++)
		{
			stb[j][i]=max(stb[j][i-1],stb[j+(1ll<<(i-1))][i-1]);
		}
	}
//	return 0;
	tp=0;
	for (int i=1;i<=n;i++)
	{
		c[i]=inf;
		while (tp&&a[sck[tp]]>=a[i]) tp--;
		if (tp)
		{
			c[i]=min(c[i],querya(sck[tp]+1,i));
		}
		sck[++tp]=i;
	}
	tp=0;
	for (int i=n;i>=1;i--)
	{
		while (tp&&a[sck[tp]]>a[i]) tp--;
		if (tp)
		{
			c[i]=min(c[i],querya(i,sck[tp]-1));
		}
		sck[++tp]=i;
	}
	tp=0;
	for (int i=1;i<=m;i++)
	{
		d[i]=inf;
		while (tp&&b[sck[tp]]>=b[i]) tp--;
		if (tp)
		{
			d[i]=min(d[i],queryb(sck[tp]+1,i));
		}
		sck[++tp]=i;
	}
	tp=0;
	for (int i=m;i>=1;i--)
	{
		while (tp&&b[sck[tp]]>b[i]) tp--;
		if (tp)
		{
			d[i]=min(d[i],queryb(i,sck[tp]-1));
		}
		sck[++tp]=i;
	}
//	return 0;
	for (int i=1;i<=n;i++)
		g.push_back(mp(mp(a[i],c[i]),0));
	for (int i=1;i<=m;i++)
		g.push_back(mp(mp(b[i],d[i]),1));
	sort(g.begin(),g.end(),cmp);
	tree[0].init(2e5);
	tree[1].init(2e5);
	for (auto u:g)
	{
		ans+=tree[u.se^1].query(k-u.fi.fi)-tree[u.se^1].query(k-u.fi.se);
		tree[u.se].update(u.fi.fi,1);
//		cout<<ans<<" "<<u.fi.fi<<" "<<u.fi.se<<" "<<tree[u.se^1].query(k-u.fi.fi)<<" "<<u.se<<endl;
	}
	writeln(ans);
}
/*

*/