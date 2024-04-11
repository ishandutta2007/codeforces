// Lynkcat.
// Problem: CF883J Renovation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF883J
// Memory Limit: 250 MB
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
#define int ll
#define N 200005
using namespace std;
int n,a[N],s[N],m;
pa b[N];
priority_queue<pa>q;
priority_queue<int>ss;
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	for (int i=1;i<=m;i++) cin>>b[i].fi;
	for (int i=1;i<=m;i++) cin>>b[i].se;
	sort(b+1,b+m+1);
	poly g;
	int mx=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]>mx)
		{
			mx=max(mx,a[i]);
			g.push_back(i);
		}
	}
	g.push_back(0);
	int l=m;
	int ans=0;
	int sm=0;
	// cout<<"?"<<g.size()<<endl;
	for (int i=(int)g.size()-2;i>=0;i--)
	{
		while (l>=1&&b[l].fi>(i==0?0:a[g[i-1]]))
		{
			q.push(mp(-b[l].se,b[l].fi));
			l--;
		}
		sm+=s[g[i]]-s[g[i+1]];
		// cout<<"!!"<<sm<<" "<<ans<<endl;
		while (!q.empty()&&((-q.top().fi<=sm||ss.size()&&-q.top().fi<ss.top())))
		{
			if (q.top().se>a[g[i]])
			{
				q.pop();
				continue;
			}
			// cout<<"?"<<-q.top().fi<<" "<<ans<<endl;
			if (-q.top().fi>sm)
			{
				sm+=ss.top();
				ans--;
				ss.pop();
			}
			sm-=-q.top().fi;
			ss.push(-q.top().fi);
			ans++;
			q.pop();
		}
	}
	cout<<ans<<endl;
		
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}