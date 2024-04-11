#pragma comment (linker, "/STACK:128000000")
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
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
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
    while (t--) {
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int k;
int n = 2;

vector<int> g[10050];

int osn = 10;

void solve() {
	cin >> k;
	if (k == 1) {
		cout << "2\nNY\nYN\n";
		return;
	}
	vector<int> number;
	int l = k;
	while (l)
		number.push_back(l % osn), l /= osn;
	int log = number.size();
	for (int i = log - 1; i >= 0; --i) {
		if (!number[i])
			continue;
		int last = 0;

		for (int j = 0; j < number[i]; ++j) {
			g[last].push_back(n);
			++n;
		}
		for (int j = 0; j < number[i]; ++j) {
			g[n].push_back(n - j - 1);
		}
		last = n;
		++n;

		for (int j = 0; j <= log - i - 1; ++j) {
			g[last].push_back(n);
			last = n;
			++n;
			if (i == 0 && j == log - i - 1) {
				g[last].push_back(1);
			}
			else {
				g[last].push_back(n);
				last = n;
				++n;
			}
		}

		for (int j = 0; j < i; ++j) {
			for (int h = 0; h < osn; ++h) {
				g[last].push_back(n);
				++n;
			}
			int nex = n;
			if (j == i - 1) {
				nex = 1;
			}
			for (int h = 0; h < osn; ++h)
				g[nex].push_back(n - h - 1);
			if (j < i - 1)
				++n;
			last = nex;
		}
	}

	vector<string> ans(n, string(n, 'N'));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < g[i].size(); ++j)
			ans[i][g[i][j]] = ans[g[i][j]][i] = 'Y';
	cout << n << "\n";
	//return;
	for (int i = 0; i < n; ++i)
		cout << ans[i] << "\n";
}

/*#pragma comment (linker, "/STACK:128000000")
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
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
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
    while (t--) {
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

int k = 24;

void solve() {
	int cnt = 0;
	for (int mask = 1; mask < (1 << k); ++mask) {
		bool flag = true;
		for (int z = 0; flag && z < k; ++z)
			if (mask & (1 << z))
				for (int h = z; flag && h < k; ++h)
					if (mask & (1 << h)) {
						int cur = z ^ h;
						if (!(mask & (1 << cur))) {
							flag = false;
							break;
						}
					}
		if (flag) {
			++cnt;
			for (int z = 0; z < k; ++z)
				if (mask & (1 << z))
					cout << z << ' ';
			cout << endl;
		}
	}
	cout << "ans = " << cnt << "\n";
}

*/