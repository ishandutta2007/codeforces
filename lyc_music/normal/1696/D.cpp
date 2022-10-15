// Lynkcat.
// Problem: D. Permutation Graph
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/d
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
#define N 250005
using namespace std;
int n,tr[N<<2],tr1[N<<2];
int dis[N],a[N];

void pushup(int k)
{
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int L,int x)
{
	if (l==r)
	{
		tr[k]=x;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,x);
	else update(k<<1|1,mid+1,r,L,x);
	pushup(k);
}
int query(int k,int l,int r,int L,int R)
{
	if (L>R) return inf;
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	int res=inf;
	if (L<=mid) res=min(res,query(k<<1,l,mid,L,R));
	if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R));
	return res;
}


void pushup1(int k)
{
	tr1[k]=min(tr1[k<<1],tr1[k<<1|1]);
}
void update1(int k,int l,int r,int L,int x)
{
	if (l==r)
	{
		tr1[k]=x;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update1(k<<1,l,mid,L,x);
	else update1(k<<1|1,mid+1,r,L,x);
	pushup1(k);
}
int query1(int k,int l,int r,int L,int R)
{
	if (L>R) return inf;
	if (L<=l&&r<=R) return tr1[k];
	int mid=l+(r-l)/2;
	int res=inf;
	if (L<=mid) res=min(res,query1(k<<1,l,mid,L,R));
	if (R>mid) res=min(res,query1(k<<1|1,mid+1,r,L,R));
	return res;
}

void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	// cout<<tr[1]<<" "<<tr1[1]<<endl;
	dis[1]=0;
	update(1,1,n,1,0);
	update1(1,1,n,1,0);
	poly g,g1;
	g.push_back(1);
	g1.push_back(1);
	for (int i=2;i<=n;i++)
	{
		poly tg,tg1;
		while (g.size()&&a[i]>a[g.back()]) 
			tg.push_back(g.back()),g.pop_back();
		while (g1.size()&&a[i]<a[g1.back()]) 
			tg1.push_back(g1.back()),g1.pop_back();
		dis[i]=min(query1(1,1,n,(g.empty()?1:g.back()+1),i-1)+1,
		query(1,1,n,(g1.empty()?1:g1.back()+1),i-1)+1);
		for (auto u:tg) update(1,1,n,u,inf);
		for (auto u:tg1) update1(1,1,n,u,inf);
		update(1,1,n,i,dis[i]);
		update1(1,1,n,i,dis[i]);
		g.push_back(i);
		g1.push_back(i);
	}
	cout<<dis[n]<<endl;
	for (int i=1;i<=n;i++)
		update(1,1,n,i,inf),update1(1,1,n,i,inf);
		
}
signed main()
{
	memset(tr,0x3f,sizeof(tr));
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}