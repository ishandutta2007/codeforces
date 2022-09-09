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

int n, m, p;
int a[200500], b[200500];
map<int, int> haveb;

void solve(){
	cin >> n >> m >> p;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		++haveb[b[i]];
	}

	int N = haveb.size();

	vector<int> ans;
	for (int i = 0; i < p; ++i) {
		map<int, int> mapa;
		int matches = 0;
		int it = 0;
		for (int j = i; j < n; j += p, ++it) {
			++mapa[a[j]];
			if (haveb.count(a[j]) && mapa[a[j]] == haveb[a[j]])
				++matches;

			if (it >= m - 1) {
				if (matches == N)
					ans.push_back(j - (m - 1) * p);
				int id = j - (m - 1) * p;
				if (haveb.count(a[id]) && haveb[a[id]] == mapa[a[id]])
					--matches;
				--mapa[a[id]];
			}

		}
	}
	sort(all(ans));
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] + 1 << ' ';

}