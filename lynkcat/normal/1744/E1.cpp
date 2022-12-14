// Lynkcat.
// Problem: E1. Divisible Numbers (easy version)
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/E1
// Memory Limit: 256 MB
// Time Limit: 4000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=a*b;
	for (int i=1;i<=100000;i++)
	{
		int g=__gcd(x,i);
		int X=x*i/g;
		int y=X/i;
		int o=(b/y)*y;
		while (o<=b) o+=y;
		// if (i==2)
			// cout<<"?"<<i<<" "<<o<<endl;
			if (i>a&&i<=c&&o>b&&o<=d) return cout<<i<<" "<<o<<'\n',void();
	}
	cout<<-1<<" -1\n";
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}