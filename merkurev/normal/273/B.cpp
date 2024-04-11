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

map <int, int> m;
int getId(int x)
{
	if (m.count(x) == 0)
	{
		int sz = m.size();
		m[x] = sz;
	}
	return m[x];
}

const int maxn = (int) 2e5 + 100;
vector <int> ys[maxn];

int mod;

void solve()
{
	int n;
	scanf("%d", &n);
	for (int it = 0; it < 2; it++)
	{
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			x = getId(x);
			ys[x].push_back(i);
		}
	}
	scanf("%d", &mod);
	long long ans = 1;
	int sz = (int) m.size();
	for (int it = 0; it < sz; it++)
	{
		int cur = (int) ys[it].size();
		sort(ys[it].begin(), ys[it].end() );
		long long empty = cur;
		for (int i = 0; i < cur; i++)
		{
			if (i < cur - 1 && ys[it][i] == ys[it][i + 1] )
			{
				i++;
				long long x = (empty * (empty - 1) / 2) % mod;
				ans = (ans * x) % mod;
				empty -= 2;
			}
			else
			{
				ans = (ans * empty) % mod;
				empty--;
			}
		}
	}
	printf("%lld\n", ans);
}


int main(int , char **)
{
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}