// Lynkcat.
// Problem: D. Traps
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/D
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
int n,m,ans,a[N],b[N];
void BellaKira()
{
	ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	priority_queue<int>q;
	for (int i=1;i<=n;i++)
	{
		b[i]=(n-i);
		ans+=a[i];
		q.push(a[i]-b[i]);
	}
	int tot=0;
	int nowans=ans;
	while (m&&!q.empty())
	{
		m--;
		ans-=q.top();
		ans-=tot;
		tot++;
		nowans=min(nowans,ans);
		q.pop();
	}
	cout<<nowans<<endl;
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