// Lynkcat.
// Problem: C. Odd/Even Increments
// URL: https://codeforces.com/contest/1669/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//#define N
using namespace std;
int n,a[10005];
void BellaKira()
{
	cin>>n;
	bool bl=1,bl1=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]%2!=a[(i-1)%2+1]%2)
			bl=0;
	}
	if (bl) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}