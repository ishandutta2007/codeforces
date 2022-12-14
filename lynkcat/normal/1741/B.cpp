// Lynkcat.
// Problem: B. Funny Permutation
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/B
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
#define inf 1e9
#define mod 998244353
// #define int ll
// #define N 
using namespace std;
int n,ans[200005];
void BellaKira()
{
	cin>>n;
	if (n==2)
	{
		cout<<"2 1\n";
		return;
	}
	if (n<=3) return cout<<"-1\n",void();
	int tot=0;
	for (int i=n;i>=1;i--) ans[++tot]=i;
	if (n%2==1) reverse(ans+1,ans+(n+1)/2+1);
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}