// Lynkcat.
// Problem: E. Replace With the Previous, Minimize
// URL: https://codeforces.com/contest/1675/problem/E
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
int n,m;
string st;
	set<int>S[255];
void BellaKira()
{
	cin>>n>>m;
	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		S[(int)st[i]].insert(i);
		// cout<<"!"<<(int)st[i]<<" "<<i<<endl;
	}
	m=min(m,26ll);
	int now='a';
	int o=m;
	int pp=0;
	for (int i=0;i<=n;i++)
	{
		if (st[i]-now>o||i==n)
		{
			// cout<<i<<" "<<(char)now<<" "<<char(pp+now)<<" "<<pp<<endl;
			for (int j=pp+now;j>now;j--)
			{
				set<int>nw=S[j];
				for (auto u:nw)
				{
					// cout<<(char)j<<endl;
					// cout<<st<<" "<<u<<endl;
					// assert(st[u]==j&&S[j].count(u));
					st[u]--;
					S[j-1].insert(u);
				}
				S[j].clear();
			}
			if (i==n) break;
			o-=pp;
			now=st[i]-o;
			now=max(now,(int)('a'));
			pp=st[i]-now;
		} else
		{
			pp=max(pp,st[i]-now);
			// st[i]=now;
		}
	}
	o-=pp;
	cout<<st<<endl;
	for (int i=0;i<st.size();i++) S[st[i]].erase(i);
		
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
/*
abcdefghijklmnopqrstuvwxyz
*/