#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> e[200010];
map<ll,ll> mp[200010];
ll a[200010];
ll dfs(int x,ll k)
{
	if (mp[x][k]) return mp[x][k]-1;
	if (!k || !e[x].size()) return k*a[x];
	ll l=k/e[x].size(),r=(k+e[x].size()-1)/e[x].size(),res=k*a[x],cnt=k%e[x].size();
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	for (auto p:e[x])
	{
		ll t1=dfs(p,l),t2=r!=l?dfs(p,r):t1;
		res+=t2;
		pq.push(t2-t1);
		if (!cnt) {res-=pq.top();pq.pop();}
		else cnt--;
	}
	mp[x][k]=res+1;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i;ll k;cin>>n>>k;
		for (i=1;i<=n;i++) e[i].clear(),mp[i].clear();
		for (i=2;i<=n;i++)
		{
			int x;cin>>x;
			e[x].push_back(i);
		}
		for (i=1;i<=n;i++) cin>>a[i];
		cout<<dfs(1,k)<<endl;
	}
}