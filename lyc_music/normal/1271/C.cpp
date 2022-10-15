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
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,X,Y,x[N],y[N];
vector<int>G[4],G1[4];
signed main()
{
	n=read(),X=read(),Y=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		if (x[i]<X) G[0].push_back(i);
		else 
			if (x[i]>X) G[1].push_back(i);
		else G[2].push_back(i);
		if (y[i]<Y) G1[0].push_back(i);
		else 
			if (y[i]>Y) G1[1].push_back(i);
		else G1[2].push_back(i);
	}
	int nowmx=0,nowx=0,nowy=0;
	if (G[0].size()>nowmx) 
	{
		nowx=X-1,nowy=Y;
		nowmx=G[0].size();
	}
	if (G[1].size()>nowmx) 
	{
		nowx=X+1,nowy=Y;
		nowmx=G[1].size();
	}
	if (G1[0].size()>nowmx) 
	{
		nowx=X,nowy=Y-1;
		nowmx=G1[0].size();
	}
	if (G1[1].size()>nowmx) 
	{
		nowx=X,nowy=Y+1;
		nowmx=G1[1].size();
	}
	writeln(nowmx);
	writesp(nowx),writesp(nowy);
}
/*

*/