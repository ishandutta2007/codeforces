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

const int INF = 2000000000;

const int MAXN = 160;
const int INF2 = 100000;

int ans = INF;

bitset<MAXN> cn;
bitset<MAXN> cn2;

bitset<MAXN> op1[MAXN];
bitset<MAXN> op2[MAXN];
bitset<MAXN> go[MAXN];
bitset<MAXN> go2[MAXN];
bitset<MAXN> ago[MAXN];

int ff[MAXN][MAXN];

int n, m;

vector<tuple<int, int, int> > eds;


void pow2(int b) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ago[i][j] = (i == j);
	for (int i = 0; i < n; ++i)
		go2[i] = go[i];
	while (b) {
		while (!(b & 1)) {
			b >>= 1;
			for (int i = 0; i < n; ++i)
				op1[i] = go2[i];
			for (int i = 0; i < n; ++i)
				op2[i] = go2[i];
			for (int i = 0; i < n; ++i)
				go2[i].reset();
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					if (op1[i][j])
						go2[i] |= op2[j];
		}
		--b;
		for (int i = 0; i < n; ++i)
			op1[i] = ago[i];
		for (int i = 0; i < n; ++i)
			op2[i] = go2[i];
		for (int i = 0; i < n; ++i)
			ago[i].reset();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (op1[i][j])
					ago[i] |= op2[j];
	}
}



int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		--a;
		--b;
		eds.push_back(make_tuple(d, a, b));
	}
	sort(eds.begin(), eds.end());
	cn[0] = 1;
	int lst = 0;
	for (int i = 0; i < (int)eds.size(); ++i) {
		int a, b, d;
		tie(d, a, b) = eds[i];
		pow2(d - lst);
		for (int j = 0; j < n; ++j)
			cn2[j] = (ago[j] & cn).any();
		cn = cn2;
		lst = d;
		go[b][a] = 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (go[j][i])
					ff[i][j] = 1;
				else
					ff[i][j] = INF2;
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					if (ff[i][k] + ff[k][j] < ff[i][j])
						ff[i][j] = ff[i][k] + ff[k][j];
		for (int i = 0; i < n; ++i)
			if (cn[i]) {
				if (ff[i][n - 1] < INF2 && lst + ff[i][n - 1] < ans)
					ans = lst + ff[i][n - 1];
			}
	}

	if (ans >= INF)
		cout << "Impossible\n";
	else
		cout << ans << "\n";
	return 0;
}