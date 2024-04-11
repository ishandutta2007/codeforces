// Lynkcat.
// Problem: F. Multi-Colored Segments
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
#define N 400005
using namespace std;
int n;
int l[N],r[N],c[N],ans[N];
poly G[N],E[N];
int Lst[N];
int cnt[N];
int Tot[N];
int R[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>l[i]>>r[i]>>c[i];
	// cout<<"!!"<<endl;
	for (int i=1;i<=n;i++) ans[i]=inf;
	{
	// cout<<"!!"<<endl;
		poly g;
		for (int i=1;i<=n;i++)
		{
			g.push_back(l[i]);
			g.push_back(r[i]+1);
		}
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		for (int i=1;i<=n;i++)
			G[lower_bound(g.begin(),g.end(),l[i])-g.begin()+1].push_back(i);
		for (int i=1;i<=n;i++)
			E[lower_bound(g.begin(),g.end(),r[i]+1)-g.begin()+1].push_back(i);
		multiset<int>S;
		multiset<int>S1;
		for (int i=1;i<=n;i++) Tot[i]=0;
		int Tt=0;
		for (int i=1;i<=g.size();i++)
		{
			for (auto u:E[i])
			{
				cnt[c[u]]--;
				if (!cnt[c[u]])
				{
					S.erase(S.find(c[u]));
				}
				if (R[c[u]]) 
				{
					S1.erase(S1.find(R[c[u]]));
					R[c[u]]=max(R[c[u]],r[u]);
					S1.insert(R[c[u]]);
				} else R[c[u]]=r[u],S1.insert(R[c[u]]);
			}
			for (auto u:E[i])
			{
				int v=Tt-Tot[c[u]];
				if (v+Lst[u])
				{
					ans[u]=0;
				}
			}
			for (auto u:G[i])
			{
				cnt[c[u]]++;
				if (cnt[c[u]]==1) S.insert(c[u]);
			}
			for (auto u:G[i])
			{
				if (S.size()-S.count(c[u]))
				{
					ans[u]=0;
				}
				Lst[u]=Tot[c[u]]-Tt;
					if (S1.size())
					{
						if (R[c[u]]==(*S1.rbegin()))
						{
							if (S1.size()>1)
							{
								int x=(*(--(--S1.end())));
								ans[u]=min(ans[u],l[u]-x);
							}
						} else
							{
								int x=(*(--S1.end()));
								ans[u]=min(ans[u],l[u]-x);
							}
					}
			}
			for (auto u:G[i])
				Tot[c[u]]++,Tt++;
		}
		for (int i=1;i<=g.size();i++) poly().swap(E[i]),poly().swap(G[i]);
		for (int i=1;i<=n;i++) R[i]=0,Lst[i]=0,cnt[i]=0;
		// cout<<"!!"<<endl;
	}
	{
		// cout<<"!!"<<endl;
		for (int i=1;i<=n;i++) r[i]=1000000000-r[i]+1,l[i]=1000000000-l[i]+1,swap(l[i],r[i]);
		poly g;
		for (int i=1;i<=n;i++)
		{
			g.push_back(l[i]);
			g.push_back(r[i]+1);
		}
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		for (int i=1;i<=n;i++)
			G[lower_bound(g.begin(),g.end(),l[i])-g.begin()+1].push_back(i);
		for (int i=1;i<=n;i++)
			E[lower_bound(g.begin(),g.end(),r[i]+1)-g.begin()+1].push_back(i);
		multiset<int>S;
		multiset<int>S1;
		for (int i=1;i<=n;i++) Tot[i]=0;
		int Tt=0;
		for (int i=1;i<=g.size();i++)
		{
			for (auto u:E[i])
			{
				cnt[c[u]]--;
				if (!cnt[c[u]])
				{
					S.erase(S.find(c[u]));
				}
				if (R[c[u]]) 
				{
					S1.erase(S1.find(R[c[u]]));
					R[c[u]]=max(R[c[u]],r[u]);
					S1.insert(R[c[u]]);
				} else R[c[u]]=r[u],S1.insert(R[c[u]]);
			}
			for (auto u:E[i])
			{
				int v=Tt-Tot[c[u]];
				if (v+Lst[u])
				{
					ans[u]=0;
				}
			}
			for (auto u:G[i])
			{
				cnt[c[u]]++;
				if (cnt[c[u]]==1) S.insert(c[u]);
			}
			for (auto u:G[i])
			{
				if (S.size()-S.count(c[u]))
				{
					ans[u]=0;
				}
				Lst[u]=Tot[c[u]]-Tt;
					if (S1.size())
					{
						if (R[c[u]]==(*S1.rbegin()))
						{
							if (S1.size()>1)
							{
								int x=(*(--(--S1.end())));
								ans[u]=min(ans[u],l[u]-x);
							}
						} else
							{
								int x=(*(--S1.end()));
								ans[u]=min(ans[u],l[u]-x);
							}
					}
			}
			for (auto u:G[i])
				Tot[c[u]]++,Tt++;
		}
		for (int i=1;i<=g.size();i++) poly().swap(E[i]),poly().swap(G[i]);
		for (int i=1;i<=n;i++) R[i]=0,Lst[i]=0,cnt[i]=0;
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
		
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