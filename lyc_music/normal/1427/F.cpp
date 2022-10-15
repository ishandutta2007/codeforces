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
#define inf 1000000005
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,b[N],fa[N],sta[N],id[N],tp,col[N],ID,vis[N],du[N],gen;
pair<int,pa>ans[N];

signed main()
{
	n=read();
	for (int i=1;i<=3*n;i++) b[read()]=1;
	for (int i=1;i<=6*n;i++) if (!b[i]) b[i]=2;
	n=6*n;
	for (int i=1;i<=n;i++)
	{
		if (tp>=2)
		{
			if (b[i]==b[sta[tp]]&&b[sta[tp]]==b[sta[tp-1]])
			{
				ans[id[sta[tp]]]={sta[tp-1],{sta[tp],i}};
				if (tp!=2)
				{
					fa[id[sta[tp]]]=id[sta[tp-2]];
				}
				col[id[sta[tp]]]=b[i];
				tp-=2;
				continue;
			} 
		}
		tp++;
		sta[tp]=i;
		if (b[i]!=b[sta[tp-1]]) id[i]=++ID;
		else id[i]=id[sta[tp-1]];
	}
//	if (n==900) cout<<ID<<endl;
	n/=3;
	for (int i=1;i<=n;i++) du[fa[i]]++;
	for (int i=1;i<=n;i++)
		if (col[i]==2&&fa[i]==0) gen++;
//	puts("");
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=1;j<=n;j++)
			if (col[j]==((i-1)%2+1)&&!vis[j]&&du[j]==0)
			{
				if (i<n&&col[j]==2&&fa[j]==0&&gen==1) continue;
				now=j;
				break;
			}
		writesp(ans[now].fi),writesp(ans[now].se.fi),writeln(ans[now].se.se);
		vis[now]=1;
		du[fa[now]]--;
		if (col[now]==2&&fa[now]==0) gen--;
	}
}
/*

*/