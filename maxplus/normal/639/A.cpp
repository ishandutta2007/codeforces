#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>
#include <unordered_map>
#include <ctime>

#define int long long

using namespace std;

const int maxsz = 8;

struct node
{
	int val, mod;
	node() { val = 0, mod = 0; }
	node(int v) { val = v, mod = 0; }
};

struct tree
{
	vector<node> arr;
	tree() { arr.resize(2 * maxsz); }

	void push_mod(int ver)
	{
		arr[ver * 2].mod += arr[ver].mod;
		arr[ver * 2 + 1].mod += arr[ver].mod;
		arr[ver].val += arr[ver].mod;
		arr[ver].mod = 0;
	}

	int getval(int ver)
	{
		return arr[ver].val + arr[ver].mod;
	}

	void add(int ver, int l, int r, int x, int y, int val)
	{
		if (x > r || y < l)
			return;
		if (l >= x && r <= y)
		{
			arr[ver].mod += val;
			return;
		}
		int m = (l + r) / 2;
		push_mod(ver);
		add(ver * 2, l, m, x, y, val);
		add(ver * 2 + 1, m + 1, r, x, y, val);
		arr[ver].val = min(getval(ver * 2), getval(ver * 2 + 1));
	}

	int get(int ver, int l, int r, int x, int y)
	{
		if (x > r || y < l)
			return 999999;
		if (l >= x && r <= y)
			return getval(ver);
		int m = (l + r) / 2;
		push_mod(ver);
		return min(get(ver * 2, l, m, x, y), get(ver * 2 + 1, m + 1, r, x, y));
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < q; i++)
	{
		int t, id;
		cin >> t >> id;
		if (t == 1)
		{
			s.insert(a[id - 1]);
			if (s.size() > k)
				s.erase(s.begin());
		}
		else
		{
			bool qq = false;
			for (auto el : s)
			{
				if (el == a[id - 1])
					qq = true;
			}
			if (qq)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}