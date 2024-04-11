// Lynkcat.
// Problem: G. Fall Down
// URL: https://codeforces.com/contest/1669/problem/G
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
// #define int ll
#define N 55
using namespace std;
int n,m;
string a[N];
void outp()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) cout<<a[i][j];
		cout<<endl;
	}	
	cout<<endl;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=' '+a[i];
	}
	for (int i=n-1;i>=1;i--)
	{
		for (int j=1;j<=m;j++)
		{
			int x=i;
			while (x<n&&a[x][j]=='*'&&a[x+1][j]=='.')
			{
				swap(a[x][j],a[x+1][j]);
				x++;
			}
		}
	}
		outp();
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}