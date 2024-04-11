// Lynkcat.
// Problem: A. Division?
// URL: https://codeforces.com/contest/1669/problem/A
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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	cout<<"Division ";
	if (n<=1399) cout<<4<<endl;
	else if (n<=1599) cout<<3<<endl;
	else if (n<=1899) cout<<2<<endl;
	else cout<<1<<endl;
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