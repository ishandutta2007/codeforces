//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
#define N 55
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,m,q,a[N][N],b[N][N];
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>q;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			cin>>st;
			for (int j=0;j<m;j++) a[i][j+1]=(st[j]=='*');
		}
		for (int i=n;i>q;i--)
		{
			for (int j=1;j<=m;j++)
			{
				if (a[i][j])
				{
					int mxdp=0;
					for (int k=i-1;k>=1;k--)
					{
						if (j-(i-k)>=1&&a[k][j-(i-k)]) 
						{
							if (j+(i-k)<=m&&a[k][j+(i-k)]) mxdp=(i-k);
							else break;
						}
						else break;
					}
//					cout<<i<<" "<<j<<" "<<mxdp<<endl;
					if (mxdp>=q)
					{
						for (int k=i;k>=i-mxdp;k--)
						{
							b[k][j-(i-k)]=1;
							b[k][j+(i-k)]=1;
						}
					}
				}
			}
		}
		for (int i=n;i>=1;i--)
		{
			for (int j=1;j<=m;j++)
			{
				if (a[i][j]&&!b[i][j]) ans=1;
			}
		}
		if (ans) puts("NO");
		else puts("YES");
		memset(b,0,sizeof(b)),memset(a,0,sizeof(a));
	}
		
}
/*

*/