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

const int N = (int)1e6 + 100;
const int64 INF = (int64)1e18;
const int64 SH = 1e9;

int n, k;
int64 b, c;
int64 t[N];
int64 ans;
int64 cost[N];

int64 get_cost(int64 len)
{
	assert(len % 5 == 0);
	return min(len * c, (len / 5) * b);
}

bool cmp(int a, int b1)
{
	if (cost[a] != cost[b1])
		return cost[a] < cost[b1];
	return a < b1;
}

int64 get_dx(int64 cur_t, int r)
{
	int64 cur_ans = 0;
	while (cur_t % 5 != r)
	{
		cur_t += 1;
		cur_ans += 1;
	}
	return cur_ans;
}

void try_solve(int r)
{
	int64 T = (int64)2e9 + r;

	for (int i = 0; i < n; i++)
	{
		int64 cur_t = t[i];
		int64 dx = get_dx(cur_t, r);
		int64 cur_cost = dx * c + get_cost(T - cur_t - dx);
		cost[i] = cur_cost;
		dbg(cost[i]);
	}

	set<int, decltype(&cmp)> s(&cmp);
	int64 cost_to_T = 0;
	for (int ptr = 0; ptr < n; ptr++)
	{
		s.insert(ptr);
		cost_to_T += cost[ptr];
		if ((int)s.size() == k + 1)
		{
			int bad_ind = (*s.rbegin());
			cost_to_T -= cost[bad_ind];
			s.erase(bad_ind);
		}
		
		int64 x = t[ptr] + get_dx(t[ptr], r);

		if ((int)s.size() == k)
		{
			dbg(k, cost_to_T, get_cost(T - x), T - x);
			int64 cur_ans = cost_to_T - get_cost(T - x) * k;
			dbg(cur_ans);
			ans = min(ans, cur_ans);
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d%d%lld%lld", &n, &k, &b, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &t[i]);
		t[i] += SH;
	}
	sort(t, t + n);
	
	ans = INF;
	for (int r = 0; r < 5; r++)
		try_solve(r);

	printf("%lld\n", ans);

	return 0;
}