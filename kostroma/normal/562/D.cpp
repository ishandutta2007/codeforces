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
	freopen("out.txt", "w", stdout);
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


vector<int> dsu;

int get(int v) {
	if (v == dsu[v])
		return v;
	return dsu[v] = get(dsu[v]);
}

void unite(int a, int b) {
	dsu[get(a)] = get(b);
}

void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	dsu.assign(n, 0);
	for (int i = 0; i < n; ++i)
		dsu[i] = i;


	set<int> firsts(dsu.begin(), dsu.end());
	firsts.insert(n);
	
	for (int i = 0; i < q; ++i) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		--x, --y;
		if (type == 1) {
			unite(x, y);
		}
		else if (type == 3) {
			if (get(x) == get(y)) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}
		else {
			auto it = --firsts.upper_bound(x);
			while (true) {
				auto nex = std::next(it);
				if (*nex > y)
					break;
				unite(x, *nex);
				firsts.erase(nex);
			}
		}
	}
}