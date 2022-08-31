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

const int MX = 201000;
const int MAXN = 201000;

vector<int> eds[MX * 3];
vector<int> en[MX * 3];
int p[MAXN * 3];
int n;
map<pair<int, int>, int> mm;
int ans[MAXN];
int cnt1[MX];
int cnt2[MX];
int xxx[MX];
int yyy[MX];

void dfs(int v, int c) {
	while (p[v] < (int)eds[v].size() && en[v][p[v]])
		++p[v];
	if (p[v] >= (int)eds[v].size())
		return;
	int a = v;
	int b = eds[v][p[v]];
	if (a > b)
		swap(a, b);
	ans[mm[make_pair(a, b)]] = c;
	en[v][p[v]] = 1;
	int u = eds[v][p[v]];
	en[u][lower_bound(eds[u].begin(), eds[u].end(), v) - eds[u].begin()] = 1;
	dfs(eds[v][p[v]], c ^ 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		xxx[i] = x;
		yyy[i] = y;
		mm[make_pair(x, y + MX)] = i;
		eds[x].push_back(y + MX);
		eds[y + MX].push_back(x);
		en[x].push_back(0);
		en[y + MX].push_back(0);
	}
	for (int i = 0; i < 2 * MX; ++i)
		sort(eds[i].begin(), eds[i].end());
	for (int i = 0; i < MX; ++i) {
		int lst = 0;
		while (p[i] != (int)eds[i].size())
			dfs(i, lst), lst ^= 1;
	}

	for (int i = 0; i < n; ++i)
		if (ans[i] == 0)
			++cnt1[xxx[i]], ++cnt2[yyy[i]];
		else
			--cnt1[xxx[i]], --cnt2[yyy[i]];
	for (int i = 0; i < MX; ++i)
		if (abs(cnt1[i]) > 1 || abs(cnt2[i]) > 1)
			return 1;

	for (int i = 0; i < n; ++i)
		if (ans[i] == 0)
			printf("b");
		else
			printf("r");
	return 0;
}