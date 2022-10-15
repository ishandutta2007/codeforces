// Lynkcat.
// Problem: F. Lost Array
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/F
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
#define N 2000005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>b[i];
	int m=1,t=0;
	while (m<=n)
	{
		m<<=1;
		t++;
	}
	for (int i=0;i<t;i++)
		for (int j=0;j<n;j++)
			if ((j>>i)&1)
				b[j]^=b[j^(1<<i)];
	for (int i=0;i<t;i++)
		for (int j=0;j<n;j++)
			if ((j>>i)&1)
				b[j^(1<<i)]^=b[j];
	for (int i=0;i<n;i++) cout<<b[n-i-1]<<" ";
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