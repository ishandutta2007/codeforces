#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

const int MAXN = (int)500010;
bool white[MAXN];
vector<int> graph[MAXN];

const string WHITE = "White\n";
const string DRAW = "Draw\n";

void solve()
{
	int n;
	cin >> n;
	For(i, n)
		graph[i].clear();
	For(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	string s;
	cin >> s;
	For(i, n)
		white[i] = s[i] == 'W';

	if (n < 3)
	{
		cout << DRAW;
		return;
	}
	if (n == 3)
	{
		if (white[0] + white[1] + white[2] == 2)
			cout << WHITE;
		else
			cout << DRAW;
		return;
	}
	bool succ = false;
	For(i, n)
	{
		if (sz(graph[i]) >= 4)
			succ = true;
		else if (sz(graph[i]) == 3)
		{
			if (white[i])
				succ = true;
			int adj_non_leaf = 0;
			for (auto e : graph[i])
			{
				if (white[e])
					succ = true;
				if (sz(graph[e]) > 1)
					++adj_non_leaf;
			}
			if (adj_non_leaf >= 2)
				succ = true;	
		}
		else if (sz(graph[i]) == 2)
		{
			if (white[i])
				succ = true;
		}
		int adj_white = 0;
		int adj_3 = 0;
		for (auto e : graph[i])
		{
			adj_white += white[e];
			adj_3 += sz(graph[e]) >= 3;
		}
		if (adj_white >= 2 || adj_3 >= 2)
			succ = true;
	}
	int leaves = 0, white_leaves = 0;
	For(i, n)
		if (sz(graph[i]) == 1)
		{
			++leaves;
			if (white[i])
				++white_leaves;
		}
	if (leaves == 3 && white_leaves == 1 && n >= 6 && n % 2 == 0)
		succ = true;
	if (leaves == 2 && white_leaves == 2 && n >= 5 && n % 2 == 1)
		succ = true;
    if (leaves == 4 && n >= 9 && n % 2 == 1)
        succ = true;
	if (succ)
		cout << WHITE;
	else
		cout << DRAW;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int t;
	cin >> t;
	For(test, t)
		solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}