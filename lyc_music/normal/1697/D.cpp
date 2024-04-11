// Lynkcat.
// Problem: D. Guess The String
// URL: https://codeforces.com/contest/1697/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
#define N 2005
using namespace std;
int n,s[N],a[N],lst[N],val[N];
int query(int l,int r)
{
	cout<<"? 2 "<<l<<" "<<r<<endl;
	int res;
	cin>>res;
	return res;
}
int qry(int x)
{
	cout<<"? 1 "<<x<<endl;
	char res;
	cin>>res;
	return res-'a';
}
void BellaKira()
{
	cin>>n;
	int l=1;
	for (int i=1;i<=n;i++)
	{
		s[i]=query(1,i);
		if (s[i]>s[i-1])
		{
			a[i]=qry(i);
			for (int i=0;i<26;i++)
				val[i]++;
			// cout<<"!!"<<i<<" "<<a[i]<<endl;
			lst[a[i]]=i;
			val[a[i]]=1;
		} else
		{
			vector<pa>g;
			for (int ii=0;ii<26;ii++)
				if (lst[ii])
				{
					g.push_back(mp(lst[ii],ii));
				}
			// for (auto u:g) cout<<u.fi<<","<<u.se<<endl;
			sort(g.begin(),g.end());
			int l=0,r=g.size()-1;
			int now=r;
			while (l<=r)
			{
				int mid=l+(r-l)/2;
				if (query(g[mid].fi,i)==val[g[mid].se])
				{
					now=mid;
					l=mid+1;
				} else r=mid-1;
			}
			a[i]=g[now].se;
			for (int j=now+1;j<g.size();j++)
				val[g[j].se]++;
			lst[a[i]]=i;
			val[a[i]]=1;
		}
	}
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<char(a[i]+'a');
	cout<<endl;
	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}