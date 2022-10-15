// Lynkcat.
// Problem: B. Permutation Chain
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/B
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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;int n,a[N];
void BellaKira()
{
	cin>>n;
	cout<<n<<endl;
	
		for (int j=1;j<=n;j++) cout<<j<<" ",a[j]=j;
	cout<<endl;
	swap(a[1],a[n]);
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=n;j++) cout<<a[j]<<" ";
		cout<<endl;
		swap(a[i],a[i+1]);
	}
	
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}