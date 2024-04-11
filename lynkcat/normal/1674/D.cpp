// Lynkcat.
// Problem: D. A-B-C Sort
// URL: https://codeforces.com/contest/1674/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

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
#define N 200005
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	int ans=1;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=n%2+1;i+1<=n;i+=2)
		if (a[i]>a[i+1]) swap(a[i],a[i+1]);
	for (int i=2;i<=n;i++)
		if (a[i]<a[i-1]) ans=0;
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}