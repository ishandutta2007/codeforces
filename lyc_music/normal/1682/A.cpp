// Lynkcat.
// Problem: A. Palindromic Indices
// URL: https://codeforces.com/contest/1682/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	string st;
	cin>>n>>st;
	st=' '+st;
	int l=n/2,r=n/2+1,now=2;
	if (n%2==1) l++,now--;
	while (l>1) if (st[l]==st[l-1]) l--,now++; else break;
	while (r<n) if (st[r]==st[r+1]) r++,now++; else break;
	cout<<now<<endl;
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