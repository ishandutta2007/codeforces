// Lynkcat.
// Problem: D. Circular Spanning Tree
// URL: https://codeforces.com/contest/1682/problem/D
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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	string st;
	cin>>n;
	cin>>st;
	int nowx=0,nowy=0,nowz=1;
	for (auto u:st)
		nowx^=(u-'0'),nowy|=(u-'0'),nowz&=(u-'0');
	if (nowx==1||nowy==0)
	{
		return cout<<"NO"<<endl,void();
	}
	if (nowz==1)
	{
		cout<<"YES"<<endl;
		for (int i=2;i<=n;i++)
		{
			cout<<1<<" "<<i<<endl;
		}
	} else
	{
		cout<<"YES"<<endl;
		int now=0;
		for (int i=0;i<n;i++)
			if (st[i]=='0'&&st[(i+1)%n]!='0')
			{
				now=i;
			}
		int lst=now;
		for (int i=(now-1+n)%n;;i=(i-1+n)%n)
		{
			if (i==now) break;
			cout<<lst+1<<" "<<i+1<<endl;
			if (st[i]=='1')
			{
				lst=now;
			} else lst=i;
		}
	}
			
				
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