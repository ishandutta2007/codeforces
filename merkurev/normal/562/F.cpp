#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long int int64;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int N = (int)1e6;
const int A = 26;

int n;
int size;
int nv[N][A];

int id;
int type;
int len;
char buf[N];

vector<int> inds[N][2];

void add(int v, int pos)
{
	if (pos == len)
	{
		inds[v][type].push_back(id);
		return;
	}

	int c = (int)(buf[pos] - 'a');
	int n1 = nv[v][c];
	if (n1 == -1)
		nv[v][c] = size++;

	add(nv[v][c], pos + 1);
}

int64 ans;
vector<pair<int, int> > ans_list;
vector<int> list[2];

pair<int, int> calc(int v, int h)
{
	pair<int, int> cur_p;

	for (int i = 0; i < A; i++)
	{
		int n1 = nv[v][i];
		if (n1 == -1)
			continue;
		pair<int, int> p = calc(n1, h + 1);
		cur_p.first += p.first;
		cur_p.second += p.second;
	}

	cur_p.first += inds[v][0].size();
	cur_p.second += inds[v][1].size();

	for (int t = 0; t < 2; t++)
		for (int x : inds[v][t])
			list[t].push_back(x);

	int cnt = min(cur_p.first, cur_p.second);
	for (int i = 0; i < cnt; i++)
	{
		ans += (int64)h;
		int x1 = list[0].back();
		list[0].pop_back();
		int x2 = list[1].back();
		list[1].pop_back();
		ans_list.push_back({x1, x2});
	}

	return {cur_p.first - cnt, cur_p.second - cnt};
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	for (int i = 0; i < N; i++)
		for (int j = 0; j < A; j++)
			nv[i][j] = -1;

	size = 1;
	scanf("%d", &n);

	for (int t = 0; t < 2; t++)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s", buf);
			len = strlen(buf);
			type = t;
			id = i;
			add(0, 0);
		}
	}

	calc(0, 0);

	printf("%lld\n", ans);
	for (auto p : ans_list)
		printf("%d %d\n", p.first + 1, p.second + 1);

	return 0;
}