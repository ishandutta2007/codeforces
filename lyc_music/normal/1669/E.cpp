// Lynkcat.
// Problem: E. 2-Letter Strings
// URL: https://codeforces.com/contest/1669/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
//#define N
using namespace std;
int n;
void BellaKira()
{
	cin>>n;
	int ans=0;
	map<string,int>Mp;
	map<char,int>Mp1;
	map<char,int>Mp2;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		ans-=Mp[st]*2;
		Mp[st]++;
		ans+=Mp1[st[0]];
		ans+=Mp2[st[1]];
		Mp1[st[0]]++;
		Mp2[st[1]]++;
	}
	cout<<ans<<endl;
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