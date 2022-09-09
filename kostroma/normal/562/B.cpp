#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstring>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <complex>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define all(a) a.begin(), a.end()

typedef long long li;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef long double ld;

void precalc();
void solve();
int main() {
#ifdef VKCUP
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	cout.precision(20);
	cout << fixed;
	cout.sync_with_stdio(0);
	cin.tie(0);
	clock_t start = clock();

	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
#ifdef VKCUP
	cerr << endl << (clock() - start) / 1.0 / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}

void precalc() {

}

const int C = 1000001;

vector<int> dels[C];

void solve() {

	int n;
	scanf("%d", &n);
	//n = 1000000;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		//a[i] = i + 1;

		/*int d = a[i];
		for (int cur = 2 * d; cur < C; cur += d) {
			dels[cur].push_back(d);
		}*/
	}

	vector<int> dp(C, 0);
	for (int i = n - 1; i >= 0; --i) {
		dp[a[i]] = max(dp[a[i]], 1);

		int d = a[i];
		for (int cur = d * 2; cur < C; cur += d) {
			dp[a[i]] = max(dp[a[i]], dp[cur] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < C; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";

}