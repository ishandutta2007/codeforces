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
//no print end

const ll inf = 1e15;

bool check(ll x, ll y, ll p, ll q, ll k) {
	if (k * q < y)
		return false;
	if (k * p < x)
		return false;
	return k * q - y >= k * p - x;
}

void solve()
{
	ll x, y, p, q;
	scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
	ll mx = 2e9 + 1;
	ll l = 0;
	ll r = mx;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(x, y, p, q, mid))
			r = mid;
		else
			l = mid + 1;
	}
	if (l == mx)
		printf("-1\n");
	else
		printf("%lld\n", l * q - y);
}

int main()
{
#ifdef ALEX
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();	
	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}