#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
#define int long long
const int  CONST = 998244353;
struct dsu{
	vector <int> parent, rg, rang;
	dsu()
	{
		parent = rg = rang = {};
	}
	dsu(int n)
	{
		parent.resize(n);
		rg.resize(n);
		rang.resize(n);
		for(int i = 0; i < n; i++)
		{
			parent[i] = i, rang[i] = 0, rg[i] = i + 1;
		}
	}
	int get(int a)
	{
		if(parent[a] == a)
		{
			return a;
		}
		return parent[a] = get(parent[a]);
	}
	void unite(int a, int b)
	{
		a = get(a);
		b = get(b);
		if(a == b)
		{
			return;
		}
		if(rang[a] > rang[b])
		{
			swap(a, b);
		}
		rg[b] = max(rg[b], rg[a]);
		parent[a] = b;
		if(rang[a] == rang[b]){
			rang[b]++;
		}
	}
	bool same(int a, int b)
	{
		return get(a) == get(b);
	}
	int nxt(int a)
	{
		return rg[get(a)];
	}
};
vector <int> tree, a, b;
void build(int v, int l, int r)
{
	a[v] = 1;
	b[v] = 0;
	tree[v] = 0;
	if(l == r)
	{
		return;
	}
	int midd = (r + l) / 2;
	build(v * 2, l, midd);
	build(v * 2 + 1, midd + 1, r);
}
void push(int v, int l, int r)
{
	tree[v] = (tree[v] * a[v] + b[v] * (r - l + 1)) % CONST;
	if(r != l)
	{
		a[v * 2] = (a[v * 2] * a[v]) % CONST;
		a[v * 2 + 1] = (a[v * 2 + 1] * a[v]) % CONST;
		b[v * 2] = (b[v * 2] * a[v] + b[v]) % CONST;
		b[v * 2 + 1] = (b[v * 2 + 1] * a[v] + b[v]) % CONST;
	}
	a[v] = 1;
	b[v] = 0;
}
void change(int v, int l, int r, int al, int ar, int val)
{
	push(v, l, r);
	if(ar < l || al > r)
	{
		return;
	}
	if(al <= l && r <= ar)
	{
		if(val == 0)
		{
			a[v] = (a[v] * 2LL) % CONST;
			b[v] = (b[v] * 2LL) % CONST; 
		}
		else
		{
			b[v] = (b[v] + 1) % CONST;
		}
		push(v, l, r);
		return;
	}
	int midd = (r + l) / 2;
	change(v * 2, l, midd, al, ar, val);
	change(v * 2 + 1, midd + 1, r, al, ar, val);
	tree[v] = (tree[v * 2] + tree[v * 2 + 1]) % CONST;
}
int sum(int v, int l, int r, int al, int ar)
{
	push(v, l, r);
	if(al > r || ar < l)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	return sum(v * 2, l, (r + l) / 2 , al, ar) + sum(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
}
int n, q;
vector <vector <int> > qr;
vector <vector <int> > vx;
vector <vector <pair <int, int> > > seg;
vector <vector <bool> > used;
vector <dsu> d;
void update(int x, int l, int r)
{
	vector <int> Neww;
	int L = -1, R = seg[x].size();
	while(R - L > 1)
	{
		int midd = (R + L) / 2;
		if(seg[x][midd].first >= l)
		{
			R = midd;
		}
		else
		{
			L = midd;
		}
	}
	int i = R;
	while(i < seg[x].size())
	{
		if(seg[x][i].second > r)
		{
			break;
		}
		if(used[x][i])
		{
			i = d[x].nxt(i);
			continue;
		}
		Neww.push_back(i);
		i = d[x].nxt(i);
	}
	for(int i = 0; i < Neww.size(); i++)
	{
		change(1, 0, n, seg[x][Neww[i]].first, seg[x][Neww[i]].second, 1);
	}
	vector <int> a;
	a.push_back(l);
	for(int i = 0; i < Neww.size(); i++)
	{
		a.push_back(seg[x][Neww[i]].first - 1);
		a.push_back(seg[x][Neww[i]].second + 1);
	}
	a.push_back(r);
	for(int i = 0; i < a.size(); i += 2)
	{
		if(a[i] > a[i + 1])
		{
			continue;
		}
		change(1, 0, n, a[i], a[i + 1], 0);
	}
	for(int i = 0; i < Neww.size(); i++)
	{
		used[x][Neww[i]] = true;
		if(Neww[i] != 0 && used[x][Neww[i] - 1]) d[x].unite(Neww[i] - 1, Neww[i]);
		if(Neww[i] != seg[x].size() - 1 && used[x][Neww[i] + 1]) d[x].unite(Neww[i], Neww[i] + 1); 
	}
}
signed main()
{
	cin >> n >> q;
	vx.resize(n);
	seg.resize(n);
	used.resize(n);
	tree.resize(4 * n);
	a.resize(4 * n );
	b.resize(4 * n);
	int q1 = q;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			r--;
			x--;
			qr.push_back({l, r, x});
			vx[x].push_back(l);
			vx[x].push_back(r);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			qr.push_back({l, r});
		}
	}
	d.resize(n);
	for(int i = 0; i < n; i++)
	{
		sort(vx[i].begin(), vx[i].end());
		vx[i].resize(unique(vx[i].begin(), vx[i].end()) - vx[i].begin());
		for(int x = 0; x < vx[i].size(); x++)
		{
			seg[i].push_back({vx[i][x], vx[i][x]});
			if(x + 1 != vx[i].size())
			{
				if(vx[i][x + 1] - vx[i][x] != 1)
				{
					seg[i].push_back({vx[i][x] + 1, vx[i][x + 1] - 1});
				}
			}
		}
		used[i].assign(seg[i].size(), false);
		d[i] = dsu(seg[i].size());
	}
	build(1, 0, n);
	for(int i = 0; i < q1; i++)
	{
		if(qr[i].size() == 3)
		{
			update(qr[i][2], qr[i][0], qr[i][1]);
		}
		else
		{
			cout << sum(1 , 0, n, qr[i][0], qr[i][1]) % CONST << "\n";
		}
	}
	return 0;
}