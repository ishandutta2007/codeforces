#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > tree;
vector <vector <int> > iterleft, iterright;
vector <pair <int, int> > x;
void build(int v, int l, int r)
{
	if(l == r){
		tree[v].push_back(x[l].second);
		iterleft[v].resize(1);
		iterright[v].resize(1);
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		int j = 0;
		for(int i = 0; i < tree[v * 2].size(); i++)
		{
			while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] <= tree[v * 2][i])
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
		iterleft[v].resize(tree[v].size());
		iterright[v].resize(tree[v].size());
		int iter1 = 0, iter2 = 0;
		for(int i = 0; i < tree[v].size(); i++)
		{
			while(iter1 < tree[v * 2].size() && tree[v * 2][iter1] <= tree[v][i])
			{
				iter1++;
			}
			while(iter2 < tree[v * 2 + 1].size() && tree[v * 2 + 1][iter2] <= tree[v][i])
			{
				iter2++;
			}
			iterleft[v][i] = iter1 - 1;
			iterright[v][i] = iter2 - 1;
		}
	}
}
int sum(int v, int l, int r, int al, int ar, int ind)
{
	if(ind == -1)
	{
		return 0;
	}
	if(ind == tree[v].size())
	{
		ind  = tree[v].size() -1;
	}
	if(l >= al && r <= ar)
	{
		return ind + 1;
	}
	else if(l <= ar && r >= al )
	{
		return sum(v * 2, l, (r + l) / 2, al, ar, iterleft[v][ind]) + sum(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, iterright[v][ind]);
	}
	return 0;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	tree.resize(4 * n);
	iterleft.resize(4 * n);
	iterright.resize(4 * n);
	x.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin(), x.end());
	build(1, 0, n - 1);
	while(m--)
	{
		int k;
		cin >> k;
		vector <int> p(k);
		for(int i = 0; i < k; i++)
		{
			cin >> p[i];
		}
		int ans = n;
		int l1 = lower_bound(x.begin(), x.end(), make_pair(p[0], 0)) - x.begin();
		int l2 = lower_bound(tree[1].begin(), tree[1].end(), p[0]) - tree[1].begin();
		l2--;
		if(l1 != 0 && l2 != -1)
		{
			ans -= sum(1, 0, n - 1, 0, l1 - 1, l2);
		}
		for(int i = 0; i < k - 1; i++)
		{
			int l1 = lower_bound(x.begin(), x.end(),make_pair(p[i] + 1, 0)) - x.begin();
			int l2 = lower_bound(x.begin(), x.end(), make_pair(p[i + 1], 0)) - x.begin();
			l2--;
			int t1 = lower_bound(tree[1].begin(), tree[1].end(), p[i + 1]) - tree[1].begin();
			t1--;
			if(l1 <= l2 && t1 >= 0)
			{
				ans -= sum(1, 0, n - 1, l1, l2, t1);
			}
		}
		l1 = lower_bound(x.begin(), x.end(), make_pair(p[k - 1] + 1, 0)) - x.begin();
		ans -= n - l1;
		cout << ans << "\n";
	}
	return 0;
}