#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <stack>
#include <iostream>
#include <fstream>

#define mp make_pair
#define pb push_back

using ll = long long;
using ld = long double;

using namespace std;

const int MAXN = 100001;

const int M = 60;

ll a[MAXN];
int n;

void no() {
	cout << -1 << endl;
	exit(0);
}


int pc[MAXN];


int getp2(ll x) {
	ll c = 1;
	int pw = 0;
	while (c < x) c *= 2, pw++;
	if (c == x) return pw;
	else return -1;
}

struct dvector {
	ll a[MAXN];
	int ac = 0;

	int size() {
		return ac;
	}

	void push_back(ll x) {
		assert(ac < n);
		a[ac++] = x;
	}

	int resize(int x) {
		ac = x;
	}

	ll& operator[] (int index) {
		return a[index];
	}

	ll* begin() {
		return a;
	}

	ll* end() {
		return a + ac;
	}

	void clear() {
		ac = 0;
	}

};

dvector bad;
dvector finishes;
dvector nbad;
dvector nfinishes;

bool check() {
	sort(nbad.begin(), nbad.end());
	if (nfinishes.size() < nbad.size()) return false;
	for (int i = 0; i < nbad.size(); i++) {
		if (nbad[i] >= 2 * nfinishes[nfinishes.size() - nbad.size() + i]) return false;
	}
	return true;
}


void print(int l, int r) {
	for (int i = l; i <= r; i++)
		cout << i << " ";
	cout << endl;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cout.setf(ios::fixed); cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int p2 = getp2(a[i]);
		if (p2 != -1) pc[p2]++;
		else bad.push_back(a[i]);
	}
	int cur = pc[0];
	for (int i = 1; i < M; i++) {
		if (pc[i] > cur) {
			for (int j = cur; j < pc[i]; j++) {
				bad.push_back(1ll << i);
			}
		}
		while (cur > pc[i]) {
			finishes.push_back(1ll << (i - 1));
			cur--;
		}
	}

	int lg = 0, rg = finishes.size() + 1;
	while (lg < rg) {
		int md = (lg + rg) / 2;
		int rm = finishes.size() - md;
		nbad.clear();
		for (int i = 0; i < bad.size(); i++) nbad.push_back(bad[i]);
		nfinishes.clear();
		for (int i = 0; i < rm; i++) {
			for (ll j = 1; j <= finishes[i]; j *= 2ll) {
				nbad.push_back(j);
			}
		}
		for (int i = rm; i < finishes.size(); i++) nfinishes.push_back(finishes[i]);
		if (check()) rg = md;
		else lg = md + 1;
	}

	if (lg <= finishes.size()) {
		print(lg, finishes.size());
	} else {
		cout << -1 << endl;
	}
	return 0;
}