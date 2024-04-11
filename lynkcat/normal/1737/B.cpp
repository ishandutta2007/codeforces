// Problem: B. Ela's Fitness and the Luxury Number
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/B
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
// #define N 
using namespace std;
inline int calc(int x)
{
	int l=1,r=1000000000;
	int now=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (mid*(mid+2)<=x)
		{
			now=mid;
			l=mid+1;
		}  else r=mid-1;
	}
	int res=now;
	l=1,r=1000000000;
	now=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (mid*mid<=x)
		{
			now=mid;
			l=mid+1;
		} else r=mid-1;
	}
	res+=now;
	l=1,r=1000000000;
	now=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (mid*(mid+1)<=x)
		{
			now=mid;
			l=mid+1;
		} else r=mid-1;
	}
	res+=now;
	return res;
}
	
void BellaKira()
{
	int l,r;
	cin>>l>>r;
	cout<<calc(r)-calc(l-1)<<'\n';
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