#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int pow2 = (1 << 20);
const int N = pow2;
const int INF = (int)1e9;

struct IntervalTree
{
	int min_val[pow2 * 2];

	IntervalTree()
	{
		fill(min_val, min_val + pow2 * 2, INF);
	}

	void set(int pos, int new_val)
	{
		pos += pow2;
		min_val[pos] = new_val;
		pos /= 2;
		while (pos >= 1)
		{
			min_val[pos] = min(min_val[pos * 2], min_val[pos * 2 + 1]);
			pos /= 2;
		}
	}

	int get_min(int a, int b)
	{
		return get_min(1, 0, pow2 - 1, a, b);
	}

	int get_min(int v, int l, int r, int a, int b)
	{
		if (l > b || r < a)
			return INF;
		if (a <= l && r <= b)
			return min_val[v];
		int m = (l + r) / 2;
		return min(get_min(v * 2, l, m, a, b),
				get_min(v * 2 + 1, m + 1, r, a, b));
	}
};

struct Query
{
	int l, r, ind;
	Query() : l(), r(), ind() {}
	Query(int _l, int _r, int _ind) : l(_l), r(_r), ind(_ind) {}

	bool operator < (Query other) const
	{
		return r < other.r;
	}

	void print()
	{
		printf("l = %d r = %d ind = %d\n", l, r, ind);
	}
};

int n, m;
int list[N];
vector<Query> query_list;
IntervalTree tree;
int ans[N];

void scan()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);
	query_list.resize(m);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		query_list[i] = Query(l, r, i);
	}
	sort(query_list.rbegin(), query_list.rend());
}

void solve()
{
	map<int, int> last_pos;

	for (int r = 0; r < n; r++)
	{
		if (last_pos.count(list[r]) == 1)
			tree.set(last_pos[list[r]], r - last_pos[list[r]]);
		last_pos[list[r]] = r;

		while (!query_list.empty())
		{
			Query q = query_list.back();
			if (q.r > r)
				break;
			ans[q.ind] = tree.get_min(q.l, q.r);
			if (ans[q.ind] == INF)
				ans[q.ind] = -1;
			query_list.pop_back();
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scan();
	solve();
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	return 0;
}