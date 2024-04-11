#include<bits/stdc++.h>
using namespace std;
vector <int> tree;
void update(int v, int l, int r, int ind)
{
	if(l == r){
		tree[v]++;
		return;
	}
	tree[v]++;
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	tree.resize(4 * n);
	vector <int> left1(n), a(n);
	vector <vector <pair <int, int> > > queries(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	vector <int> ansq(q, 0);
	for(int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		r = n - r - 1;
		if(l > r)
		{
			continue;
		}
		queries[r].push_back({l, i});
	}
	for(int i = 0; i < n; i++)
	{
		left1[i] = -1;
		if(a[i] <= i)
		{
		int l = -1, r = i + 1;
		while(r - l > 1){
			int midd = (r + l) / 2;
			int t = ans(1, 0, n - 1, midd, i);
			if(t >= i - a[i])
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		if(l != -1)
		{
			left1[i] = l;
			update(1, 0, n - 1, l);
		}
		}	
		for(int j = 0; j < queries[i].size(); j++)
		{
			int l = queries[i][j].first;
			int ind = queries[i][j].second;
			ansq[ind] = ans(1, 0, n - 1, l, i);
		}
	}
	for(int i = 0; i < q; i++)
	{
		cout << ansq[i] << "\n";
	}
	return 0;
}