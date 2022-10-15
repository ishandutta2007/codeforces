// Lynkcat.
// Problem: A. Polycarp and Sums of Subsequences
// URL: https://codeforces.com/contest/1618/problem/A
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
int a[8];
void BellaKira()
{
	for (int i=1;i<=7;i++)
		cin>>a[i];
	sort(a+1,a+8);
	if (a[4]==a[1]+a[2])
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	else cout<<a[1]<<" "<<a[2]<<" "<<a[4]<<endl;
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