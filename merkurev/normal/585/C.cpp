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
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;
/*
const int K = 20;
bool ans[K][K];

struct State
{
	int a, b, c, d;
	State() : a(1), b(), c(), d(1) {}
	State(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}

	int sum()
	{
		return a + b + c + d;
	}
	State turnL()
	{
		return State(a + c, b + d, c, d);
	}
	State turnR()
	{
		return State(a, b, c + a, b + d);
	}

	void mark()
	{
		ans[a + c][b + d] = true;
	}
	void eprint()
	{
		eprintf("%d %d\n", a + c, b + d);
	}
};


void dfs(State s)
{
	if (s.sum() >= K)
		return;
	s.mark();
	dfs(s.turnL() );
	dfs(s.turnR() );
}
*/
vector <pair<int, long long> > ans;

void solve(long long x, long long y)
{
	while (x != 0 && y != 0)
	{
		if (x > y)
		{
			ans.push_back(make_pair(0, x / y) );
			x %= y;
		}
		else
		{
			ans.push_back(make_pair(1, y / x) );
			y %= x;
		}
	}
	if (x + y != 1)
	{
		printf("Impossible\n");
		return;
	}
	ans.back().second--;
	for (auto it : ans)
		if (it.second != 0)
			printf("%lld%c", it.second, 'A' + it.first);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	long long x, y;
	scanf("%lld%lld", &x, &y);
	solve(x, y);
	return 0;
/*
	State start = State();
	dfs(start);


	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
			eprintf(ans[i][j] ? "+" : "-");
		eprintf("\n");
	}

	return 0;
*/

}