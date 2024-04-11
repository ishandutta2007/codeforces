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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 120000;
const int SQ = 400;
const int SQ2 = MAXN / SQ;

int bb[SQ2][SQ];
int bc[SQ2];
int dl[SQ2];
int t[MAXN];
int x[MAXN];
int m;

void upd(int k) {
	int l = k * SQ;
	int r = min((k + 1) * SQ, m);
	dl[k] = 0;
	bc[k] = 0;
	for (int i = l; i < r; ++i) {
		if (t[i] == 1) {
			if (bc[k])
				--bc[k];
			else
				++dl[k];
		}
		else if (t[i] == 2) {
			bb[k][bc[k]++] = x[i];
		}
	}
}

vector<pair<int, int> > vv;

int calc() {
	vv.clear();
	int bl = (m + SQ - 1) / SQ;
	for (int i = 0; i < bl; ++i) {
		int x = dl[i];
		while (!vv.empty() && x >= vv.back().second)
			x -= vv.back().second, vv.pop_back();
		if (!vv.empty())
			vv.back().second -= x;
		if (bc[i])
			vv.push_back(make_pair(i, bc[i]));
	}
	if (vv.empty())
		return -1;
	int x = vv.back().first;
	int y = vv.back().second;
	return bb[x][y - 1];
}


int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int pp, tt;
		scanf("%d%d", &pp, &tt);
		--pp;
		if (tt == 0) {
			t[pp] = 1;
		}
		else {
			t[pp] = 2;
			scanf("%d", x + pp);
		}
		upd(pp / SQ);
		printf("%d\n", calc());
	}
	return 0;
}