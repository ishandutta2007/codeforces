#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > tree;
vector <vector <int> > iter1, iter2;
vector <int> p;
void build(int v, int l, int r)
{
	if(l == r)
	{
		tree[v].push_back(p[l]);
		iter1[v].resize(1);
		iter2[v].resize(1);
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		int j = 0;
		for(int i = 0; i < tree[v * 2].size(); i++)
		{
			while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] < tree[v * 2][i])
			{
				tree[v].push_back(tree[v * 2 + 1][j]);
				j++;
			}
			tree[v].push_back(tree[v * 2][i]);
		}
		while(j < tree[v * 2 + 1].size())
		{
			tree[v].push_back(tree[v * 2 + 1][j]);
			j++;
		}
		j = 0;
		iter1[v].resize(tree[v].size());
		iter2[v].resize(tree[v].size());
		for(int i = 0; i < tree[v].size(); i++)
		{
			while(j < tree[v * 2].size() && tree[v * 2][j] <= tree[v][i])
			{
				j++;
			}
			iter1[v][i] = j - 1;
		}
		j = 0;
		for(int i = 0; i < tree[v].size(); i++)
		{
			while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] <= tree[v][i])
			{
				j++;
			}
			iter2[v][i] = j - 1;
		}
	}
}
int ans(int v, int l, int r, int al, int ar, int ind)
{
	if(l >= al && r <= ar)
	{
		return ind + 1;
	}
	else if(l <= ar && r >= al)
	{
		if(ind == -1)
		{
			return 0;
		}
		return ans(v * 2, l, (r + l) / 2, al, ar, iter1[v][ind]) + 
		ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, iter2[v][ind]);
	}
	return 0;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	tree.resize(4 * n);
	iter1.resize(4 * n);
	iter2.resize(4 * n);
	p.resize(n);
	vector <int> vals(n), pref(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
		vals[p[i]]++;
	}
	build(1, 0, n - 1);
	for(int i = 0; i < n; i++)
	{
		pref[i] = vals[i];
		if(i != 0)
		{
			pref[i] += pref[i - 1];
		}
	}
	for(int i = 0; i < q; i++)
	{
		int l, r, d, u;
		cin >> l >> d >> r >> u;
		l--;
		r--;
		d--;
		u--;
		int sum = 0;
		if(d != 0)
		{
			sum += pref[d - 1] * (pref[d - 1] - 1) / 2;
		}
		sum += (n - pref[u]) * (n - pref[u] - 1) / 2;
		sum += l * (l - 1) / 2;
		sum += (n - r - 1) * (n - r - 2) / 2;
		int l1 = -1, r1 = tree[1].size();
		while(r1 - l1 > 1)
		{
			int midd = (r1 + l1) / 2;
			if(tree[1][midd] <= d - 1)
			{
				l1 = midd;
			}
			else
			{
				r1 = midd;
			}
		}
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
		if(l != 0)
		{
			cnt1 = ans(1, 0, n - 1, 0, l - 1, l1);
		}
		if(r != n - 1)
		{
			cnt2 = ans(1, 0, n - 1, r + 1, n - 1, l1);
		}
		l1 = -1, r1 = tree[1].size();
		while(r1 - l1 > 1)
		{
			int midd = (r1 + l1) / 2;
			if(tree[1][midd] <= u)
			{
				l1 = midd;
			} 
			else
			{
				r1 = midd;
			}
		}
		if(l != 0)
		{
			cnt3 = l - ans(1, 0, n - 1, 0, l - 1, l1);
		}
		if(r != n - 1)
		{
			cnt4 = n - r - 1 - ans(1, 0, n - 1, r + 1, n - 1, l1);
		}
		sum -= cnt1 * (cnt1 - 1) / 2;
		sum -= cnt2 * (cnt2 - 1) / 2;
		sum -= cnt3 * (cnt3 - 1) / 2;
		sum -= cnt4 * (cnt4 - 1) / 2;
		sum = n * (n - 1) / 2 - sum;
		cout << sum << "\n";
	}
	return 0;
}