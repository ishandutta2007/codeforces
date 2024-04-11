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
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,T,m,a[N],b[N];
int L[N],R[N];
int nowsum;
vector<pa>G[N];
deque<int>q;
int tp;
int s[N],s1[N],s2[N],s3[N];
int ans[N];
int Q;
signed main()
{
	n=read(),Q=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		while (!q.empty()&&a[q.back()]>=a[i]) q.pop_back();
		q.push_back(i);
	}
	b[m]=a[q.front()];
	for (int i=m+1;i<=n;i++)
	{
		while (!q.empty()&&a[q.back()]>=a[i]) q.pop_back();
		q.push_back(i);
		while (q.front()<i-m) q.pop_front();
		b[i]=a[q.front()];
//		cout<<i<<","<<b[i]<<endl;
	}
	for (int i=1;i<=Q;i++)
	{
		L[i]=read(),R[i]=read();
		if (L[i]+m<=R[i]) G[L[i]+m].push_back({i,R[i]});
		ans[i]=a[L[i]];
	}
	for (int i=0;i<m;i++)
	{
		vector<int>g,g1;
		for (int j=i+m;j<=n;j+=m)
			g.push_back(j);
		g1=g;
		reverse(g.begin(),g.end());
		tp=1;
		s2[tp]=1,s1[tp]=1,s3[tp]=inf,s[tp]=inf;
		for (auto u:g)
		{
			int x=1;
			while (tp&&s[tp]>=b[u])
			{
				x+=s1[tp];
				tp--;
			}
			++tp;
			s2[tp]=s2[tp-1]+x;
			s1[tp]=x;
			s3[tp]=s3[tp-1]+x*b[u];
			s[tp]=b[u];
//			for (int j=1;j<=tp;j++) cout<<u<<" "<<s[j]<<" "<<s1[j]<<" "<<s2[j]<<" "<<s3[j]<<endl;
			for (auto v:G[u])
			{
				int vx=v.fi,vy=v.se;
				int y=0;
				if (vy>=g[0]) y=g.size();
				else
				{
					y=(vy/m);
					if (g1[y-1]>vy) y--;
				}
				int l=1,r=tp,nowans=0,gsize=g.size()+1;
				while (l<=r)
				{
					int mid=l+(r-l)/2;
					if (s2[mid]>gsize-y)
					{
						nowans=s3[mid]-s[mid]*(s2[mid]-gsize+y);
//						cout<<"???"<<mid<<" "<<s3[mid]-s[mid]*(s2[mid]-gsize+y)<<endl;
						r=mid-1;
					}
					else l=mid+1;
				}
//				cout<<vx<<"?"<<s3[tp]<<" "<<nowans<<" "<<y<<" "<<gsize<<" "<<g[0]<<endl;
				ans[vx]+=s3[tp]-nowans;
			}
		}
	}
	for (int i=1;i<=Q;i++) writeln(ans[i]);	
}
/*

*/