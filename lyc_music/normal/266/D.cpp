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
#define int ll
#define N 505
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N][N];
vector<int>G[N];
int sta[N];
int c[N],d[N],e[N];
int n,m;
double ans;
struct node
{
	int u,v;
	double w;
}E[N*N];
inline double calc(double x,double y,double xx,double yy,double k)
{
	double X=(x+y+k)*1.0/2;
	x=(X+(X-x));
	return (x+xx)*1.0/2;
}
signed main()
{
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	ans=f[0][0];
	bool bl=1;
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		if (u>v) swap(u,v);
		bl&=(w==2);
		f[u][v]=f[v][u]=min(f[u][v],w);
		E[i]={u,v,w};
		G[u].push_back(i);
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			if (i!=k)
				for (int j=1;j<=n;j++)
					if (i!=j&&j!=k)
						f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	for (int i=1;i<=n;i++)
	{
		if (G[i].size()==0) continue;
		vector<pa>g;
		for (int j=1;j<=n;j++)
			g.push_back({f[j][i],j});
		sort(g.begin(),g.end());
		for (int j=1;j<=n;j++)
			c[g[j-1].se]=j,d[j]=g[j-1].fi;
		for (auto u:G[i])
		{
			re int tp=0;
			for (int j=1;j<=n;j++) 
				e[c[j]]=f[j][E[u].v];
			for (int j=1;j<=n;j++)
			{
				while (tp&&e[sta[tp]]<=e[j]) tp--;
				sta[++tp]=j;
			}
//			cout<<"!"<<u<<endl;
//			for (int j=1;j<=tp;j++) cout<<d[sta[j]]<<" "<<e[sta[j]]<<" "<<E[u].w<<endl;
//			cout<<endl;
			for (int j=2;j<=tp;j++)
			{
				ans=min(ans,calc(e[sta[j-1]],d[sta[j-1]],e[sta[j]],d[sta[j]],E[u].w));
			}
			ans=min(ans,e[sta[1]]*1.0);
			ans=min(ans,d[sta[tp]]*1.0);
		}
	}
//	cout<<calc(1,0,0,1,1)<<endl;
	printf("%.10f",ans);
			
}
/*

*/