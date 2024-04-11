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
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n;
pa a[N];
int ans[N];
multiset<pa>S;
int p[N];
bool cmp(int x,int y)
{
	return a[x].fi<a[y].fi;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++)
		{
			int x=read(),y=read();
			if (x>y) swap(x,y);
			a[i]={x,y};
			p[i]=i;
		}
		sort(p+1,p+n+1,cmp);
		int l=1;
		a[n+1].se=114514;
		p[n+1]=n+1;
		for (int i=1;i<=n;i++)
		{
//			cout<<a[p[i]].fi<<" "<<S.size()<<endl;
			auto it=(S.lower_bound({a[p[i]].se,0}));
			if (it==S.begin())
			{
				ans[p[i]]=-1;
			} else
			{
				--it;
				ans[p[i]]=(*it).se;
//			cout<<"??"<<a[p[i+1]].fi<<endl;
			}
			if (a[p[i]].fi!=a[p[i+1]].fi)
			{
//				cout<<"?"<<endl;
				while (l!=i+1)
				{
					S.insert({a[p[l]].se,p[l]});
					l++;
				}
			}
		}
		for (int i=1;i<=n;i++)writesp(ans[i]);
		puts("");
		S.clear();
	}
}
/*

*/