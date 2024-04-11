// Lynkcat.
// Problem: C. Canine poetry
// URL: https://codeforces.com/contest/1466/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define N 100005
using namespace std;
string st;
int dp[N];
int ans;
void BellaKira()
{
	ans=0;
	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		if (i>=1&&st[i-1]==st[i])
		{
			st[i]='#';
			ans++;
		} else
		if (i>=2&&st[i-2]==st[i])
		{
			st[i]='#';
			ans++;
		}
	}
	// cout<<st<<endl;
	cout<<ans<<endl;
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