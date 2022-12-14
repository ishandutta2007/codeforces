// Lynkcat.
// Problem: B. Find a Gift
// Contest: Codeforces - 10.11
// URL: https://codeforces.com/gym/403247/problem/B
// Memory Limit: 256 MB
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
#define inf 1e9
#define mod 998244353
#define int ll
// #define N 
using namespace std;
int n,m;
mt19937_64 rnd(time(0));
int query(poly x,poly y)
{
	cout<<"? "<<x.size()<<" "<<y.size()<<endl;
	for (auto u:x) cout<<u<<" ";
	cout<<endl;
	for (auto u:y) cout<<u<<" ";
	cout<<endl;
	string st;
	cin>>st;
	if (st=="FIRST") return 1;
	if (st=="SECOND") return 2;
	return 3;
}
bool cmp(int x,int y)
{
	poly gx,gy;
	gx.push_back(x);
	gy.push_back(y);
	if (query(gx,gy)==2) return 1;
	return 0;
}
void BellaKira()
{
	cin>>n>>m;
	poly g;
	for (int i=1;i<=n;i++) g.push_back(i);
	shuffle(g.begin(),g.end(),rnd);
	while (g.size()>20) g.pop_back();
	int x=g[0];
	for (int i=1;i<g.size();i++)
		if (cmp(x,g[i]))
		{
			// cout<<x<<"???"<<g[i]<<endl;
			x=g[i];
		}
	poly a;
	a.push_back(x);
	for (int i=1;i<=n;i++)
		if (x!=i) a.push_back(i);
	int now=1;
	while (now*2<=n)
	{
		poly gx,gy;
		for (int i=1;i<=now;i++) gx.push_back(a[i-1]);
		for (int i=now+1;i<=now*2;i++) gy.push_back(a[i-1]);
		int v=query(gx,gy);
		if (v==1)
		{
			n=now*2;
			break;
		} else
		{
			now*=2;
		}
	}
	int l=now+1,r=n;
	int ans=now;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		poly gx,gy;
		for (int i=now+1;i<=mid;i++) gy.push_back(a[i-1]);
		for (int i=1;i<=(mid-now);i++) gx.push_back(a[i-1]);
		int v=query(gx,gy);
		if (v==1)
		{
			ans=mid;
			r=mid-1;
		} else
		{
			l=mid+1;
		}
	}
	cout<<"! "<<a[ans-1]<<endl;
}
signed main()
{
	// IOS;
	// cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}