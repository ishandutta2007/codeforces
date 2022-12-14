// Lynkcat.
// Problem: E2. Divisible Numbers (hard version)
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/E2
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
	poly x,y;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for (int i=1;i*i<=a;i++)
		if (a%i==0)
		{
			x.push_back(i);
			x.push_back(a/i);
		}
	for (int i=1;i*i<=b;i++)
		if (b%i==0)
		{
			y.push_back(i);
			y.push_back(b/i);
		}
	for (auto i:x)
		for (auto j:y)
		{
			int X=i*j;
			int Y=a*b/i/j;
			int nw=a+1,nw1=b+1;
			if (nw%X!=0) nw+=X-nw%X;
			if (nw1%Y!=0) nw1+=Y-nw1%Y;
			if (nw>a&&nw<=c&&nw1>b&&nw1<=d) return cout<<nw<<" "<<nw1<<'\n',void();
		}
	cout<<-1<<" "<<-1<<'\n';
			
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