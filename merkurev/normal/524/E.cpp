#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int pow2 = (1 << 17);
const int INF = (int)2e9;

struct IntervalTree
{
	int val[pow2 * 2];
	set<int> s[pow2 * 2];

	IntervalTree()
	{
		for (int i = 0; i < 2 * pow2; i++)
		{
			val[i] = INF;
			s[i] = set<int> ();
		}
	}

	void add(int pos, int cval)
	{
		pos += pow2;
		s[pos].insert(cval);
		val[pos] = *s[pos].begin();
		pos /= 2;
		while (pos >= 1)
		{
			val[pos] = max(val[pos * 2], val[pos * 2 + 1]);
			pos /= 2;
		}
	}

	void rem(int pos, int cval)
	{
		pos += pow2;
		s[pos].erase(cval);
		if (s[pos].empty())
			val[pos] = INF;
		else
			val[pos] = *s[pos].begin();
		pos /= 2;
		while (pos >= 1)
		{
			val[pos] = max(val[pos * 2], val[pos * 2 + 1]);
			pos /= 2;
		}
	}

	int get_max(int a, int b)
	{
		return get_max(1, 0, pow2 - 1, a, b);
	}

	int get_max(int v, int l, int r, int a, int b)
	{
		if (l > b || r < a)
			return -INF;
		if (a <= l && r <= b)
			return val[v];
		int m = (l + r) / 2;
		return max(get_max(2 * v, l, m, a, b),
				get_max(2 * v + 1, m + 1, r, a, b));
	}
};

struct Query
{
	int x1, y1;
	int x2, y2;
	int id;

	Query() : x1(), y1(), x2(), y2(), id() {}
	Query(int _x1, int _y1, int _x2, int _y2, int _id) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), id(_id) {}

	bool operator < (const Query q) const
	{
		return y1 < q.y1;
	}
};

vector<bool> solve(int m, vector<pair<int, int> > pos_list, vector<Query> q_list)
{
	IntervalTree tree = IntervalTree();
	for (auto p : pos_list)
		tree.add(p.first, p.second);

	vector<vector<int> > need_rem(m + 1, vector<int> ());
	for (auto p : pos_list)
		need_rem[p.second].push_back(p.first);
	
	sort(q_list.rbegin(), q_list.rend());
	vector<bool> res (q_list.size());

	for (int cur_y = 1; cur_y <= m; cur_y++)
	{
		while (!q_list.empty())
		{
			auto q = q_list.back();
			if (q.y1 != cur_y)
				break;
			q_list.pop_back();
			int max_val = tree.get_max(q.x1, q.x2);
			if (max_val <= q.y2)
				res[q.id] = true;
		}

		for (int x : need_rem[cur_y])
			tree.rem(x, cur_y);
	}

	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	vector<pair<int, int> > pos_list(k);
	for (int i = 0; i < k; i++)
		scanf("%d%d", &pos_list[i].first, &pos_list[i].second);
	vector<Query> q_list(q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d%d", &q_list[i].x1, &q_list[i].y1, &q_list[i].x2, &q_list[i].y2);
		q_list[i].id = i;
	}
	
	auto res1 = solve(m, pos_list, q_list);

	for (int i = 0; i < k; i++)
		swap(pos_list[i].first, pos_list[i].second);
	for (int i = 0; i < q; i++)
	{
		swap(q_list[i].x1, q_list[i].y1);
		swap(q_list[i].x2, q_list[i].y2);
	}

	auto res2 = solve(n, pos_list, q_list);

	for (int i = 0; i < q; i++)
	{
		if (res1[i] || res2[i])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}