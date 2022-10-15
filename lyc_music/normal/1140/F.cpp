//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fa[N],h[N],ans,q,a[N],b[N];
vector<int>g;
vector<int>G[N<<2];
pa sta[N],s[N];
int tp;
map<pa,vector<int>>Mp;
int id(int x,int y)
{
	if (y==0) return x;
	return x+300000;
}
int gf(int x)
{
	if (x==fa[x]) return x;
	return gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	if (h[x]>h[y]) swap(x,y);
	ans-=s[x].fi*s[x].se,ans-=s[y].fi*s[y].se;
	s[y].fi+=s[x].fi,s[y].se+=s[x].se;
	ans+=s[y].fi*s[y].se;
	h[y]+=h[x];
	fa[x]=y;
	sta[++tp]={x,y};
}
void update(int k,int l,int r,int L,int R,int d)
{
	if (L<=l&&r<=R)
	{
		G[k].push_back(d);
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,R,d);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,d);
}
void slove(int k,int l,int r)
{
	int lsttp=tp;
	for (auto u:G[k])
	{
		merge(id(a[u],0),id(b[u],1));
//		cout<<"add "<<a[u]<<" "<<b[u]<<endl;
	}
	if (l==r)
	{
		writesp(ans);
	} else
	{
		slove(k<<1,l,l+(r-l)/2);
		slove(k<<1|1,l+(r-l)/2+1,r);
	}
	int mid=l+(r-l)/2;
	while (lsttp!=tp)
	{
		int x=sta[tp].fi,y=sta[tp].se;
		ans-=s[y].fi*s[y].se;
		s[y].fi-=s[x].fi,s[y].se-=s[x].se;
		ans+=s[x].fi*s[x].se+s[y].fi*s[y].se;
		h[y]-=h[x];
		fa[x]=x;
		tp--;
	}
}
signed main()
{
	q=read();
	for (int i=1;i<=q;i++)
	{
		a[i]=read(),b[i]=read();
		g.push_back(a[i]);g.push_back(b[i]);
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	for (int i=1;i<=q;i++)
	{
		a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+1;
		b[i]=lower_bound(g.begin(),g.end(),b[i])-g.begin()+1;
		Mp[{a[i],b[i]}].push_back(i);
	}
	for (auto u:Mp)
	{
		int ls=1,t=1;
		for (auto v:u.se)
		{
			if (!t)
			{
				if (ls<v)
				{
					update(1,1,q,ls,v-1,v);
				}
			}
			t^=1;
			ls=v;
		}
		if (ls<=q)
		{
			if (!t)
			update(1,1,q,ls,q,*(--u.se.end()));
		}
	}
	for (int i=1;i<=3e5;i++)
		fa[id(i,0)]=id(i,0),s[id(i,0)]={1,0},h[id(i,0)]=1,
		fa[id(i,1)]=id(i,1),s[id(i,1)]={0,1},h[id(i,1)]=1;
	slove(1,1,q);
}
/*

*/