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
const int MAXN = 800;

int n, m;
int dd[MAXN][MAXN];
vector<int> eds[MAXN];
vector<pair<int, int> > ed;
ld gg[MAXN][3];
int cc[MAXN];
vector<int> vv[MAXN];
ld pp[MAXN];
int tm;
ld mx[MAXN];
int ts[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == j)
				dd[i][j] = 0;
			else
				dd[i][j] = 100000;
		}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
		ed.push_back(make_pair(a, b));
		dd[a][b] = dd[b][a] = 1;
	}
	ld ans = 0;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dd[i][j] > dd[i][k] + dd[k][j])
					dd[i][j] = dd[i][k] + dd[k][j];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j)
			cc[j] = 0, vv[j].clear();
		for (int j = 0; j < n; ++j)
			++cc[dd[i][j]], vv[dd[i][j]].push_back(j);
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < 3; ++k)
				gg[j][k] = 0;
		for (int j = 0; j < (int)ed.size(); ++j) {
			int a = ed[j].first, b = ed[j].second;
			gg[a][dd[i][b] - dd[i][a] + 1] += 1.0 / (cc[dd[i][b]] * eds[b].size());
			gg[b][dd[i][a] - dd[i][b] + 1] += 1.0 / (cc[dd[i][a]] * eds[a].size());
		}
		for (int j = 0; j < n; ++j) {
			if (cc[j] == 0)
				pp[j] = 0;
			else
				pp[j] = 1.0 / cc[j];
		}
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				++tm;
				if (cc[k] == 0)
					continue;
				ld now = 0;
				if (k > 0) {
					for (int t: vv[k - 1]) {
						if (ts[dd[j][t]] != tm) {
							ts[dd[j][t]] = tm;
							mx[dd[j][t]] = 0;
						}
						if (gg[t][2] > mx[dd[j][t]])
							now += gg[t][2] - mx[dd[j][t]], mx[dd[j][t]] = gg[t][2];
					}
				}
				for (int t: vv[k]) {
					if (ts[dd[j][t]] != tm) {
						ts[dd[j][t]] = tm;
						mx[dd[j][t]] = 0;
					}
					if (gg[t][1] > mx[dd[j][t]])
						now += gg[t][1] - mx[dd[j][t]], mx[dd[j][t]] = gg[t][1];
				}
				for (int t: vv[k + 1]) {
					if (ts[dd[j][t]] != tm) {
						ts[dd[j][t]] = tm;
						mx[dd[j][t]] = 0;
					}
					if (gg[t][0] > mx[dd[j][t]])
						now += gg[t][0] - mx[dd[j][t]], mx[dd[j][t]] = gg[t][0];
				}
				pp[k] = max(pp[k], now);
			}
		}
		ld sum = 0;
		for (int i = 0; i < n; ++i)
			if (cc[i] != 0) {
				sum += pp[i] * ((ld)cc[i] / n);
			}
		ans = max(ans, sum);
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << ans << "\n";

	return 0;
}