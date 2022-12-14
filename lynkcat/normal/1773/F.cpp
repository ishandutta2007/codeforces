// Lynkcat.
// Problem: F. Hossam and Range Minimum Query
// Contest: Codeforces - Codeforces Round #837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/F
// Memory Limit: 256 MB
// Time Limit: 1500 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 200005
using namespace std;
mt19937_64 rnd(time(0));
unsigned long long  tr[N*60];
int rson[N*60],lson[N*60];
int n,q;
int a[N];
int rt[N];
unsigned long long  A[N];
int tot,pp;
map<int,int>Mp;
int val(int x)
{
	if (Mp.count(x)) return Mp[x];
	Mp[x]=rnd();
	return Mp[x];
}
void pushup(int k)
{
	tr[k]=tr[lson[k]]^tr[rson[k]];
}
void update(int &k,int rt,int l,int r,int L,unsigned long long  x)
{
	k=++tot;
	tr[k]=tr[rt];
	lson[k]=lson[rt];
	rson[k]=rson[rt];
	if (l==r)
	{
		tr[k]^=x;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(lson[k],lson[rt],l,mid,L,x);
	else update(rson[k],rson[rt],mid+1,r,L,x);
	pushup(k);
}
int query(int k,int lst,int l,int r)
{
	// cout<<"?"<<k<<" "<<lst<<" "<<tr[k]<<" "<<tr[lst]<<" "<<l<<" "<<r<<" "<<'\n';
	if (tr[k]==tr[lst]) return r;
	if (l==r) return l-1;
	int mid=l+(r-l)/2;
	int res=query(lson[k],lson[lst],l,mid);
	if (res==mid) res=max(res,query(rson[k],rson[lst],mid+1,r));
	// cout<<k<<" "<<lst<<" "<<l<<" "<<r<<" "<<res<<" "<<tr[k]<<'\n';
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		A[i]=val(a[i]);
		rt[i]=rt[i-1];
		update(rt[i],rt[i],1,1000000000,a[i],A[i]);
		// cout<<i<<" "<<rt[i]<<'\n';
	}
	cin>>q;
	int ans=0;
	while (q--)
	{
		int l,r;
		cin>>l>>r;
		l^=ans,r^=ans;
		// cout<<"?"<<l<<" "<<r<<'\n';
		int v=query(rt[r],rt[l-1],1,1000000000);
		if (v==1000000000) v=0;
		else v++;
		ans=v;
		cout<<ans<<'\n';
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}