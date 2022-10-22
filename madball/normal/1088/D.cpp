#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <string>
#include <random>

using namespace std;

typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n)  for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
//#define INTERACTOR
#endif

bool swapped;
lint int_a, int_b;
mt19937 rng(43);

bool ask(lint x, lint y)
{
#ifdef INTERACTOR
	return (int_a ^ x) < (int_b ^ y);
#else
	cout << '?' << ' ' << x << ' ' << y << endl;
	int ans;
	cin >> ans;
	return ans == -1;
#endif
}

void answer(lint a, lint b)
{
#ifdef INTERACTOR
	if (a != int_a || b != int_b)
		throw;
#else
	cout << '!' << ' ' << a << ' ' << b << endl;
#endif
}

void solve() {
#ifdef INTERACTOR
	int_a = rng() & ((1 << 30) - 1);
	int_b = rng() & ((1 << 30) - 1);
#endif
	swapped = false;
	swapped = ask(0, 0);
	lint a = 0, b = 0;
	for (int bit = 29; bit >= 0; --bit)
	{
		bool u = ask((swapped ? b : a) ^ (1ll << bit), (swapped ? a : b)), v = ask((swapped ? b : a), (swapped ? a : b) ^ (1ll << bit));
		if (u == v)
		{
			(swapped ? b : a) ^= (1ll << bit);
			swapped = u;
		}
		else if (u)
		{
			a ^= (1ll << bit);
			b ^= (1ll << bit);
		}
	}
	answer(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef INTERACTOR
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}