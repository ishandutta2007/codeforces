// Lynkcat.
// Problem: B. NIT Destroys the Universe
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
int n,x;
void BellaKira()
{
	cin>>n;
	int bl=0;
	int all=0;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		if (x==0) 
		{
			all+=(bl>0);
			bl=0;
		}  else bl++;
	}
	all+=(bl>0);
	cout<<min(all,2ll)<<endl;
		
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