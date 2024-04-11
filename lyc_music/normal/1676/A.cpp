// Lynkcat.
// Problem: A. Lucky?
// URL: https://codeforces.com/contest/1676/problem/A
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
	string st;
	cin>>st;
	int now=0,now1=0;
	for (int i=0;i<3;i++) now+=st[i];
	for (int i=3;i<6;i++) now1+=st[i];
	if (now==now1) cout<<"YES"<<endl;
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