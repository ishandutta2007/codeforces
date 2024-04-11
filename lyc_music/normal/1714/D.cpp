// Lynkcat.
// Problem: D. Color with Occurrences
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/D
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
#define N 105 
using namespace std;
string st;
int nn;
int dp[N],lst[N],now[N];
int n;
vector<pa> G[N];
string a[N];
void BellaKira()
{
	cin>>st;
	n=st.size();
	// cout<<n<<" "<<st<<endl;
	cin>>nn;
	for (int i=1;i<=nn;i++)
	{
		cin>>a[i];
		for (int j=0;j<st.size();j++)	
		{
			string now="";
			for (int k=j;k<st.size();k++)
			{
				now+=st[k];
				if (now.size()==a[i].size()&&now==a[i]) 
					G[k+1].push_back(mp(i,j));
					// cout<<j<<","<<k+1<<endl;
			}
		}
	}
	dp[0]=0;
	lst[0]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=inf;
		lst[i]=0;
		for (auto U:G[i])
		{
			int w=U.fi,u=U.se;
			for (int j=u;j<=i;j++)
				if (dp[j]+1<dp[i])
				{
					dp[i]=dp[j]+1;
					lst[i]=j;
					now[i]=w;
				}
		}
		// cout<<i<<","<<dp[i]<<" "<<G[i].size()<<endl;
		G[i].clear();
	}
	if (dp[n]==inf) cout<<-1<<endl;
	else
	{
		cout<<dp[n]<<endl;
		int nw=n;
		while (nw)
		{
			cout<<now[nw]<<" "<<nw-a[now[nw]].size()+1<<endl;
			nw=lst[nw];
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