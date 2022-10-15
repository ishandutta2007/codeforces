// Lynkcat.
// Problem: F. Longest Strike
// URL: https://codeforces.com/contest/1676/problem/F
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
#define N 200005
using namespace std;
int n,m,a[N];
void BellaKira()
{
	map<int,int>Mp;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i],Mp[a[i]]++;
	poly g;
	for (auto u:Mp) if (u.se<m) g.push_back(u.fi);
	for (auto u:g) Mp.erase(u);
	if (Mp.size()==0) return cout<<-1<<endl,void();
	int lst=(*Mp.begin()).fi;
	int ans=1;
	pa nowans=mp(lst,lst);
	int sum=lst;
	auto now=Mp.begin();
	now++;
	while (now!=Mp.end())
	{
		if (sum==(*now).fi-1)
		{
			sum=(*now).fi;
			if (sum-lst+1>ans) ans=sum-lst+1,nowans=mp(lst,(*now).fi);
		} else
		{
			lst=(*now).fi;
			sum=(*now).fi;
			if (sum-lst+1>ans) ans=sum-lst+1,nowans=mp(lst,(*now).fi);
		}
		// cout<<lst<<" "<<sum<<" "<<(*now).fi<<endl;
		now++;
	}
	cout<<nowans.fi<<" "<<nowans.se<<endl;
	
			
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