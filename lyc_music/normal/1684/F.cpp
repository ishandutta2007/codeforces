// Lynkcat.
// Problem: F. Diverse Segments
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/F
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
#define int ll
#define N 200005
using namespace std;
int a[N];
int pre[N];
int suf[N];
int L[N],R[N];
int lf[N];
int n,m;
void BellaKira()
{
	map<int,poly>Mp;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		lf[i]=n+1,L[i]=n+1;
		Mp[a[i]].push_back(i);
	}
	for (int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		L[r]=min(L[r],l);
	}
	int nowl=n+1;
	int mxr=1;
	for (int i=n;i>=1;i--)
	{
		nowl=min(nowl,L[i]);
		Mp[a[i]].pop_back();
		// cout<<i<<","<<nowl<<endl;
		if (nowl<i)
		{
			if (Mp[a[i]].size()&&Mp[a[i]].back()>=nowl)
			{
				int now=lower_bound(Mp[a[i]].begin(),Mp[a[i]].end(),nowl)-Mp[a[i]].begin();
				// cout<<"?"<<Mp[a[i]][now]<<" "<<Mp[a[i]][now+1]<<endl;
				mxr=max(mxr,Mp[a[i]].back());
				if (now==Mp[a[i]].size()-1)
					lf[n]=min(lf[n],i);
				else lf[n]=min(lf[n],Mp[a[i]][now+1]);
				lf[i-1]=min(lf[i-1],Mp[a[i]][now]);
			}
		}
	}
	int ans=n;
	lf[n+1]=n+1;
	for (int i=n;i>=mxr;i--)
	{
		lf[i]=min(lf[i],lf[i+1]);
		// cout<<i<<","<<lf[i]<<endl;
		ans=min(max(0ll,i-lf[i]+1),ans);
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