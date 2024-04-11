// Problem: A. Doremy's Paint
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
#define N 100005 
int n,a[N];
using namespace std;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cout<<1<<" "<<n<<'\n';
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}