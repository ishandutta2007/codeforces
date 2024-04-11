//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
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
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,f[N][27],tot[N],ans;
string st;
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		cin>>st;
		st=' '+st;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=26;j++)
				f[i][j]=0;
			tot[i]=0;
		}
		for (int i=1;i<=n;i++)
			f[min(m-((i-1)%m+1)+1,((i-1)%m+1))][st[i]-'a'+1]++,
			tot[min(m-((i-1)%m+1)+1,((i-1)%m+1))]++;
		for (int i=1;i<=m/2+(m%2);i++)
		{
			int now=inf;
			for (int j=1;j<=26;j++)
				now=min(tot[i]-f[i][j],now);
			ans+=now;
		}
		writeln(ans);
	}
}
/*

*/