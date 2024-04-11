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

const int MAXN = (int)5e5 + 5;

inline int f(int x)
{
	return x & (-x);
}

struct Fenvick
{
	lint ar[MAXN];
	Fenvick() {}
	void add(int i, lint val)
	{
		for (; i < MAXN; i += f(i + 1))
			ar[i] += val;
	}
	lint get(int i)
	{
		lint res = 0;
		for (; i >= 0; i -= f(i + 1))
			res += ar[i];
		return res;
	}
} fen;

void solve()
{
	multiset<lint> ms;
	int q;
	scanf("%d", &q);
	vector<lint> qu(q);
	vector<lint> compress(q);
	For(i, q)
	{
		char c;
		lint x;
		scanf(" %c %lld", &c, &x);
		qu[i] = c == '+' ? x : -x;
		compress[i] = x;
	}
	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	For(i, q)
	{
		fen.add(lower_bound(all(compress), abs(qu[i])) - compress.begin(), qu[i]);
		if (qu[i] > 0)
			ms.insert(qu[i]);
		else
			ms.erase(ms.lower_bound(-qu[i]));
		if (ms.empty())
		{
			printf("0\n");
			continue;
		}
		int res = 0;
		lint cur = *ms.begin();
		while (true)
		{
			auto it = ms.lower_bound(cur * 2 + 1);
			if (it == ms.end())
				break;
			cur = *it;
			int ind = lower_bound(all(compress), cur) - compress.begin();
			if (cur > fen.get(ind - 1) * 2)
				++res;
			cur = fen.get(ind);
		}
		printf("%d\n", sz(ms) - 1 - res);
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