// Author: Little09
// Problem: C2. Good Subarrays (Hard Version)
// Contest: Codeforces - Codeforces Round #825 (Div. 2)
// URL: https://codeforces.com/contest/1736/problem/C2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) ((x)&(-(x)))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],d[N],f[N];
ll c[N],s[N];

struct point
{
	int x,y,id;
}q[N];
bool cmp(point x,point y)
{
	return x.x>y.x;
}

ll sum[N*4],add[N*4];
inline void push_up(int u)
{
	sum[u]=sum[u*2]+sum[u*2+1];
}
inline void push_down(int u,ll len)
{
	if (add[u]!=-1)
	{
		sum[u*2]+=(len+1)/2*add[u];
		sum[u*2+1]=(len)/2*add[u];
		add[u*2]=add[u];
		add[u*2+1]=add[u];
		add[u]=-1;
	}
}
void build(int u,int l,int r)
{
	add[u]=-1;
	if (l==r)
	{
		sum[u]=n+1;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	push_up(u);
}
ll ask(int u,int L,int R,int l,int r)
{
	if (l>r) return 0;
	if (l<=L&&R<=r) return sum[u];
	int mid=(L+R)>>1;
	push_down(u,R-L+1);
	ll res=0;
	if (l<=mid) res+=ask(u*2,L,mid,l,r);
	if (mid<r) res+=ask(u*2+1,mid+1,R,l,r);
	return res;
}
void change(int u,int L,int R,int l,int r,ll k)
{
	if (l<=L&&R<=r) 
	{
		sum[u]=(R-L+1)*k;
		add[u]=k;
		return;
	}
	int mid=(L+R)>>1;
	push_down(u,R-L+1);
	if (l<=mid) change(u*2,L,mid,l,r,k);
	if (mid<r) change(u*2+1,mid+1,R,l,r,k);
	push_up(u);
}

void adde(int x)
{
	int y=a[x];
	if (y<1) return;
	change(1,1,n,1,y,x);
}
ll ANS[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) a[i]=i-a[i];
	for (int i=1;i<=n;i++) d[i]=max(d[i-1],a[i]);
	ll ans=-1ll*n*(n+1)/2;
	ll u=1;
	for (int i=1;i<=n;i++)
	{
		while (u<=n&&a[u]<i) u++;
		b[i]=u,c[u]+=u,s[u]+=u,f[u]=i;
	}
	a[n+1]=n;
	for (int i=1;i<=n+1;i++) c[i]+=c[i-1];
	for (int i=n;i>=1;i--) s[i]+=s[i+1];
	cin >> m;
	for (int i=1;i<=m;i++) 
	{
		q[i].id=i;
		cin >> q[i].x >> q[i].y;
	}
	sort(q+1,q+m+1,cmp);
	int uu=n+1;
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int x=q[i].x,y=q[i].y;
		cin >> x >> y;
		y=x-y;
		while (x<uu) adde(uu--);
		ll res=ans+c[x-1];
		//cout << res << endl;
		int p=max(d[x-1],y);
		if (y>d[x-1]) res+=1ll*x*(y-d[x-1]);
		//cout << p << endl;
		res+=ask(1,1,n,p+1,n);
		//cout << res << endl;
		ANS[q[i].id]=res;
	}
	for (int i=1;i<=m;i++) cout << ANS[i] << endl;
	return 0;
}