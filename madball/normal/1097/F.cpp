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

const int MAXN = (int)1e5;
bitset<7001> ar[MAXN];

bool is_prime(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

void solve()
{
	vector<int> prime;
	for (int i = 2; i <= 7000; ++i)
		if (is_prime(i))
			prime.push_back(i);
	vector<int> good;
	for (int i = 1; i <= 7000; ++i)
	{
		bool succ = true;
		for (auto e : prime)
			if (i % e == 0 && i % (e * e) == 0)
				succ = false;
		if (succ)
			good.push_back(i);
	}
	vector<bitset<7001>> very_good(7001);
	for (int i = 1; i <= 7000; ++i)
	{
		for (auto e : good)
			if (i * e <= 7000)
				very_good[i].flip(i * e);
	}
	int q;
	scanf("%d", &q);
	scanf("%d", &q);
	For(qi, q)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x, v;
			scanf("%d %d", &x, &v);
			--x;
			ar[x].reset();
			for (int i = 1; i * i <= v; ++i)
				if (v % i == 0)
				{
					ar[x].flip(i);
					if (i * i != v)
						ar[x].flip(v / i);
				}
		}
		if (t == 2)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			--x;
			--y;
			--z;
			ar[x] = ar[y] ^ ar[z];
		}
		if (t == 3)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			--x;
			--y;
			--z;
			ar[x] = ar[y] & ar[z];
		}
		if (t == 4)
		{
			int x, v;
			scanf("%d %d", &x, &v);
			--x;
			cout << ((ar[x] & very_good[v]).count() % 2);
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}