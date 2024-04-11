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
	int len, n, k;
	cin >> n >> len >> k;

	vector<int> ar(n);
	For(i, n)
		cin >> ar[i];
	vector<int> diff(n - 1);
	For(i, n - 1)
		diff[i] = ar[i + 1] - ar[i] - 1;

	int cur_len = ar.back() - ar.front() + 1;
	int cur_seg = 1;
	sort(all(diff));
	while (!diff.empty() && cur_seg < k)
	{
		++cur_seg;
		cur_len -= diff.back();
		diff.pop_back();
	}
	cout << cur_len;
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