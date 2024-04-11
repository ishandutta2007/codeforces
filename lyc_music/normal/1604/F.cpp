//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define mod 998244353
//#define int ll
#define N 100005
#define B 320
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
ll s[N][B+5],s1[N][B+5];
ll P[N];
ll phi[N],vis[N];
int cnt;
int pr[N];
ll f[25][N];
int n,m;
inline ll c(int x,int y)
{
	if (x>y) return 0;
	ll l=y/x,r=y/l+1;
	if (y/r==0) return 1ll*(r-x)*P[l];
	if (y/r<=B) 
		return s[y][y/r]+1ll*(r-x)*P[l];
	return (s1[y][y/(y/r)]+1ll*(r-x)*P[l]);
}
void solve(int k,int l,int r,int L,int R)
{
	if (l>r) return;
	int now=L,mid=l+(r-l)/2;
	for (int i=L;i<=min(R,mid-1);i++)
		if (f[k-1][now]+c(now+1,mid)>=f[k-1][i]+c(i+1,mid))
		{
			now=i;
		}
	f[k][mid]=f[k-1][now]+c(now+1,mid);
//	if (k<=5) cout<<"?"<<k<<" "<<now+1<<"?"<<mid<<" "<<c(now+1,mid)<<endl;
	solve(k,l,mid-1,L,now);
	solve(k,mid+1,r,now,R);
}
inline void init()
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			pr[++cnt]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=cnt&&i*pr[j]<=n;j++)
		{
//			cout<<i<<","<<pr[j]<<endl;
			vis[i*pr[j]]=1;
			if (i%pr[j]==0)
			{
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			} else phi[i*pr[j]]=phi[i]*(pr[j]-1);
		}
	}
	for (int i=1;i<=n;i++) P[i]=P[i-1]+phi[i];
	for (int i=1;i<=n;i++)
	{
		vector<pa>g;
		for (int l=1,r;l<=i;)
		{
			r=(i/(i/l));
			g.push_back({i/l,r-l+1});
			l=r+1;
		}
		int siz=g.size();
		for (int j=siz-1;j>=0;j--)
		{
			if (g[j].fi<=B) 
			{
				s[i][g[j].fi]=1ll*P[g[j].fi]*g[j].se;
				if (j!=siz-1) 
				{
					if (g[j+1].fi<=B) s[i][g[j].fi]+=s[i][g[j+1].fi];
					else s[i][g[j].fi]+=s1[i][i/g[j+1].fi];
				}
			} else
			{
				s1[i][i/g[j].fi]=1ll*P[g[j].fi]*g[j].se;
				if (j!=siz-1) 
				{
					if (g[j+1].fi<=B) s1[i][i/g[j].fi]+=s[i][g[j+1].fi];
					else s1[i][i/g[j].fi]+=s1[i][i/g[j+1].fi];
				}
			}
		}
	}
//	return;
	memset(f[0],0x3f,sizeof(f[0]));
	f[0][0]=0;
	for (int i=1;i<=m;i++)
	{
//		memset(f[i],0x3f,sizeof(f[i]));
		solve(i,0,n,0,n-1);
	}
}
inline void LYC()
{
	n=read(),m=read();
	if (m>18) writeln(n);
	else  writeln(f[m][n]);
}
signed main()
{
//	freopen("1.txt","r",stdin);
	m=18,n=100000;
	init();
	int T=read();
	while (T--)
	{
		LYC();
	}
}
/*
1
99982 10
*/