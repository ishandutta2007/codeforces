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

//int mod = 1000000007;

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}


void solve() {
	string s;
	cin >> s;

	string q;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '#') {
			q += ')';
			q += '#';
		}
		else
			q += s[i];
	}
		 
	s = q;

	vector<int> res;

	int lastPos = -1;

	int diff = 0;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '#') {
			lastPos = i;
		}
		if (s[i] == '(')
			++diff;
		if (s[i] == ')')
			--diff;
	}

	if (diff < 0) {
		cout << "-1\n";
		return;
	}


	string ans;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			ans += s[i];
		}
		if (s[i] == ')') {
			ans += s[i];
		}
		if (s[i] == '#') {
			if (i == lastPos) {
				res.push_back(diff + 1);
				for (int j = 0; j < diff; ++j)
					ans += ')';
			}
			else {
				res.push_back(1);
			}
		}
	}

	int bal = 0;
	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] == '(')
			++bal;
		if (ans[i] == ')')
			--bal;
		if (bal < 0) {
			cout << "-1\n";
			return;
		}
	}

	assert(bal == 0);
	

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << '\n';
	}

}