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
int T,c[N],b[N];
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>st;
		int n=st.length();
		st=' '+st;int ans=0;
		for (int i=1;i<=n;i++)
		{
			if (st[i]==st[i-1]&&st[i]=='1') b[i]=1;else b[i]=0;
			if (st[i]==st[i-1]&&st[i]=='0') c[i]=1;else c[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			b[i]+=b[i-1];
			c[i]+=c[i-1];
		}
		for (int i=1;i<=n;i++)
		{
//			cout<<c[n]-c[i]<<endl;
			if (b[i]==0&&c[n]-c[i]==0) ans=1;
		}
		if (!ans) puts("NO");else puts("YES");
	}
			
			
}
/*

*/