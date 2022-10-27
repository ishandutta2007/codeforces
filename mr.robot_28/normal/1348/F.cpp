#include <bits/stdc++.h>
using namespace std;
vector <set <int> > tree;
vector <int> a, b, par, ans;
int n;
bool cmp(int t1, int t2)
{
	return a[t1] < a[t2];
}
void upd(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r<= ar)
	{
		tree[v].insert(val);
	}
	else if(l <= ar && r >= al)
	{
		upd(v * 2, l, (r + l) / 2, al, ar, val);
		upd(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int get(int v, int l, int r, int al, int ar, int x)
{
	set <int> :: iterator it;
	it = tree[v].lower_bound(al);
	if(it != tree[v].end() && *it <= ar)
	{
		return par[*it];
	}
	if(l == r)
	{
		return 0;
	}
	if(x <= (r + l) / 2)
	{
		return get(v * 2, l, (r + l) / 2, al, ar, x);
	}
	else
	{
		return get(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	tree.resize(4 * n + 4);
	a.resize(n + 1);
	b.resize(n + 1);
	vector <int> v;
	par.resize(n + 1);
	ans.resize(n + 1);
	for(int i = 1; i <= n; i++)
	{
		v.push_back(i);
		cin >> a[i] >> b[i];
	}
	sort(v.begin(), v.end(), cmp);
	set <pair <int, int> > s;
	for(int i = 1, j = 0; i <= n; i++)
	{
		while(j < n && a[v[j]] <= i)
		{
			s.insert({b[v[j]], v[j]});
			j++;
		}
		set <pair <int, int> > :: iterator it;
		it = s.begin();
		ans[it -> second] = i;
		par[i] = it -> second;
		s.erase(it);
	}
	pair <int, int> sw = make_pair(0, 0);
	for(int j = 0; j < n; j++)
	{
		int i = v[j];
		int x = 0;
		x = get(1, 1, n, a[i], b[i], ans[i]);
		if(x != 0)
		{
			sw = {i, x};
			break;
		}
		upd(1, 1, n, a[i], b[i], ans[i]);
	}
	if(sw.first == 0)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	for(int i = 1; i <=n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	if(sw.first != 0)
	{
		swap(ans[sw.first], ans[sw.second]);
		for(int i= 1; i <= n; i++)
		{
			cout << ans[i] << " ";
		}
	}
	return 0;
}