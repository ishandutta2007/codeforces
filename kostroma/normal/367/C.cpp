#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
//void precalc();
clock_t start;
//int timer = 1;
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	//cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
    while (t--)
        solve();

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int n, m;
pair<int, int> a[100500];

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> a[i].second >> a[i].first;
	sort(a, a + m);
	reverse(a, a + m);
	int res;
	for (res = 2; res <= m; ++res) {
		int val = min(res * (res / 2) + 1, 2 * ((res + 1) / 2) + (res - 2) * (res / 2));
		if (val > n)
			break;
	}
	--res;
	long long ans = 0;
	for (int i = 0; i < res; ++i)
		ans += a[i].first;
	cout << ans;
}