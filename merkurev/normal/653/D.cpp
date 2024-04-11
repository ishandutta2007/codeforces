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

struct Edge
{
	int v, to, flow, max_flow, next;
	Edge() : v(), to(), flow(), max_flow(), next() {}
	Edge(int _v, int _to, int _max_flow, int _next) :
		v(_v), to(_to), flow(0), max_flow(_max_flow), next(_next) {}
};

struct IEdge
{
	int a, b, c;
	IEdge() : a(), b(), c() {}
	IEdge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

const int N = (int)1e5;
const double MAX_W = 1e7;
const int INF = (int)1e9;

int n, m, x;
IEdge i_list[N];

int s, t;
int v_cnt;
int g[N], buf_g[N];
int dist[N];

vector<Edge> e_list;

void add_e(int v, int to, int max_flow)
{
	e_list.push_back(Edge(v, to, max_flow, g[v]));
	g[v] = (int)e_list.size() - 1;

	e_list.push_back(Edge(to, v, 0, g[to]));
	g[to] = (int)e_list.size() - 1;
}

bool bfs()
{
	fill(dist, dist + v_cnt, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = g[v]; i != -1; i = e_list[i].next)
		{
			Edge e = e_list[i];
			int can = e.max_flow - e.flow;
			if (can == 0)
				continue;
			if (dist[e.to] > dist[v] + 1)
			{
				dist[e.to] = dist[v] + 1;
				q.push(e.to);
			}
		}
	}
	return dist[t] != INF;
}

int dfs(int v, int flow)
{
	if (v == t || flow == 0)
		return flow;
	for (int &i = g[v]; i != -1; i = e_list[i].next)
	{
		Edge e = e_list[i];
		
		int can = e.max_flow - e.flow;
		if (dist[e.to] != dist[v] + 1 || can == 0)
			continue;
		int push = dfs(e.to, min(flow, can));
		if (push == 0)
			continue;

		e_list[i].flow += push;
		e_list[i ^ 1].flow -= push;
		return push;
	}
	return 0;
}

bool can_solve(double w)
{
	v_cnt = n;
	s = 0;
	t = n - 1;
	fill(g, g + v_cnt, -1);
	
	e_list.clear();
	for (int i = 0; i < m; i++)
	{
		int a = i_list[i].a;
		int b = i_list[i].b;
		int c = i_list[i].c;
		int real_c = (int)(min((double)c / w, MAX_W));

		add_e(a, b, real_c);
	}

	dbg(v_cnt, s, t);
	for (auto e : e_list)
		dbg(e.v, e.to, e.flow, e.max_flow, e.next);

	int flow = 0;
	while (bfs())
	{
		copy(g, g + v_cnt, buf_g);
		while (true)
		{
			int push = dfs(s, INF);
			if (push == 0)
				break;
			flow += push;
		}
		copy(buf_g, buf_g + v_cnt, g);
	}
	return flow >= x;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		i_list[i] = IEdge(a, b, c);
	}


	double l = 0;
	double r = 1e7;
	for (int it = 0; it < 200; it++)
	{
		double mid = (l + r) / 2;
		if (can_solve(mid))
			l = mid;
		else
			r = mid;
	}

	printf("%.10lf\n", l * x);

	return 0;
}