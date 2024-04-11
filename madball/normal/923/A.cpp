//no print start
#pragma region Header
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <complex>
#include <bitset>
#include <random>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll, lint;
typedef long double ldouble;

#define sz(v) ((int) (v).size())
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define For(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()

#ifdef ALEX
#define eprintf(...) fprintf(stdout, __VA_ARGS__)
#define print_var(x) cout << #x << " = " << x << endl
#define print_array(arr, len) {cout << #arr << " = "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_iterable(it) {cout << #it << " = "; for(const auto& e : it) cout << e << ' '; cout << endl << endl;}
#define print_2d_array(arr, len1, len2) {\
		cout << #arr << ':' << endl;\
		for(int i = 0; i < len1; ++i, cout << endl) \
			for(int j = 0; j < len2; ++j)\
				cout << arr[i][j] << ' '; \
		cout << endl;\
	}
#define print_endl() cout << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) (void)0;
#define print_iterable(it) (void)0;
#define print_2d_array(arr, len1, len2) (void)0;
#define print_endl() (void)0
#endif

#define forn(var, count) for (int var = 0; var < count; var++)

template<class T>
string to_string(T arr, int len = 1e9) {
	stringstream ss;
	int i = 0;
	for (auto item : arr) {
		ss << item << ' ';
		if (++i == len)
			break;
	}
	return ss.str();
}

#ifdef ALEX
#define dbg(expr) cout << "[line " << __LINE__ << "] " << (#expr) << ": " << (expr) << endl;
#else
#define dbg(expr) (void) 0;
#endif

#pragma endregion
//no print end

const int maxn = 1e6 + 17;
int dv[maxn];
int best_start[maxn];

void init() {
	For(i, maxn)
		dv[i] = i;

	for (lint i = 2; i < maxn; i++) {
		if (dv[i] == i) {
			for (lint j = i * i; j < maxn; j += i) {
				dv[j] = i;
			}
		}
	}
}

int ga1(int x1) {
	int ans = x1;
	int x = x1;
	while (x > 1) {
		int d = dv[x];
		if (d < x1)
			ans = min(ans, x1 - d + 1);
		while (x % d == 0)
			x /= d;
	}
	return max(ans, 3);
}

void solve() {
	init();
	int n;
	scanf("%d", &n);
	for (int x1 = 1; x1 < maxn; x1++)
		best_start[x1] = ga1(x1);

	int ans = 1e9 + 7;
	int x = n;
	while (x > 1) {
		int d = dv[x];
		for (int i = n - d + 1; i <= n; i++)
			ans = min(ans, best_start[i]);
		while (x % d == 0)
			x /= d;
	}

	printf("%d", ans);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
#ifdef ALEX
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}