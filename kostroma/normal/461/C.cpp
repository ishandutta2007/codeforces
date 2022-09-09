#pragma comment (linker, "/STACK:128000000")
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
	cout.sync_with_stdio(0);
	//precalc();
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

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

const int shift = 1 << 18;

int tree[2 * shift + 6];

void modify(int v, int add) {
	tree[v] += add;
	while (v > 0) {
		v /= 2;
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
}

int getSum(int l, int r) {
	if (l > r)
		return 0;
	if (l % 2)
		return tree[l] + getSum(l + 1, r);
	if (r % 2 == 0)
		return tree[r] + getSum(l, r - 1);
	return getSum(l / 2, r / 2);
}

void solve() {

	int n, Q;
	cin >> n >> Q;

	int curBegin = shift, curEnd = shift + n;

	bool reversed = false;

	for (int i = 0; i < n; ++i)
		modify(curBegin + i, 1);

	while(Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int p;
			cin >> p;
			int curLength = curEnd - curBegin;
			bool wasReversed = reversed;
			if (reversed)
				p = curLength - p;
			if (curLength - p < p) {
				reversed ^= 1;
				for (int i = curBegin + p; i < curEnd; ++i) {
					modify(curBegin + p - 1 - (i - curBegin - p), tree[i]);
					modify(i, -tree[i]);
				}
				curEnd = curBegin + p;
			}
			else {
				for (int i = curBegin + p - 1; i >= curBegin; --i) {
					modify(curBegin + p + (curBegin + p - 1 - i), tree[i]);
					modify(i, -tree[i]);
				}
				curBegin = curBegin + p;
			}
			reversed ^= wasReversed;
		}
		else {

			int l, r;
			cin >> l >> r;
			int res;
			if (!reversed)
				res = getSum(curBegin + l, curBegin + r - 1);
			else
				res = getSum(curEnd - r, curEnd - l - 1);

			cout << res << "\n";

		}
	}

}