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

void solve()
{
	string s;
	cin >> s;
	int n = sz(s);
	bool succ = false;
	For(i, sz(s)) For(j, i)
		if (s[i] != s[j] && (n % 2 == 0 || i != (n / 2) && j != (n / 2)))
			succ = true;
	if (sz(s) <= 3)
		succ = false;
	if (!succ)
	{
		cout << "Impossible\n";
		return;
	}
	
	For(i, n - 1)
	{
		succ = true;
		bool succ2 = false;
		For(j, n)
		{
			int pos1 = (i + 1 + j) % n;
			int pos2 = (i + n - j) % n;
			if (s[pos1] != s[pos2])
				succ = false;
			if (s[pos1] != s[j])
				succ2 = true;
		}
		if (succ && succ2)
		{
			cout << "1\n";
			return;
		}
	}
	cout << "2\n";
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