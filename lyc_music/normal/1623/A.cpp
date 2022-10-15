// Lynkcat.
// Problem: A. Robot Cleaner
// URL: https://codeforces.com/contest/1623/problem/A
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
int n,m,rb,cb,rd,cd;
void BellaKira()
{
	cin>>n>>m>>rb>>cb>>rd>>cd;
	int ans=inf;
	if (rb<=rd) ans=min(ans,rd-rb);
	else ans=min(n-rd+n-rb,ans);
	
	if (cb<=cd) ans=min(ans,cd-cb);
	else ans=min(m-cd+m-cb,ans);
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