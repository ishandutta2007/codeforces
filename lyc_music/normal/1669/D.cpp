// Lynkcat.
// Problem: D. Colorful Stamp
// URL: https://codeforces.com/contest/1669/problem/D
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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	string st;
	cin>>n;
	cin>>st;
	st=st+'W';
	int l=0;
	int now=1;
	int ans=1;
	for (int i=0;i<=n;i++)
	{
		if (st[i]=='W'&&(i!=0&&st[i-1]!='W'))
		{
			// cout<<"!"<<i<<" "<<now<<" "<<l<<endl;
			if (now) ans=0;
			now=1;
			l=i+1;
			continue;
		}
		if (st[i]=='W') 
		{
			now=1;
			l=i+1;
			continue;
		}
		if (st[i]!=st[l]) now=0;
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}