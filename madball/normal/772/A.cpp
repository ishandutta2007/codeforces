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

#define ll long long
#define ld double

using namespace std;

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

#pragma endregion
const double eps = 1e-10;
bool eq(double a, double b) {
	return abs(b - a) < eps;
}

bool gr(double a, double b) {
	return a > b && !eq(a, b);
}

void solve()
{
	int n, p;
	scanf("%d%d", &n, &p);
	vector<pair<int, int> > arr(n);
	ll a_sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
		a_sum += arr[i].first;
	}
	if (p >= a_sum) {
		printf("-1");
		return;
	}
	double l = 0;
	double r = 1e15;
	for (int iter = 0; iter < 200; iter++) {
		double t = (l + r) / 2;
		double sum = 0;
		for (int i = 0; i < n; i++) {
			if (gr(arr[i].first * t, arr[i].second))
				sum += arr[i].first * t - arr[i].second;
		}
		if (!gr(sum, t * p))
			l = t;
		else
			r = t;
	}
	printf("%.7lf", l);
}

int main()
{
#ifdef ALEX
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}