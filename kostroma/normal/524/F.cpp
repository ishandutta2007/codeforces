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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
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
	//freopen("c3.out", "w", stdout);
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

//#define int li

void Build(const string& init, vector <int>& suffArray) {
	string s = init;
	/*             1- */
	vector <int> head;
	/*color[i] -  ,   i- */
	vector <int> color;
	/* ,   color,     */
	vector <int> colorSub;
	vector <int> suffArraySub;
	/*256 -   */
	head.assign(max((int)s.size(), 256), 0);
	suffArray.resize(s.size());
	color.resize(s.size());
	colorSub.resize(s.size());
	suffArraySub.resize(s.size());

	/*     */
	for (int i = 0; i < s.size(); ++i) {
		++head[s[i]];
	}
	for (int i = 1; i < 256; ++i) {
		head[i] += head[i - 1];
	}
	for (int i = 255; i > 0; --i) {
		head[i] = head[i - 1];
	}
	head[0] = 0;
	for (int i = 0; i < s.size(); ++i) {
		suffArray[head[s[i]]] = i;
		++head[s[i]];
	}
	/* suffArray     */

	/*   ,  head  ,   */
	int numberOfClasses = 1;
	head[0] = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[suffArray[i - 1]] != s[suffArray[i]]) {
			++numberOfClasses;
			head[numberOfClasses - 1] = i;
		}
		color[suffArray[i]] = numberOfClasses - 1;
	}

	/**/
	for (int k = 1; k < s.size(); k *= 2) {
		/*    2*k*/

		for (int i = 0; i < s.size(); ++i) {
			int firstPartBeginning = suffArray[i] - k;
			if (firstPartBeginning < 0) {
				firstPartBeginning += s.size();
			}
			suffArraySub[head[color[firstPartBeginning]]] = firstPartBeginning;
			++head[color[firstPartBeginning]];
		}
		suffArray = suffArraySub;

		/* color  head*/
		int secondPartBeginning;
		pair <int, int> prevSuffClasses, curSuffClasses;
		curSuffClasses = make_pair(-1, 0);
		numberOfClasses = 0;

		for (int i = 0; i < s.size(); ++i) {
			prevSuffClasses = curSuffClasses;

			secondPartBeginning = suffArray[i] + k;
			if (secondPartBeginning >= s.size()) {
				secondPartBeginning -= s.size();
			}
			curSuffClasses = make_pair(color[suffArray[i]], color[secondPartBeginning]);

			if (curSuffClasses != prevSuffClasses) {
				++numberOfClasses;
				head[numberOfClasses - 1] = i;
			}
			colorSub[suffArray[i]] = numberOfClasses - 1;
		}

		color = colorSub;

		/*      ->  suffArray  */
		if (numberOfClasses == s.size())
			break;
	}
}

const int shift = 1 << 20;

int tree[2 * shift + 7];

int getRmq(int l, int r) {
	if (l >= r) {
		return 1e9;
	}
	if (l & 1) {
		return min(tree[l], getRmq(l + 1, r));
	}
	if (r & 1) {
		return min(tree[r - 1], getRmq(l, r - 1));
	}
	return getRmq(l / 2, r / 2);
}

int getMin(int l, int r) {
	return getRmq(l + shift, r + shift);
}

vector<int> balances;

int getMinBalance(int l, int r) {
	return getMin(l, r) - balances[l];
}

void solve() {
	
	string s;
	cin >> s;

	vector<int> suffArray;
	Build(s, suffArray);
	vector<int> order(s.length());
	for (int i = 0; i < suffArray.size(); ++i) {
		order[suffArray[i]] = i;
	}


	int curBal = 0;

	for (int i = 0; i <= s.length(); ++i) {
		tree[i + shift] = curBal;
		balances.push_back(curBal);
		if (i == s.length()) {
			break;
		}
		int add = 1;
		if (s[i] == ')') {
			add = -1;
		}
		curBal += add;
	}
	for (int i = shift - 1; i >= 0; --i) {
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}

	int overallBal = curBal;

	int add = 0;
	if (overallBal < 0) {
		add = -overallBal;
	}

	int bestPos = -1;

	for (int start = 0; start < s.length(); ++start) {
		if (add + getMinBalance(start, s.length()) < 0) {
			continue;
		}
		int minBal = getMinBalance(0, start) + add + balances[s.length()] - balances[start];
		if (minBal < 0) {
			continue;
		}
		if (bestPos == -1 || order[bestPos] > order[start]) {
			bestPos = start;
		}
	}

	rotate(s.begin(), s.begin() + bestPos, s.end());
	if (overallBal > 0) {
		s += string(overallBal, ')');
	}
	else {
		s = string(add, '(') + s;
	}

	cout << s;


}