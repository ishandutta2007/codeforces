// Lynkcat.
// Problem: H. Zigu Zagu
// URL: https://codeforces.com/contest/1672/problem/H
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
#define N 200005
using namespace std;
int n,q;
string st;
int s[N][2];
void BellaKira()
{
	cin>>n>>q;
	cin>>st;
	st=' '+st;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=1;j++)
			s[i][j]=s[i-1][j];
		if (st[i]==st[i-1]) s[i][st[i]-'0']++;
	}
	for (int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		int x=s[r][1]-s[l][1];
		int y=s[r][0]-s[l][0];
		cout<<max({x,y,(x+y+1)/2})+1<<endl;
	}
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}