#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, p;
pair<int, int> a[200005], b[200005];
pair<int, pair<int, int> > x[200005];
int it[800005], lazy[800005];

void build_tree(int id, int l, int r)
{
	if(l==r)
	{
		it[id]=-b[l].second;
		return;
	}
	int mid=(l+r)/2;
	build_tree(id*2, l, mid);
	build_tree(id*2+1, mid+1, r);
	it[id]=max(it[id*2], it[id*2+1]);
}

void down(int id)
{
	it[id*2]+=lazy[id];
	it[id*2+1]+=lazy[id];
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}

int get(int val)
{
	int lo=1, hi=m+1;
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(b[mid].first<=val) lo=mid+1;
		else hi=mid;
	}
	return lo;
}

void update(int id, int l, int r, int u, int v, int val)
{
	if(l>v||r<u) return;
	else if(l>=u&&r<=v)
	{
		it[id]+=val;
		lazy[id]+=val;
		return;
	}
	down(id);
	int mid=(l+r)/2;
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);
	it[id]=max(it[id*2], it[id*2+1]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>p;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=m; i++)
	{
		cin>>b[i].first>>b[i].second;
	}
	sort(b+1, b+m+1);
	for(int i=1; i<=p; i++)
	{
		cin>>x[i].first>>x[i].second.first>>x[i].second.second;
	}
	sort(x+1, x+p+1);
	build_tree(1, 1, m);
	int ite=1;
	int ans=-10000000000;
	for(int i=1; i<=n; i++)
	{
		while(ite<=p&&x[ite].first<a[i].first)
		{
			//cout<<ite<<" "<<get(x[ite].second.first)<<"dit\n";
			update(1, 1, m, get(x[ite].second.first), m, x[ite].second.second);
			ite++;
		}
		//cout<<i<<" "<<ite<<" "<<ite<<endl;
		ans=max(ans, it[1]-a[i].second);
	}
	cout<<ans;
}