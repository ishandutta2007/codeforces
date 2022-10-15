// Lynkcat.
// Problem: C. Virus
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
int n,m,a[N],vis[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	sort(a+1,a+m+1);
	priority_queue<int>q;
	for (int i=2;i<=m;i++)
	{
		q.push(a[i]-a[i-1]-1);
	}
	q.push(a[1]+n-a[m]-1);
	int x=0;
	int ans=0;
	while (!q.empty())
	{
		int u=q.top();
		q.pop();
		u-=x*2;
		// cout<<"?"<<u<<endl;
		if (u<=0) continue;
		if (u<=2) 
		{
			x++;
			ans++;
		}
		else
		{
			x+=2;
			ans+=u-1;
			// cout<<ans<<" "<<u<<endl;
		}
	}
	cout<<n-ans<<endl;
			
		
		
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