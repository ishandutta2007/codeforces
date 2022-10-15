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
#define N 205
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int len(int x,int y){return y-x+1;}
vector<vector<int> >ans;
int n,a[N],b[N];
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=1;
	while (1)
	{
		vector<int>g;
		int i=1;
		for (;i<=n;i++)
		{
//			cout<<i<<" "<<a[i]<<endl;
			if ((a[i+1]!=a[i]+1&&i!=n)||(i==n&&a[i]!=n))
			{
//				cout<<"!"<<i<<endl;
				int x=0;
				for (int j=1;j<i;j++)
				{
					if (a[j]==a[i]+1) x=j;
				}
//				cout<<i<<" "<<x<<endl;
				if (x==0) continue;
				int y=i;
				while (y>1&&a[y-1]==a[y]-1) y--;
				if (y==0) continue;
				if (x-1>0) g.push_back(x-1);
				if (len(x,y-1)>0) g.push_back(len(x,y-1));
				if (len(y,i)>0) g.push_back(len(y,i));
				if (len(i+1,n)>0) g.push_back(len(i+1,n));
//				cout<<i<<" "<<x<<","<<y<<" "<<len(4,4)<<endl;
				ans.push_back(g);
				int now=n;
				for (int j=x-1;j>=1;j--) b[now--]=a[j];
				for (int j=y-1;j>=x;j--) b[now--]=a[j];
				for (int j=i;j>=y;j--) b[now--]=a[j];
				for (int j=n;j>=i+1;j--) b[now--]=a[j];
				for (int j=1;j<=n;j++) a[j]=b[j];
				g.clear();
				break;
			}
		}
		if (i==n+1) break;
	}
	writeln(ans.size());
	for (auto u:ans)
	{
		writesp(u.size());
		for (auto v:u) writesp(v);
		puts("");
	}
}
/*

*/