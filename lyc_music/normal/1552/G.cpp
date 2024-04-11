//QwQcOrZ yyds!!!
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define bp()  __builtin_popcount()
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
#define N 105
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,x,Ans;
ll now,h[N];
vector<ll>ans,ans1;
vector<int>G[N];
signed main()
{
	n=read(),m=read();
	if (n==1) return puts("ACCEPTED"),0;
	Ans=1;
	for (int i=1;i<=m;i++)
	{
		x=read();
		while (x--) G[i].push_back(read()-1);
	}
	ans.push_back(0);
	now=0;
	for (int i=1;i<=m;i++)
	{
		ll stat=0;
	    for (auto x:G[i]) stat|=1ll<<x;
	    vector<int>p;
	    p=G[i];
	    if (p.size()==0) continue;
	    reverse(p.begin(),p.end());
	    h[0]=0;
	    for (int j=1;j<=p.size();j++) h[j]=h[j-1]|(1ll<<(p[j-1]));
	    ll y=(stat^(stat&now));
	    now|=stat;
	    ans1.clear();
	    for (auto v:ans)
	    {
		    for (int j=0;j<=__builtin_popcountll(y);j++)
		    {
				int cnt=j+__builtin_popcountll(v&stat);
				ans1.push_back((v&(((1ll<<n)-1)^stat))|h[cnt]);
		    }
	    }
	    swap(ans,ans1);
	}
	if (now!=(1ll<<n)-1)
					return puts("REJECTED"),0;
	for (auto u:ans)
	{
		int bl=0;
		for (int j=0;j<n;j++)
			if ((u>>j)%2) bl=1;
			else
			{
				if (bl) 
				{
					return puts("REJECTED"),0;
				}
			}
	}
	puts("ACCEPTED");
}
/*

*/