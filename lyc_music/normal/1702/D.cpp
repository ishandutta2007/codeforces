// Lynkcat.
// Problem: D. Not a Cheap String
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
// #define N 
using namespace std;
void BellaKira()
{
	string st;
	int w;
	cin>>st;
	cin>>w;
	int n=st.size();
	vector<int>vis(n+1,0);
	vector<pa>a(n+1);
	st=' '+st;
	int sm=0;
	for (int i=1;i<=n;i++)
			a[i]=mp(st[i]-'a'+1,i),sm+=st[i]-'a'+1;
	sort(a.begin(),a.end());
	for (int i=n;i>=1;i--)
	{
		if (sm<=w)
		{
			break;
		}
		vis[a[i].se]=1;
		sm-=a[i].fi;
	}
	for (int i=1;i<=n;i++) if (!vis[i]) cout<<st[i];
	cout<<endl;
		
		
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