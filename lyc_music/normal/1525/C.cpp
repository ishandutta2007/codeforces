//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m;
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		set<pa>S;vector<int>g[2];
		vector<int>a(n+1),c(n+1);
		vector<char>b(n+1);
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			g[a[i]%2].push_back(i);
		}
		for (int i=1;i<=n;i++)
			cin>>b[i];
		for (int now=0;now<=1;now++)
		{
			sort(g[now].begin(),g[now].end(),[&](int x,int y){return a[x]<a[y];});
			for (int i=g[now].size()-1;i>=0;i--)
			{
				if (b[g[now][i]]=='R') 
				{
					if (!S.empty())
					{
						pa u=(*S.begin());
						S.erase(S.begin());
						c[u.se]=c[g[now][i]]=(u.fi-a[g[now][i]])/2;
					} else
						S.insert({(m+(m-a[g[now][i]])),g[now][i]});
				} else	S.insert({a[g[now][i]],g[now][i]});
			}
			while (S.size()>=2)
			{
				pa u=*S.begin();
				S.erase(S.begin());
				pa v=*S.begin();
				S.erase(S.begin());
				c[u.se]=c[v.se]=(u.fi+v.fi)/2;
			}
			if (!S.empty())
			{
				pa u=*S.begin();
				c[u.se]=-1;
				S.erase(S.begin());
			}
		}
		for (int i=1;i<=n;i++) cout<<c[i]<<" ";
		cout<<'\n';
	}
}
/*

*/