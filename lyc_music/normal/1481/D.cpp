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
string st[2005];
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		int ans=0;
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			cin>>st[i];
			st[i]=' '+st[i];
		}
		for (int i=1;i<=n;i++)
		{
			if (ans) break;
			for (int j=i+1;j<=n;j++)
				if (st[i][j]==st[j][i])
				{
//					puts("YES");
					cout<<"YES"<<endl;
					for (int k=1;k-1<=m;k++)
						if (k%2==1) cout<<i<<" ";
						else cout<<j<<" ";
					cout<<endl;
					ans=1;
					break;
				}
		}
		if (!ans)
		{
			if (m%2==1)
			{
					cout<<"YES"<<endl;
					for (int k=1;k-1<=m;k++)
						if (k%2==1) cout<<1<<" ";
						else cout<<2<<" ";
					cout<<endl;ans=1;
			}
			else 
			{
				for (int i=1;i<=n;i++)
				{
					vector<int>g[2];
					g[0].clear(),g[1].clear();
					for (int j=1;j<=n;j++)
					if (i!=j)
					{
						if (st[i][j]=='b')	
							g[0].push_back(j);
						else g[1].push_back(j);
					}
					if (g[0].size()==0||g[1].size()==0) continue;
					int x=g[0][0],y=g[1][0];
					if (m%4==0)
					{
						cout<<"YES"<<endl;
						cout<<i<<" ";
						for (int i1=1;i1<=m/4;i1++)
							cout<<x<<" "<<i<<" ";
						for (int i1=1;i1<=m/4;i1++)
							cout<<y<<" "<<i<<" ";
					cout<<endl;ans=1;break;
					} else
					{
						cout<<"YES"<<endl;
						cout<<x<<" ";
						for (int i1=1;i1<=m/2;i1++)
							if (i1%2==1) cout<<i<<" ";
							else cout<<x<<" ";
						for (int i1=1;i1<=m/2;i1++)
							if (i1%2==1) cout<<y<<" ";
							else cout<<i<<" ";
					cout<<endl;ans=1;break;
					}
				}
			}
			if (!ans) cout<<"NO"<<endl;
		}
	}
				
}
/*
1
2 1
*a
b*

*/