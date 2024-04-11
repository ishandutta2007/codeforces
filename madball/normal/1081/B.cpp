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

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> ar(n);
	For(i, n)
	{
		cin >> ar[i].first;
		ar[i].second = i;
	}
	sort(all(ar));
	int t = 1;
	for (int i = 0; i < n;)
	{
		int j;
		for (j = i; j < n && ar[i].first == ar[j].first; ++j);
		int d = n - ar[i].first;
		if ((j - i) % d)
		{
			cout << "Impossible";
			return;
		}
		for (int k = i; k < j; ++k)
			ar[k].first = t + (k - i) / d;
		t += (j - i) / d;
		i = j;
	}
	sort(all(ar), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	cout << "Possible\n";
	for (auto e : ar)
		cout << e.first << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}