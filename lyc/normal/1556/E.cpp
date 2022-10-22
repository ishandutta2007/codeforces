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
#define N 100005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ST[N][25],ST1[N][25],s[N],a[N],b[N],n,q;
int query(int x,int y)
{
	int t=log2(y-x+1);
	return min(ST[x][t],ST[y-(1<<t)+1][t]);
}
int query1(int x,int y)
{
	int t=log2(y-x+1);
	return max(ST1[x][t],ST1[y-(1<<t)+1][t]);
}
signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++)
	{
		s[i]+=b[i]-a[i];
		s[i]+=s[i-1];
		ST[i][0]=s[i];
		ST1[i][0]=s[i];
	}
	for (int j=1;j<=20;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
		{
//			cout<<i<<" "<<j<<endl;
			ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
			ST1[i][j]=max(ST1[i][j-1],ST1[i+(1<<(j-1))][j-1]);
		}
	while (q--)
	{
		int l=read(),r=read();
		int x=query(l,r)-s[l-1],y=query1(l,r)-s[l-1];
		if (x<0||s[l-1]!=s[r]) puts("-1");
		else writeln(y);
	}
}
/*

*/