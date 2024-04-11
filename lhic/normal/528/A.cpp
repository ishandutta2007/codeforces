#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 300000;

int w, h;
int n;

set<int> ss;

char c[MAXN];
int x[MAXN];

ll a1[MAXN];
ll a2[MAXN];


int main() {
	scanf("%d%d", &w, &h);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c %d", &c[i], &x[i]);
	}
	ss.insert(0);
	ss.insert(h);
	for (int i = 0; i < n; ++i)
		if (c[i] == 'H')
			ss.insert(x[i]);
	int mxh = 1;
	int lst = 0;
	for (auto i:ss) {
		mxh = max(mxh, i - lst);
		lst = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		a1[i] = mxh;
		if (c[i] == 'H') {
			auto it = ss.find(x[i]);
			--it;
			ss.erase(x[i]);
			int x1 = *it;
			++it;
			int x2 = *it;
			mxh = max(mxh, x2 - x1);
		}
	}
	ss.clear();
	ss.insert(0);
	ss.insert(w);
	for (int i = 0; i < n; ++i)
		if (c[i] == 'V')
			ss.insert(x[i]);
	int mxw = 1;
	lst = 0;
	for (auto i:ss) {
		mxw = max(mxw, i - lst);
		lst = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		a2[i] = mxw;
		if (c[i] == 'V') {
			auto it = ss.find(x[i]);
			--it;
			ss.erase(x[i]);
			int x1 = *it;
			++it;
			int x2 = *it;
			mxw = max(mxw, x2 - x1);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << a1[i] * a2[i] << "\n";
	}


	return 0;
}