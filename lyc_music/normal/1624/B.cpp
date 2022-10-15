// Lynkcat.
// Problem: B. Make AP
// URL: https://codeforces.com/contest/1624/problem/B
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
void BellaKira()
{
	int x,y,z;
	int ans=0;
	cin>>x>>y>>z;
	if ((x+z)%2==0&&((x+z)/2%y)==0&&((x+z)/2)>0) ans=1;
	if ((y+y-x)%z==0&&((y+y-x)>0)) ans=1;
	if ((y-(z-y))%x==0&&((y-(z-y))>0)) ans=1;
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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