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

int p[2][200500];

const int shift = (1 << 18);

int tree[2 * shift + 5];

void build() {
    for (int i = shift; i < shift + n; ++i)
        tree[i] = 1;
    for (int i = shift - 1; i > 0; --i)
        tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void modify(int v, int val) {
    tree[v] = val;
    v /= 2;
    while(v > 0) {
        tree[v] = tree[2 * v] + tree[2 * v + 1];
        v /= 2;
    }
}

int rsq(int l, int r) {
    if (l >= r)
        return 0;
    if (l & 1)
        return tree[l] + rsq(l + 1, r);
    if (r & 1)
        return tree[r - 1] + rsq(l, r - 1);
    return rsq(l / 2, r / 2);
}

int findPos (int v, int need) {
    //cerr << v << ' ' << need << endl;
    if (v >= shift) {
        assert(need == 1 && tree[v] == 1);
        return v - shift;
    }
    if (tree[2 * v] >= need)
        return findPos(2 * v, need);
    return findPos(2 * v + 1, need - tree[2 * v]);
}

void solve() {
    cin >> n;
    for (int w = 0; w < 2; ++w) {
        for (int i = 0; i< n; ++i) {
            cin >> p[w][i];
        }
    }

    vector<int> sum(n + 1, 0);

    for (int w = 0; w < 2; ++w) {
        build();
        for (int i = 0; i < n; ++i) {
            sum[n - i - 1] += rsq(shift, shift + p[w][i]);
            modify(p[w][i] + shift, 0);
        }

       /* for (int i = 0; i< sum.size(); ++i)
        cout << sum[i] << ' ';
    cout << endl;*/

    }

   // return;



    for (int i = 0; i < n; ++i) {
        while (sum[i] > i) {
            sum[i] -= i + 1;
            ++sum[i + 1];
        }
    }

    build();
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        int les = sum[n - i - 1];
        int pos = findPos(1, les + 1);
        res[i] = pos;
        modify(pos + shift, 0);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }

}