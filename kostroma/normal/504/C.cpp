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

#ifdef room111
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
int a[100500];

void solve() {
	cin >> n;

	map<int, int> nums;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		nums[a[i]]++;
	}

	int cntOdd = 0;
	for (auto item : nums) {
		if (item.second & 1)
			++cntOdd;
	}
	if (cntOdd > 1) {
		cout << "0\n";
		return;
	}

	int pref = 0;
	while (pref < n) {
		if (a[pref] != a[n - 1 - pref])
			break;
		++pref;
	}

	if (pref == n) {
		li res = n * 1LL * (n + 1) / 2;
		cout << res << "\n";
		return;
	}
	assert(2 * pref < n);

	bool oddGood = true;

	pair<int, int> middle;
	if (n & 1) {
		middle = mp(n / 2, n / 2);
		if (!(nums[a[n / 2]] & 1)) {
			oddGood = false;
		}
	}
	else {
		middle = mp(n / 2, n / 2 - 1);
	}

	while (middle.first > 0 && middle.second < n) {
		if (a[middle.first - 1] == a[middle.second + 1]) {
			--middle.first;
			++middle.second;
		}
		else
			break;
	}

	assert(pref < middle.first);

	li res = 0;

	if (oddGood) {

		map<int, int> balance;
		for (int i = pref; i < middle.first; ++i)
			++balance[a[i]];

		for (int i = middle.second + 1; i < n - pref; ++i)
			--balance[a[i]];

		bool allNull = true;
		for (auto item : balance) {
			if (item.second != 0) {
				allNull = false;
				break;
			}
		}

		if (allNull) {
			res += 1LL * (pref + 1) * (n / 2 - middle.first + 1) * 2; //???
		}
	}

	for (int w = 0; w < 2; ++w) {

		int l = 0;
		int r = n / 2;

		vector<int> bal(n + 1);
		for (int i = l; i <= r; ++i)
			++bal[a[i]];
		for (int i = r + 1; i < n; ++i)
			--bal[a[i]];

		int cntNeg = 0;
		for (int i = 0; i <= n; ++i)
			if (bal[i] < 0)
				++cntNeg;

		while (l <= pref) {
			//cerr << l << "\n";
			while (cntNeg && r + 1 < n) {
				++r;
				bal[a[r]] += 2;
				if (bal[a[r]] >= 0 && bal[a[r]] <= 1)
					--cntNeg;
			}
			if (cntNeg == 0) {
				res += n - r;
			}
			++l;

		}

		reverse(a, a + n);
	}

	res -= 1LL * (pref + 1) * (pref + 1);

	cout << res << "\n";


}