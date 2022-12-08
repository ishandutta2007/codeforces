#include <bits/stdc++.h>
#define int long long
#define a first
#define b second

using namespace std;

int ans[1000005];
int n;

struct cht{
	vector<pair<int, int> > v;
	int pt=0;
	int val(int pos, int x)
	{
		return v[pos].a*x+v[pos].b;
	}

	bool lmao(pair<int, int> p0, pair<int, int> p1, pair<int, int> p2)
	{
		double lel=1.0*(p1.b-p0.b)*(p1.a-p2.a)-1.0*(p2.b-p1.b)*(p0.a-p1.a)>=1e-7;
		if(lel>0) return true;
		return false;
	}

	void add(int a, int b)
	{
		for(pair<int, int> hic={a,b}; v.size()>1&&lmao(hic, v[v.size()-1], v[v.size()-2]); v.pop_back());
		v.push_back({a, b});
	}

	int get(int x)
	{
		for(pt=min(pt, (int) v.size()-1); pt+1<(int)v.size() && val(pt, x)<val(pt+1, x); pt++);
		return val(pt, x);
	}
} C;

pair<int, pair<int, int> > a[1000005];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	C.add(0,0);
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].first>>a[i].second.first>>a[i].second.second;
	}
	sort(a+1, a+n+1);
	int hihi=-1000000000000000000;
	for(int i=1; i<=n; i++)
	{
		ans[i]=C.get(a[i].second.first)-a[i].second.second+a[i].first*a[i].second.first;
		C.add(-a[i].first, ans[i]);
		hihi=max(hihi, ans[i]);
	}
	cout<<hihi;
}