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
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int Tt,n,m,a[305][305],c[305][100005],b[305][305],A[305][305];
vector<int>G[100005];
pa S[100005],T[100005];
void update(int i,int x,int y)
{
	if (x==0) return;
	while (x<=n*m) 
	{
	c[i][x]+=y,x+=(x&(-x));
	}
}
int query(int i,int x)
{
	int res=0;
	while (x>0)
	{
		res+=c[i][x];
		x-=(x&(-x));
	}
	return res;
}
signed main()
{
	Tt=read();
	while (Tt--)
	{
		n=read(),m=read();
		int ans=0;
		vector<int>g;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) a[i][j]=read(),g.push_back(a[i][j]);
		sort(g.begin(),g.end());
		vector<pa>g1;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=lower_bound(g.begin(),g.end(),a[i][j])-g.begin()+1,g1.push_back({a[i][j],((i-1)*m+j)}),G[a[i][j]].push_back((i-1)*m+j);
//	writeln(g1.size());
		sort(g1.begin(),g1.end());
		int tot=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
//				g1[tot].se=-g1[tot].se;
				b[i][j]=g1[tot].fi;
				if (!S[g1[tot].fi].fi) S[g1[tot].fi]={i,j};
				T[g1[tot].fi]={i,j};
				tot++;
			}
		}
		for (int i=1;i<=n*m;i++)
			if (S[i].fi)
			{
				reverse(G[i].begin(),G[i].end());
				int now=0;
				if (S[i].fi==T[i].fi)
				{
					for (int j=S[i].se;j<=T[i].se;j++)
					{
						A[S[i].fi][j]=G[i][now],now++;
					}
				} else
				{
					for (int j=1;j<=T[i].se;j++)
						A[T[i].fi][j]=G[i][now],now++;
					for (int j=S[i].fi+1;j<=T[i].fi-1;j++)
						now+=m;
					for (int j=S[i].se;j<=m;j++)
						A[S[i].fi][j]=G[i][now],now++;
				}
				S[i]=T[i]={0,0};
				G[i].clear();
			}	
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
//				cout<<i<<" "<<j<<" "<<A[i][j]<<endl; 
				if (!A[i][j]) continue;
				ans+=query(i,A[i][j]);
				update(i,A[i][j],1);
			}
//		cout<<"!"<<endl;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) update(i,A[i][j],-1),A[i][j]=0;
		writeln(ans);
				
	}
			
}
/*

*/