// Lynkcat.
// Problem: H. Hard Cut
// URL: https://codeforces.com/contest/1684/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
// #define int ll
//#define N
using namespace std;
string st;
void BellaKira()
{
	int sum=0;
	cin>>st;
	for (auto u:st) sum+=u-'0';
	if (sum==5)
	{
		poly g;
		for (int i=0;i<st.size();i++)
			if (st[i]=='1')
				g.push_back(i+1);
		bool bl=1;
		for (int j=1;j<g.size();j++)
			if (g[j]!=g[j-1]+1) bl=0;
		poly ans;
		if (bl) 
		{
			if (g[0]-1) ans.push_back(g[0]-1);
			ans.push_back(g[g.size()-2]);
			ans.push_back(g.back());
			if (g.back()!=st.size()) ans.push_back(st.size());
			int lst=0;		
			cout<<ans.size()<<'\n';
			for (auto u:ans)
				cout<<lst+1<<" "<<u<<'\n',lst=u;
			return;
		} else
		{
			int now=0;
				for (int i=0;i+1<g.size();i++)
					if (g[i+1]!=g[i]+1)
					{
						now=g[i];
						break;
					}
				int i=0;
			for (auto u:g) 
			{
				if (u!=now)
					ans.push_back(u); 
				else
				{
					if (g[i+1]!=g[i]+2)
					{
						ans.push_back(g[i]+2);
					}
				}
				i++;
			}
			if (ans.back()!=st.size()) ans.push_back(st.size());
			int lst=0;		
			cout<<ans.size()<<'\n';
			for (auto u:ans)
				cout<<lst+1<<" "<<u<<'\n',lst=u;
			return;
		}
	}
	int x=1;
	// cout<<sum<<'\n';
	while (x<sum) x<<=1;
	int nowsum=0;
	int now=0;
	poly g;
	int i=0;
	int res=sum;
	for (auto u:st)
	{
		res-=u-'0';
		if (nowsum+now*2+u-'0'+res>x)
		{
			nowsum+=now;
			now=u-'0';
			g.push_back(i);
		} else now=now*2+u-'0';
		i++;
	}
	nowsum+=now;
	if (nowsum!=x) return cout<<-1<<'\n',void();
	// cout<<nowsum<<" "<<x<<'\n';
	// assert(nowsum==x);
	g.push_back(st.size());
	int lst=0;
	cout<<g.size()<<'\n';
	for (auto u:g)
		cout<<lst+1<<" "<<u<<'\n',lst=u;
		 
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