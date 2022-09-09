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

#define int li

int mod = 1000000007;

int curNumber[10];

int curSize[10];

string s;
int n;

pair<int, vector<int>> queries[100500];

int binpow(int q, int w) {
	if (!w)
		return 1;
	if (w & 1)
		return (q * binpow(q, w - 1)) % mod;
	return binpow((q * q) % mod, w / 2);
}

void solve() {
	cin >> s >> n;
	queries[0].first = 0;
	for (int i = 0; i < s.length(); ++i)
		queries[0].second.push_back(s[i] - '0');
	for (int i = 1; i <= n; ++i) {
		string q;
		cin >> q;
		queries[i].first = q[0] - '0';
		reverse(all(q));
		q = q.substr(0, q.length() - 3);
		reverse(all(q));
		for (int j = 0; j < q.length(); ++j)
			queries[i].second.push_back(q[j] - '0');
	}

	for (int i = 0; i < 10; ++i) {
		curNumber[i] = i;
		curSize[i] = 1;
	}

	for (int i = n; i >= 0; --i) {
		int newSize = 0, newNumber = 0;
		for (int j = (int)queries[i].second.size() - 1; j >= 0; --j) {
			newNumber += curNumber[queries[i].second[j]] * binpow(10, newSize);
			newNumber %= mod;
			newSize += curSize[queries[i].second[j]];
			newSize %= (mod - 1);
		}

		curNumber[queries[i].first] = newNumber;
		curSize[queries[i].first] = newSize;

	}


	cout << curNumber[0];

}