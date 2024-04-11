// Lynkcat.
// Problem: C. Sum of Substrings
// URL: https://codeforces.com/contest/1691/problem/C
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
#define int ll
//#define N
using namespace std;
int n,m;
string st;
void BellaKira()
{
	cin>>n>>m>>st;
	poly g;
	for (int i=0;i<st.size();i++)
	{
		if (st[i]=='1') g.push_back(i);
	}
	int ans=g.size()*11;
	if (g.size()==0)
	{
		cout<<0<<endl;
		return;
	}
	if (g.size()==1)
	{
		if (n-1-g[0]<=m) ans-=10;
		else
			if (g[0]<=m) ans-=1;
	} else
	{
		if (n-1-g.back()+g[0]<=m) ans-=11;
		else
		{
			if (n-1-g.back()<=m) ans-=10;
			else
			{
				if (g[0]<=m) ans-=1;
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