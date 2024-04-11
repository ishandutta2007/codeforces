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
const int MAXN = 12000;

int n;
vector<pair<int, int> > vvx;
vector<pair<int, int> > vvy;
int x[MAXN];
int y[MAXN];

void swx(int a, int b) {
	if (a == b)
		return;
	swap(x[a], x[b]);
	vvx.push_back(make_pair(a, b));
	vvx.push_back(make_pair(b, a));
	vvx.push_back(make_pair(a, b));
}

void swy(int a, int b) {
	if (a == b)
		return;
	swap(y[a], y[b]);
	vvy.push_back(make_pair(a, b));
	vvy.push_back(make_pair(b, a));
	vvy.push_back(make_pair(a, b));
}


int gg(int x) {
	for (int i = 0; i < 30; ++i)
		if ((x >> i) & 1)
			return i;
	return -1;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", y + i);
	int stx = 0;
	for (int i = 0; i < 30; ++i) {
		int fl = 0;
		for (int j = stx; j < n; ++j) {
			if ((x[j] >> i) & 1) {
				swx(stx, j);
				fl = 1;
				break;
			}
		}
		if (!fl)
			continue;
		for (int j = 0; j < n; ++j)
			if (j != stx && ((x[j] >> i) & 1))
				vvx.push_back(make_pair(j, stx)), x[j] ^= x[stx];
		++stx;
	}
	int sty = 0;
	for (int i = 0; i < 30; ++i) {
		int fl = 0;
		for (int j = sty; j < n; ++j) {
			if ((y[j] >> i) & 1) {
				swy(sty, j);
				fl = 1;
				break;
			}
		}
		if (!fl)
			continue;
		for (int j = 0; j < n; ++j)
			if (j != sty && ((y[j] >> i) & 1))
				vvy.push_back(make_pair(j, sty)), y[j] ^= y[sty];
		++sty;
	}

	for (int i = 0; i < stx; ++i) {
		for (int j = 0; j < sty; ++j) {
			if (gg(x[i]) == gg(y[j])) {
				for (int k = 0; k < 30; ++k) {
					if (((x[i] >> k) & 1) != ((y[j] >> k) & 1)) {
						for (int l = i + 1; l < stx; ++l)
							if (gg(x[l]) == k) {
								vvx.push_back(make_pair(i, l));
								x[i] ^= x[l];
								break;
							}
					}
				}
			}
		}
	}

	set<int> ssx;
	set<int> ssy;
	for (int i = 0; i < stx; ++i)
		ssx.insert(x[i]);
	for (int i = 0; i < sty; ++i)
		ssy.insert(y[i]);
	for (int i = 0; i < sty; ++i) {
		if (!ssx.count(y[i])) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for (int j = 0; j < stx; ++j) {
		if (!ssy.count(x[j])) {
			vvx.push_back(make_pair(j, j));
			x[j] = 0;
			for (int k = j + 1; k < stx; ++k)
				vvx.push_back(make_pair(k - 1, k)), x[k - 1] ^= x[k], vvx.push_back(make_pair(k, k)), x[k] = 0;
			--stx;
			j -= 1;
		}
	}
	for (int i = 0; i < n; ++i)
		assert(x[i] == y[i]);
	while (!vvy.empty())
		vvx.push_back(vvy.back()), vvy.pop_back();
	printf("%d\n", (int)vvx.size());
	for (pair<int, int> i: vvx)
		printf("%d %d\n", i.first + 1, i.second + 1);
	return 0;
}