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
const int MAXN = 210000;

int gog[45];
int vl[45];
int gog2[45];
int vl2[45];
int n, m;
vector<pair<int, int> > vv;
int ans[MAXN];
vector<pair<int, int> > go[MAXN];
int len[MAXN];
int a[MAXN][45];
int nx[MAXN];


int solve() {
	for (int i = 1; i <= 40; ++i)
		gog[i] = vv.size(), vl[i] = -1, gog2[i] = vv.size(), vl2[i] = vv.size();
	int lst = vv.size();
	int ans = 0;
	for (int i = (int)vv.size() - 1; i >= 0; --i) {
		nx[i] = vv.size();
		for (int j = 1; j <= 40; ++j) {
			if (vv[i].first % j == 0) {
				if (vv[i].second % j != vl[j]) {
					vl2[j] = vl[j];
					gog2[j] = gog[j];
					vl[j] = vv[i].second % j, nx[i] = min(nx[i], gog[j]), gog[j] = i;
				}
				else {
					gog[j] = i;
					nx[i] = min(nx[i], gog2[j]);
				}
			}
		}
		lst = min(lst, nx[i]);
		ans = max(ans, lst - i);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", len + i);
		for (int j = 0; j < len[i]; ++j) {
			scanf("%d", &a[i][j]);
			go[a[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= m; ++i) {
		vv.clear();
		ans[i] = 0;
		for (int j = 0; j < (int)go[i].size(); ++j) {
			vv.push_back(make_pair(len[go[i][j].first], go[i][j].second));
			if (j == (int)go[i].size() - 1 || go[i][j].first + 1 != go[i][j + 1].first) {
				int res = solve();
				ans[i] = max(ans[i], res);
				vv.clear();
			}
		}
		printf("%d\n", ans[i]);
	}
	return 0;
}