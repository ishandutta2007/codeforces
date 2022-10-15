//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N];
map<int,int>Mp;
int b[N];
vector<int>ans;
void work(int x)
{
	swap(a[x+2],a[x]);
	swap(a[x+1],a[x+2]);
	swap(b[x+2],b[x]);
	swap(b[x+1],b[x+2]);
	ans.push_back(x);
}
signed main()
{
	T=read();
	while (T--)
	{
		vector<int>g;ans.clear();
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			g.push_back(a[i]);
		}
		sort(g.begin(),g.end());
		for (int i=1;i<=n;i++)
		{
			Mp[a[i]]++;
			b[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+Mp[a[i]];
		}
		for (int i=n;i>=3;i--)
		{
			int x=0;
			for (int j=1;j<i;j++)
				if (a[j]==g[i-1]&&g[j-1]!=a[j])
				{
					x=j;
					break;
				}
			if (x==0) continue;
			while (x!=i)
			{
				if (x==i-1) 
				{
					work(i-2);
					x=i;
				} else
				{
					work(x);
					work(x);
					x=x+2;
				}
			}
		}
//		for (int i=1;i<=n;i++) writesp(a[i]);
//		puts("");
		if (a[1]>a[2])
		{
			work(1);
			if (a[1]<=a[2]&&a[2]<=a[3])
			{
				writeln(ans.size());
				for (auto u:ans)
				{
					writesp(u);
				}
				puts("");
			} else
			{
				work(1);
				if (a[1]<=a[2]&&a[2]<=a[3])
				{
					writeln(ans.size());
					for (auto u:ans)
					{
						writesp(u);
					}
					puts("");
				} else
				{
					work(1);
					int y=0;
					for (int i=3;i<n;i++)
						if (a[i]==a[i+1])
						{
							y=i;
							break;
						}
					if (!y) puts("-1");
					else
					{
//						cout<<"?"<<y<<endl;
						int i=y;
						for (int j=1;j<=i-3;j++) work(j);
						work(i-2);
						work(i-2);
						work(i-1);
						work(i-1);
						for (int j=i-3;j>=1;j--) work(j),work(j);
						writeln(ans.size());
						for (auto u:ans)
						{
							writesp(u);
						}		
						puts("");
//						for (int j=1;j<=n;j++) writesp(a[j]);
//						puts("");
					}
				}		
			}
		} else
		{
			writeln(ans.size());
			for (auto u:ans)
			{
				writesp(u);
			}
			puts("");
		}
		Mp.clear();
	}
}
/*
1
4
2 1 3 3
*/