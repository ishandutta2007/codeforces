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

const int MAXN = 3100;

int n, m;

int ff[MAXN];
int le[MAXN][MAXN];
int ri[MAXN][MAXN];
char s[MAXN][MAXN];
int gn;

void clear(int n) {
	memset(ff, 0, sizeof(ff[0]) * n);
	gn = n;
}

void upd(int v, int d) {
	for (; v < n; v |= (v + 1))
		ff[v] += d;
}

int get(int v) {
	int ans = 0;
	for (; v >= 0; v &= (v + 1), --v)
		ans += ff[v];
	return ans;
}
vector<int> vv[MAXN * 2];
ll ans = 0;


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf(" %s", s[i]), reverse(s[i], s[i] + m);
	for (int i = 0; i < n; ++i) {
		le[i][0] = (s[i][0] == 'z' ? 1 : 0);
		for (int j = 1; j < m; ++j) {
			if (s[i][j] == 'z')
				le[i][j] = le[i][j - 1] + 1;
			else
				le[i][j] = 0;
		}
		ri[i][m - 1] = (s[i][m - 1] == 'z' ? 1 : 0);
		for (int j = m - 2; j >= 0; --j) {
			if (s[i][j] == 'z')
				ri[i][j] = ri[i][j + 1] + 1;
			else
				ri[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		int sx = i;
		int sy = 0;
		int go = 0;
		int gg = min(n - sx, m - sy);
		clear(gg + 1);
		for (int i = 0; i <= m + n; ++i)
			vv[i].clear();
		--gg;
		for (int k = 0; k <= gg; ++k) {
			if (s[sx + k][sy + k] == 'z')
				++go;
			else {
				go = 0;
				continue;
			}
			int g = k + ri[sx + k][sy + k];
			upd(gg - k, 1);
			vv[g].push_back(k);
			for (int j: vv[k])
				upd(gg - j, -1);
			vv[k].clear();
			int qq = min(go, le[sx + k][sy + k]);
			ans += get(gg - k + qq - 1);
		}
	}
	for (int i = 1; i < m; ++i) {
		int sx = 0;
		int sy = i;
		int go = 0;
		int gg = min(n - sx, m - sy);
		clear(gg + 1);
		for (int i = 0; i <= m + n; ++i)
			vv[i].clear();
		--gg;
		for (int k = 0; k <= gg; ++k) {
			if (s[sx + k][sy + k] == 'z')
				++go;
			else {
				go = 0;
				continue;
			}
			int g = k + ri[sx + k][sy + k];
			upd(gg - k, 1);
			vv[g].push_back(k);
			for (int j: vv[k])
				upd(gg - j, -1);
			vv[k].clear();
			int qq = min(go, le[sx + k][sy + k]);
			ans += get(gg - k + qq - 1);
		}
	}
	
	cout << ans << "\n";

	return 0;
}