// Lynkcat.
// Problem: D. The Clock
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/D
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
void BellaKira()
{
	string st;
	int xx;
	cin>>st>>xx;
	int s=((st[0]-'0')*10+(st[1]-'0'))*60+((st[3]-'0')*10+st[4]-'0');
	int ans=0;
	for (int i=0;i<1440;i++)
	{
		int x=i/60,y=i%60;
		int dis=0;
		if (i<s) dis=i+1440-s;
		else dis=i-s;
			if (dis%__gcd(xx,1440ll)==0)
			{
				string a,b;
				a=to_string(x);
				while (a.size()!=2) a='0'+a;
				b=to_string(y);
				while (b.size()!=2) b='0'+b;
				if (a[0]==b[1]&&a[1]==b[0]) 
				{
					ans++;
				}
			}
	}
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