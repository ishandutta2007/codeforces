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
#define N 1005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int s[N][N][5],vis[N][N][5],ans,b[N],c[N];
int n,m;
string st,st1;
int work(int x,int y,int ls)
{
	if (vis[x][y][ls]) return s[x][y][ls];
	vis[x][y][ls]=1;
	s[x][y][ls]=1;
	char ch=' ';
	if (ls==0) ch=st[x-1];
	else if (ls==1) ch=st1[y-1];
	if (x+1<=n)
	{
		if (st[x]!=ch) s[x][y][ls]+=work(x+1,y,0),s[x][y][ls]%=mod;
	}
	if (y+1<=m)
	{
		if (st1[y]!=ch)
			s[x][y][ls]+=work(x,y+1,1),s[x][y][ls]%=mod;
	}
//	cout<<x<<" "<<y<<" "<<ls<<" "<<s[x][y][ls]<<" "<<st[x]<<" "<<st1[y]<<" "<<" "<<endl;
	return s[x][y][ls];
}
signed main()
{
	cin>>st>>st1;
	n=st.length(),m=st1.length();
	st=st+'8';st1=st1+'4';
//	work(0,0,i,j);
//	writeln(work(n-2,m-2,2));
	for (int i=0;i<=n;i++)
	{
		b[i]=1;
		for (int j=i+1;j<=n;j++)
		{	
			b[i]++;
			if (st[j]==st[j-1]) break;
		}
	}
	for (int i=0;i<=m;i++)
	{
		c[i]=1;
		for (int j=i+1;j<=m;j++)
		{	
			c[i]++;
			if (st1[j]==st1[j-1]) break;
		}
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			ans=(ans+work(i,j,2))%mod;
//			cout<<i<<" "<<j<<" "<<ans<<" "<<b[i]<<" "<<c[j]<<endl;
//			if (i==0) 
			ans=(ans-c[j]+mod)%mod;
//			if (j==0) 
			ans=(ans-b[i]+mod)%mod;
			ans=(ans+1)%mod;
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
//	for (int i=0;i<n;i++)
//	cout<<work(n-1,m,1)<<endl;
	writeln(ans);
}
/*
code
forces
*/