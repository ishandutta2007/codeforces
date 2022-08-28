#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int)2e5 + 100;
const int pow2 = (1 << 20);
const int INF = (int)1e9;

struct Event
{
	int x, type, ind;
	Event() : x(), type(), ind() {}
	Event(int a, int b, int c) : x(a), type(b), ind(c) {}
	bool operator < (const Event &e) const
	{
		if (x != e.x)
			return x < e.x;
		if (type != e.type)
			return type < e.type;
		return ind < e.ind;
	}
};

struct IntervalTree
{
	pair<int, int> val[pow2 * 2];

	IntervalTree()
	{
		for (int i = 0; i < pow2 * 2; i++)
			val[i] = make_pair(-INF, -INF);
	}

	void relax(int pos, pair<int, int> v)
	{
		pos += pow2;
		val[pos] = max(val[pos], v);
		pos /= 2;
		while (pos >= 1)
		{
			val[pos] = max(val[pos * 2], val[pos * 2 + 1]);
			pos /= 2;
		}
	}

	pair<int, int> get_max(int a, int b)
	{
		return get_max(1, 0, pow2 - 1, a, b);
	}

	pair<int, int> get_max(int v, int l, int r, int a, int b)
	{
		if (l > b || r < a)
			return {-INF, -INF};
		if (a <= l && r <= b)
			return val[v];
		int m = (l + r) / 2;
		return max(get_max(v * 2, l, m, a, b),
				get_max(v * 2 + 1, m + 1, r, a, b));
	}
};

int n, m;
int l[N], r[N];
int a[N], b[N], c[N];

int store_cnt;
int store[4 * N];
map<int, int> comp_mx;

void comp()
{
	for (int i = 0; i < n; i++)
	{
		store[store_cnt++] = l[i];
		store[store_cnt++] = r[i];
	}

	for (int i = 0; i < m; i++)
	{
		store[store_cnt++] = a[i];
		store[store_cnt++] = b[i];
	}

	sort(store, store + store_cnt);
	store_cnt = unique(store, store + store_cnt) - store;

	for (int i = 0; i < store_cnt; i++)
		comp_mx[store[i]] = i;

	for (int i = 0; i < n; i++)
	{
		l[i] = comp_mx[l[i]];
		r[i] = comp_mx[r[i]];
	}

	for (int i = 0; i < m; i++)
	{
		a[i] = comp_mx[a[i]];
		b[i] = comp_mx[b[i]];
	}
}

int rev(int x)
{
	return -x;
}

void change()
{
	for (int i = 0; i < n; i++)
	{
		l[i] = rev(l[i]);
		r[i] = rev(r[i]);
		swap(l[i], r[i]);
	}

	for (int i = 0; i < m; i++)
	{
		a[i] = rev(a[i]);
		b[i] = rev(b[i]);
		swap(a[i], b[i]);
	}
}

int ev_cnt;
Event ev_list[4 * N];
IntervalTree tree;

int64 ans;
int ans1, ans2;

void solve()
{
	ev_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		ev_list[ev_cnt++] = Event(l[i], -1, i);
		ev_list[ev_cnt++] = Event(r[i], 1, i);
	}
	for (int i = 0; i < m; i++)
		ev_list[ev_cnt++] = Event(a[i], 0, i);
	
	sort(ev_list, ev_list + ev_cnt);
	multiset<pair<int, int> > r_pos;

	for (int i = 0; i < ev_cnt; i++)
	{
		Event cur_ev = ev_list[i];

		if (cur_ev.type == -1)
		{
			r_pos.insert({r[cur_ev.ind], cur_ev.ind});
		}
		else if (cur_ev.type == 0)
		{
			int max_r = cur_ev.x;
			if (!r_pos.empty())
				max_r = r_pos.rbegin()->first;

			int64 cur_ans = (int64)c[cur_ev.ind] * (min(max_r, b[cur_ev.ind]) - a[cur_ev.ind]);
			if (cur_ans > ans)
			{
				ans = cur_ans;
				ans1 = r_pos.rbegin()->second;
				ans2 = cur_ev.ind;
			}
		}
		else
		{
			auto it = r_pos.find({r[cur_ev.ind], cur_ev.ind});
			r_pos.erase(it);
		}
	}
}

void solve2()
{
	ev_cnt = 0;
	for (int i = 0; i < n; i++)
		ev_list[ev_cnt++] = Event(l[i], 1, i);
	for (int i = 0; i < m; i++)
		ev_list[ev_cnt++] = Event(a[i], 0, i);
	sort(ev_list, ev_list + ev_cnt);
	
	for (int i = ev_cnt - 1; i >= 0; i--)
	{
		Event cur_ev = ev_list[i];
		if (cur_ev.type == 0)
		{
			auto max_len = tree.get_max(a[cur_ev.ind], b[cur_ev.ind]);
			int64 cur_ans = (int64)c[cur_ev.ind] * max_len.first;
			if (cur_ans > ans)
			{
				ans = cur_ans;
				ans1 = max_len.second;
				ans2 = cur_ev.ind;
			}
		}
		else
		{
			int ll = l[cur_ev.ind];
			ll = store[ll];
			int rr = r[cur_ev.ind];
			rr = store[rr];
			tree.relax(r[cur_ev.ind], {rr - ll, cur_ev.ind});
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &l[i], &r[i]);

	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);

	/*
	for (int i = 0; i < n; i++)
		printf("%d %d\n", l[i], r[i]);
	printf("\n");
	for (int i = 0; i < m; i++)
		printf("%d %d\n", a[i], b[i]);
	printf("\n");
	*/


	solve();
	change();

	solve();
	change();
	
	comp();	
	
	solve2();

	printf("%lld\n", ans);
	if (ans != 0)
		printf("%d %d\n", ans1 + 1, ans2 + 1);

	return 0;
}