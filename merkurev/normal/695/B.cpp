#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
#define debug_flag true
#else
#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
	string name = it -> substr((*it)[0] == ' ', it -> length());
	if (isalpha(name[0]))
		cerr << name  << " = " << a << " ";
	else
		cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42;
#endif

typedef long long int int64;

const int N = 1005;
const int M = 30005;
const int INF = (int)2e9 + 100;

struct Edge
{
	int a, b, c;
	Edge() : a(), b(), c() {}
	Edge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

int n, m;
int s, t;
vector<int> graph[M];
Edge e_list[M];

bool used[M];
int par_v[M];
int par_e[M];

bool blocked[M];

bool is_bridge[M];
int timer;
int t_in[N], f_up[M];
bool br_used[M];

int path_s;
int path[M];

void go_dfs(int v)
{
	used[v] = true;
	if (v == t)
		return;
	for (int e_id : graph[v])
	{
		if (blocked[e_id])
			continue;
		int to = (e_list[e_id].a + e_list[e_id].b - v);
		if (used[to])
			continue;
		par_v[to] = v;
		par_e[to] = e_id;
		go_dfs(to);
	}
}

void find_path()
{
	vector<int> e_path;
	fill(used, used + n, false);
	fill(par_e, par_e + n, -1);
	fill(par_v, par_v + n, -1);
	go_dfs(s);
	path_s = 0;
	if (used[t])
	{
		for (int i = t; i != s; i = par_v[i])
			path[path_s++] = par_e[i];
	}
}

void br_dfs(int v, int pr_e)
{
	br_used[v] = true;
	t_in[v] = timer;
	f_up[v] = timer;
	timer++;
	
	for (int e_id : graph[v])
	{
		if (blocked[e_id])
			continue;
		int to = (e_list[e_id].a + e_list[e_id].b - v);
		if (e_id == pr_e)
			continue;
		if (br_used[to])
			f_up[v] = min(f_up[v], t_in[to]);
		else
		{
			br_dfs(to, e_id);
			if (f_up[to] > t_in[v])
				is_bridge[e_id] = true;
			f_up[v] = min(f_up[v], f_up[to]);
		}
	}
}

pair<int, int> solve1()
{
	find_path();
	fill(br_used, br_used + n, false);
	fill(is_bridge, is_bridge + m, false);
	timer += 146;
	br_dfs(s, -1);
	pair<int, int> ans = make_pair(INF, -1);
	for (int i = 0; i < path_s; i++)
	{
		int e_id = path[i];
		if (is_bridge[e_id])
			ans = min(ans, make_pair(e_list[e_id].c, e_id));
	}
	return ans;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	s--;
	t--;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		e_list[i] = Edge(a, b, c);
		graph[a].push_back(i);
		graph[b].push_back(i);
	}

	find_path();
	vector<int> cur_path;
	for (int i = 0; i < path_s; i++)
		cur_path.push_back(path[i]);

	if (!used[t])
	{
		printf("0\n0\n");
		return 0;
	}

	pair<int, int> ans1 = solve1(), ans = make_pair(INF, -1);

	if (ans.first != INF)
	{
		printf("%d\n1\n%d\n", ans.first, ans.second + 1);
		return 0;
	}

	int fa, fb;
	for (int e_id : cur_path)
	{
		blocked[e_id] = true;
		pair<int, int> solve_p = solve1();
		if (solve_p.first != INF)
		{
			int cur_ans = solve_p.first + e_list[e_id].c;
			if (cur_ans < ans.first)
			{
				ans = make_pair(cur_ans, -1);
				fa = e_id;
				fb = solve_p.second;
			}
		}
		blocked[e_id] = false;
	}

	if (ans1.first < ans.first)
	{
		printf("%d\n1\n%d\n", ans1.first, ans1.second + 1);
		return 0;
	}
	else if (ans.first == INF)
		printf("-1\n");
	else
	{
		printf("%d\n", ans.first);
		printf("2\n%d %d\n", fa + 1, fb + 1);
	}
	return 0;
}