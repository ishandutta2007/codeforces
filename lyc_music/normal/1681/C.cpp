// Lynkcat.
// Problem: C. Double Sort
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/C
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
#define N  105
using namespace std;
int n,a[N],b[N],p[N];
int B[N];
bool cmp(int x,int y)
{
	if (a[x]==a[y]) return b[x]>b[y];
	return a[x]>a[y];
}
void BellaKira()
{
	poly G;
	cin>>n;
	for (int i=1;i<=n;i++)p[i]=i;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<n;j++)
			if (cmp(p[j],p[j+1]))
			{
				// cout<<"?"<<p[j]<<" "<<p[j+1]<<" "<<a[p[j]]<<" "<<a[p[j+1]]<<endl;
				G.push_back(j);
				swap(p[j],p[j+1]);
			}
	for (int i=1;i<=n;i++)
	{
		B[i]=b[p[i]];
	}
	int ans=1;
	for (int i=2;i<=n;i++)
		if (B[i-1]>B[i]) ans=0;
	if (ans==0) cout<<"-1"<<endl;
	else
	{
		cout<<G.size()<<endl;
		for (auto u:G) cout<<u<<" "<<u+1<<endl;
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