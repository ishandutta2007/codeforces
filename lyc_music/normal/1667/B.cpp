//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],s[N],tr[N],tr1[N];
int dp[N];
void upd(int x,int y)
{
	assert(x!=0);
	while (x<=n+1)
	{
		tr[x]=max(tr[x],y);
		x+=x&-x;
	}
}
void upd1(int x,int y)
{
	assert(x!=0);
	while (x<=n+1)
	{
		tr1[x]=max(tr1[x],y);
		x+=x&-x;
	}
}
int query(int x)
{
	// assert(x>=0);
	int res=-inf;
	while (x)
	{
		res=max(res,tr[x]);
		x-=x&-x;
	}
	return res;
}
int query1(int x)
{
	// assert(x>=0);
	int res=-inf;
	while (x)
	{
		res=max(res,tr1[x]);
		x-=x&-x;
	}
	return res;
}	

void BellaKira()
{
	poly G;
	map<int,int>Mp;
	n=read();
	s[0]=0;
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i],G.push_back(s[i]);
	G.push_back(0);
	sort(G.begin(),G.end());
	for (int i=1;i<=n+1;i++) tr[i]=-inf,tr1[i]=-inf;
	for (int i=0;i<=n;i++) 
	{
		s[i]=lower_bound(G.begin(),G.end(),s[i])-G.begin()+1;
	}
	Mp[s[0]]=0;
	// cout<<"?!"<<s[0]<<" "<<n+1<<" "<<G.size()<<" "<<endl;
	upd(s[0],0);
	upd1(n+1-s[0]+1,0);
	for (int i=1;i<=n;i++)
	{
		// cout<<i<<" "<<s[i]<<endl;
		int x=query(s[i]-1);
		dp[i]=x+i;
		if (Mp.count(s[i])) dp[i]=max(Mp[s[i]],dp[i]);
		x=query1(n+1-s[i]+1-1);
		dp[i]=max(dp[i],x-i);
		upd(s[i],dp[i]-i);
		Mp[s[i]]=dp[i];
		upd1(n+1-s[i]+1,dp[i]+i);
	}
	writeln(dp[n]);
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/