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
int vis[N],col[N],a[N],b[N];
int T,n;
int tot;
signed main()
{
	vis[1]=1;
	for (int i=2;i<=1000;i++)
	{
		if (!vis[i])
		{
			b[i]=++tot;
			for (int j=i*2;j<=1000;j+=i)
				vis[j]=1;
		}
	}
	for (int i=3;i<=1000;i++)
		for (int j=2;j<i;j++)
			if (i%j==0)
			{
				for (int k=2;k<=j;k++)
					if (!vis[k]&&(j%k==0))
						col[i]=k;
				break;
			}
//	cout<<col[3]<<endl;
	T=read();
	while (T--)
	{
		vector<int>g;
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			g.push_back(col[a[i]]);
//			cout<<col[a[i]]<<endl;
		}
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		writeln(g.size());
		for (int i=1;i<=n;i++) writesp(lower_bound(g.begin(),g.end(),col[a[i]])-g.begin()+1);
		puts("");
	}
}
/*

*/