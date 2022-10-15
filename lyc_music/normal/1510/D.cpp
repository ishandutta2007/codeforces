//The Hunting Party - Keys To The Kingdom
//~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
double f[N][15];
int lst[N][15];
int n,d,a[N];
void What_will_Diana_eat_today()
{
	n=read(),d=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<=9;i++) for (int j=0;j<=n;j++) f[j][i]=-inf;
	f[0][1]=log2(1);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=9;j++)
		{
//			if (f[i-1][j]<0) continue;
			if (f[i][j*a[i]%10]<f[i-1][j]+log2(a[i]))
			{
				lst[i][j*a[i]%10]=j;
				f[i][j*a[i]%10]=f[i-1][j]+log2(a[i]);
			}
			if (f[i][j]<f[i-1][j])
			{
				lst[i][j]=10;
				f[i][j]=f[i-1][j];
			}
		}
	if (f[n][d]<0) puts("-1");
	else
	{
		vector<int>g;
		for (int i=n;i>=1;i--)
		{
//			cout<<"?"<<f[n][d]<<" "<<lst[i][d]<<endl;
			if (lst[i][d]!=10)
			{
				g.push_back(a[i]);
				d=lst[i][d];
			}
		}
		reverse(g.begin(),g.end());
		if (g.size()==0) 
		{
			puts("-1");
			return;
		}
		writeln(g.size());
		for (auto u:g) writesp(u);
		puts("");
	}
	
}
signed main()
{
	int T=1;
	while (T--)
	{
	 	  What_will_Diana_eat_today();
	}
}
/*

*/