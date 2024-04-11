// Lynkcat.
// Problem: A. Food for Animals
// URL: https://codeforces.com/contest/1675/problem/A
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
#define int ll
//#define N
using namespace std;
void BellaKira()
{	
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
x-=a,y-=b;
x=max(x,0ll);
y=max(y,0ll);
if (x+y<=c) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}