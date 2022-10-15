//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=Next[i])
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
#define inf 10000000000000005
//#define mod 1000000007
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll a){if(a<0){a=-a; putchar('-');}write(a); putchar(' ');}
inline void writeln(ll a){if(a<0){a=-a; putchar('-');}write(a); puts("");}
int n,c[4][N],dp[2][N][4][4],f[N],x,y,z,ans,du[N],root,Last,depp[N];
vector<int>G[N];
void dfs(int k,int fa,int dep)
{
	f[k]=fa;depp[k]=dep;
	if (dep==2)
	{
		for (int i=1;i<=3;i++)
		  for (int j=1;j<=3;j++)
		  	if (i!=j)
		    dp[dep&1][dep&1^1][i][j]=c[i][f[k]]+c[j][k];
	} else
	{
		for (int i=1;i<=3;i++)
		  for (int j=1;j<=3;j++)
		  	if (i!=j)
		    	dp[dep&1][dep&1^1][i][j]=dp[dep&1^1][dep&1][1^2^3^i^j][i]+c[j][k];
	}
	for (int i=0;i<G[k].size();i++)
	  if (G[k][i]!=fa)
	  	dfs(G[k][i],k,dep+1);
}	
signed main()
{
	n=read();ans=inf;
	for (int i=1;i<=3;i++)
	  for (int j=1;j<=n;j++) 
		c[i][j]=read();
	for (int i=1;i<n;i++)
	{
		x=read(),y=read();
		du[x]++,du[y]++;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++) 
	{
		if (du[i]==1) root=i;
		if (du[i]>2) return puts("-1"),0;
	}
	for (int i=1;i<=n;i++) if (du[i]==1&&i!=root) Last=i;
	dfs(root,0,1);
	for (int i=1;i<=3;i++)
	  for (int j=1;j<=3;j++)
	    if (i!=j)
	    {
	    	if (dp[n&1][n&1^1][i][j]<ans)
	    	{
	    		ans=dp[n&1][n&1^1][i][j];
	    		x=i,y=j;
	    	}
	    }
	z=1^2^3^x^y;
	writeln(ans);
	for (int i=1;i<=n;i++)
	{
		if (depp[i]%3==(n-1)%3) writesp(x); else
		if (depp[i]%3==(n)%3) writesp(y); else writesp(z);
	}
}