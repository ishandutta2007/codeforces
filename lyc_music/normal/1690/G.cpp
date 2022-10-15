// Lynkcat.
// Problem: G. Count the Trains
// URL: https://codeforces.com/contest/1690/problem/G
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
#define int ll
#define N 100005
using namespace std;
int n,m,a[N];
multiset<pa>S;
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=-1;
	int lst=1;
	for (int i=2;i<=n+1;i++)
		if (a[i]<a[lst])
		{
			S.insert(mp(lst,i-1));
			lst=i;
		}
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		auto now=S.lower_bound(mp(x+1,0));
		now--;
		a[x]-=y;
		// for (auto u:S) cout<<u.fi<<" "<<u.se<<endl;
		// for (int j=1;j<=n;j++) cout<<a[j]<<",";
		// cout<<endl;
		if (a[(*now).first]<=a[x]&&(*now).first!=x) 
		{
		cout<<S.size()<<" ";continue;
		}
		vector<pa>G;
		int lst=(*now).first;
		int nxt=(*now).second;
		S.erase(now);
		if (lst!=x) S.insert(mp(lst,x-1));
		now=S.lower_bound(mp(x+1,0));
		// cout<<"?"<<x<<" "<<nxt<<endl;
		while (now!=S.end())
		{
			if (a[(*now).first]>=a[x])
			{
				G.push_back((*now));
				nxt=(*now).second;
				now++;
			} else break;
		}
		for (auto u:G) S.erase(u);
		S.insert(mp(x,nxt));
		cout<<S.size()<<" ";
	}	
	cout<<endl;
	S.clear();
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