//#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
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
//#include <unordered_map>
//#include <unordered_set>
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
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef DEBUG
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//ld eps = 1e-9;

int n;
int d[100500], s[100500];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> s[i];
    }

    set<pair<int, int> > verts;
    for (int i = 0; i < n; ++i) {
        verts.insert(mp(d[i], i));
    }

    vector<pair<int, int> > edges;

    while(!verts.empty()) {
        pair<int, int> now = *verts.begin();
        verts.erase(verts.begin());
        int v = now.second;
        int deg = now.first;
        if (deg == 0) {
            assert(s[v] == 0);
            continue;
        }
        assert(deg == 1);
        edges.push_back(mp(v, s[v]));

        verts.erase(mp(d[s[v]], s[v]));
        --d[s[v]];
        s[s[v]] ^= v;
        verts.insert(mp(d[s[v]], s[v]));
    }

    cout << edges.size() << "\n";
    for (int i = 0; i < edges.size(); ++i) {
        cout << edges[i].first << ' ' << edges[i].second << "\n";
    }

}