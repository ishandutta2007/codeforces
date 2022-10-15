// Lynkcat.
// Problem: C. Cypher
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/C
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
#define N 1000005
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		string st;
		int x;
		cin>>x;
		cin>>st;
		int nw=0;
		for (auto u:st)
		{
			if (u=='U')  nw=(nw+1)%10;
			else nw=(nw-1+10)%10;
		}
		// cout<<nw<<" "<<x<<endl;
		// nw=nw*x%10;
		a[i]=(a[i]-nw+10)%10;
		cout<<a[i]<<" ";
	}
	cout<<endl;
		
		
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