// Lynkcat.
// Problem: A. Print a Pedestal (Codeforces logo?)
// URL: https://codeforces.com/contest/1690/problem/A
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
#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	if (n%3==0)
	{
		cout<<n/3<<" "<<n/3+1<<" "<<n/3-1<<endl;
	} else
	if (n%3==1)
	{
		cout<<n/3<<" "<<n/3+2<<" "<<n/3-1<<endl;
	} else
	if (n%3==2)
	{
		cout<<n/3+1<<" "<<n/3+2<<" "<<n/3-1<<endl;
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