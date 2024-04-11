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

int n;

#ifdef INTERACTOR
mt19937 rng(42);
char int_ar[300];
#endif

int asked = 0;
int ask(int l, int r)
{
	asked++;
	int res;
#ifdef INTERACTOR
	if (rng() % 2)
	{
		for (int i = 0; i < r; ++i)
			int_ar[i] ^= 1;
	}
	else
	{
		for (int i = l - 1; i < n; ++i)
			int_ar[i] ^= 1;
	}
	res = 0;
	For(i, n)
		res += int_ar[i];
#else
	cout << '?' << ' ' << l << ' ' << r << endl;
	cin >> res;
	if (res == -1)
		exit(0);
#endif
	return res;
}

void answer(vector<char>& res)
{
#ifdef INTERACTOR
	For(i, n)
		if (int_ar[i] != res[i])
			throw;
#else
	cout << '!' << ' ';
	for (auto e : res)
		cout << (char)('0' + e);
	cout << endl;
#endif
}

int get_prefix(int r, int t, int first)
{
	if (r == n)
		return t;
	if (r % 2 == 1)
	{
		int new_t;
		while (true)
		{
			ask(r + 1, n);
			new_t = ask(r + 1, n);
			if (new_t != t)
				break;
		}
		while (true)
		{
			ask(r + 1, n);
			if (ask(r + 1, n) == t)
				break;
		}
		return (r + t - new_t) / 2;
	}
	int new_t;
	while (true)
	{
		ask(r + 1, n);
		new_t = ask(r + 1, n);
		if (new_t != t)
			break;
		if (get_prefix(1, new_t, first) != first)
			break;
	}
	if (new_t != t)
	{
		while (true)
		{
			ask(r + 1, n);
			if (ask(r + 1, n) == t)
				break;
		}
	}
	else
	{
		while (true)
		{
			ask(r + 1, n);
			ask(r + 1, n);
			if (get_prefix(1, new_t, first) == first)
				break;
		}
	}
	return (r + t - new_t) / 2;
}

void solve()
{
	int t;
	cin >> n;

#ifdef INTERACTOR
	t = 0;
	For(i, n)
	{
		int_ar[i] = rng() % 2;
		t += int_ar[i];
	}
#else
	cin >> t;
#endif

	vector<char> res(n);
	res[0] = get_prefix(1, t, 0);
	for (int i = 1; i < n; ++i)
		res[i] = get_prefix(i + 1, t, res[0]);
	for (int i = n - 1; i > 0; --i)
		res[i] -= res[i - 1];
	answer(res);
#ifdef LOCAL
#ifdef INTERACTOR
	cout << asked;
#else
	cin >> n;
#endif
#endif
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
#ifdef INTERACTOR
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}