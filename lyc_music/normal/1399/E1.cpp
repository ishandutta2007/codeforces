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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,S,ans,ans1,lev[N],b[N],ls[4000005],rs[4000005];
pa a[N];
vector<pa>G[N];
priority_queue<pair<double,int> >q,q1;
void dfs(int k,int fa)
{
	int tp=0;
	for (auto U:G[k])
	{
		int u=U.fi,id=U.se;
		if (u==fa) continue;
		dfs(u,k);tp++;
		lev[k]+=lev[u];
		b[id]=lev[u];
	}
	if (!tp) lev[k]=1;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read(),S=read();ans1=0;ans=0;
		int tot=0;
		for (int i=1;i<n;i++)
		{
			int x=read(),y=read();
			a[i].fi=read(),a[i].se=1;
			b[i]=0;
			G[x].push_back({y,i});
			G[y].push_back({x,i});
		}
		dfs(1,0);
		for (int i=1;i<n;i++)
			ans+=b[i]*a[i].fi;
		for (int u=1;u<n;u++)	
			if (a[u].fi!=0&&a[u].se==1) q.push({(a[u].fi-(a[u].fi/2))*b[u]*1.0/a[u].se,u});
//		writeln(ans);
		while (!q.empty())
		{
			int u=q.top().se;
			q.pop();
//			if (ans<=S) break;
//			ans-=(a[u].fi-(a[u].fi/2))*b[u];
			ans1++;
			ls[ans1]=ls[ans1-1]+(a[u].fi-(a[u].fi/2))*b[u];
			a[u].fi/=2;
			if (a[u].fi>0)
			{
				q.push({(a[u].fi-(a[u].fi/2))*b[u]*1.0/a[u].se,u});
			}
		}
		while (!q.empty()) q.pop();
		for (int u=1;u<n;u++)	
			if (a[u].fi!=0&&a[u].se==2) q.push({(a[u].fi-(a[u].fi/2))*b[u]*1.0,u});
		tot=ans1;
		ans1=0;
		while (!q.empty())
		{
			int u=q.top().se;
			q.pop();
//			if (ans<=S) break;
//			ans-=(a[u].fi-(a[u].fi/2))*b[u];
			ans1++;
			rs[ans1]=rs[ans1-1]+(a[u].fi-(a[u].fi/2))*b[u];
			a[u].fi/=2;
			if (a[u].fi>0)
			{
				q.push({(a[u].fi-(a[u].fi/2))*b[u]*1.0,u});
			}
		}
		while (!q.empty()) q.pop();
		int nowans=inf,rrr=ans1;
		for (int i=0;i<=tot;i++)
		{
			while (ans-rs[rrr-1]-ls[i]<=S&&rrr>=1) rrr--;
			if (ans-rs[rrr]-ls[i]<=S) nowans=min(nowans,i+rrr*2);
		}
		writeln(nowans);
		for (int i=1;i<=n;i++) G[i].clear(),lev[i]=0;
	}
}
/*

*/