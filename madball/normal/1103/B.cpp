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

#ifdef LOCAL
//#define INTERACTOR
#endif

#ifdef INTERACTOR
lint int_a = 987654320;
bool int_first = true;
int cnt = 0;
#endif


bool ask(lint x, lint y)
{
#ifdef INTERACTOR
	return (x % int_a) >= (y % int_a);
#else
	char res;
	cout << '?' << ' ' << x << ' ' << y << endl;
	cin >> res;
	if (res == 'e')
		exit(0);
	return res == 'x';
#endif
}

void answer(lint a)
{
#ifdef INTERACTOR
	if (a != int_a)
		throw;
#else
	cout << '!' << ' ' << a << endl;
#endif
}

bool solve()
{
#ifdef INTERACTOR
	if (!int_first)
		return false;
	int_first = false;
#else
	string s;
	cin >> s;
	if (s != "start")
		return false;
#endif
	lint l = 0, r = 1;
	while (r != (1 << 30) && !ask(l, r))
	{
		l = r;
		r *= 2;
	}
	while (l + 1 < r)
	{
		lint m = (l + r) / 2;
		if (m % 2 == 0)
		{
			if (ask(m / 2, m))
				r = m;
			else
				l = m;
		}
		else
		{
			if (ask(m - 1, m))
				r = m;
			else
				l = m;
		}
	}
	answer(r);
	return true;
}

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	while (solve());
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}