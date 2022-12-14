// Lynkcat.
// Problem: A. Number Replacement
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/A
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
#define N 55 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)	cin>>a[i];
	string st;
	cin>>st;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if ((st[i-1]!=st[j-1])&&(a[i]==a[j])) ans=1;
	if (ans) cout<<"NO\n";
	else cout<<"YES\n";
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