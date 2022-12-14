// Lynkcat.
// Problem: C. Where's the Bishop?
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/C
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
// #define N 
using namespace std;
string a[15];
void BellaKira()
{
	for (int i=1;i<=8;i++)
	{
		cin>>a[i];
		a[i]=' '+a[i];
	}
	for (int i=2;i<=7;i++)
		for (int j=2;j<=7;j++)
			if (a[i-1][j-1]==a[i-1][j+1]&&a[i-1][j-1]==a[i+1][j-1]&&a[i-1][j-1]==a[i+1][j+1]&&a[i-1][j-1]=='#'&&a[i][j]=='#')
				cout<<i<<" "<<j<<endl;
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