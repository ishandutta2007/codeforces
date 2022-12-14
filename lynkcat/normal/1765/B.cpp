// Problem: B. Broken Keyboard
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/B
// Memory Limit: 512 MB
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
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	string s;
	cin>>n>>s;
	int l=0,x=0;
	while (l<n)
	{
		// cout<<l<<" "<<x<<endl;
		if (x==0)
		{
			l++;
		} else
		{
			if (l+1<n&&s[l]==s[l+1]) l+=2;
			else
			{
				return cout<<"NO\n",void();
			}
		}
		x^=1;
	}
	cout<<"YES\n";
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}