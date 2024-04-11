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

#ifdef LOCAL
#define ALEX
#endif

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

lint div_up(lint x, lint k) {
	return (x + k - 1) / k;
}

#ifdef LOCAL
#define STRESS
#define STRESS_GEN
#endif

#ifdef STRESS_GEN
mt19937 rng(42);
#endif

void solve() {
	int n;
	lint x1, x2;
#ifdef STRESS_GEN
	n = 10;
	x1 = rng() % 100 + 1;
	x2 = rng() % 100 + 1;
#else
	scanf("%d%lld%lld", &n, &x1, &x2);
#endif
	vector<lint> arr(n);
	For(i, n)
#ifdef STRESS_GEN
		arr[i] = rng() % 50 + 1;
#else
		scanf("%lld", &arr[i]);
#endif
	set<pair<lint, int> > pwlow, pwmid, pwtop;
	For(i, n)
		pwlow.insert({ arr[i], i });

	vector<lint> when;
	for (auto it = pwlow.begin(); it != pwlow.end(); ++it)
		when.push_back(n - sz(when) - div_up(x2, it->first));
	vector<lint> when_pmax(n);
	For(i, n)
		when_pmax[i] = max(when[i], i ? when_pmax[i - 1] : 0);

	bool possible = false;
	for (int k = 1; k < n; ++k)
	{
		int k2 = -1;
		for (auto it = pwlow.lower_bound(make_pair(div_up(x1, k), 0)); it != pwlow.end() && (k == 1 ? true : it->first < div_up(x1, k - 1)); ++it)
			pwmid.insert(*it);
		for (auto it = pwmid.lower_bound(make_pair(div_up(x1, k), 0)); it != pwmid.end() && (k == 1 ? true : it->first < div_up(x1, k - 1)); ++it)
			pwlow.erase(*it);
		while (sz(pwmid) > k)
		{
			auto p = *pwmid.rbegin();
			pwtop.insert(p);
			pwmid.erase(p);
			if (p.first >= div_up(x2, sz(pwtop)))
				k2 = sz(pwtop);
		}
		if (sz(pwmid) == k && !pwlow.empty() && when_pmax[sz(pwlow) - 1] >= k)
		{
			For(i, sz(pwlow))
				if (when[i] >= k)
					k2 = sz(pwlow) - i + sz(pwtop);
		}
		if (sz(pwmid) == k && k2 != -1)
		{
			while (sz(pwtop) < k2)
			{
				pwtop.insert(*prev(pwlow.end()));
				pwlow.erase(prev(pwlow.end()));
			}
			while (sz(pwtop) > k2)
				pwtop.erase(pwtop.begin());
			possible = true;
			break;
		}
	}
	if (!possible)
	{
		printf("No");
#ifdef STRESS
		fflush(stdout);
		for (int mask = 1; mask + 1 < (1 << n); ++mask)
		{
			int k1 = 0, k2 = 0;
			lint mn1 = (int)1e9, mn2 = (int)1e9;
			For(i, n)
				if (mask & (1 << i))
				{
					++k1;
					mn1 = min(mn1, arr[i]);
				}
				else
				{
					++k2;
					mn2 = min(mn2, arr[i]);
				}
			if (mn1 >= div_up(x1, k1) && mn2 >= div_up(x2, k2))
				throw;
		}
#endif
		return;
	}
	printf("Yes\n");
	printf("%d %d\n", sz(pwmid), sz(pwtop));
	for (auto x : pwmid)
		printf("%d ", x.second + 1);
	printf("\n");
	for (auto x : pwtop)
		printf("%d ", x.second + 1);

#ifdef STRESS
	fflush(stdout);
	for (auto e : pwmid)
		if (e.first < div_up(x1, sz(pwmid)))
			throw;
	for (auto e : pwtop)
		if (e.first < div_up(x2, sz(pwtop)))
			throw;
#endif
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
#ifdef ALEX
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

#ifdef STRESS_GEN
	while (true)
#endif
	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}