// Lynkcat.
// Problem: C. Stripes
// Contest: Codeforces - Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/C
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
char a[15][15];
void BellaKira()
{
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++)
			cin>>a[i][j];
	char ans='B';
	for (int i=1;i<=8;i++)
	{
		int x=0;
		for (int j=1;j<=8;j++)
			if (a[i][j]=='R') x++;
		if (x==8) ans='R';
	}
	cout<<ans<<'\n';
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