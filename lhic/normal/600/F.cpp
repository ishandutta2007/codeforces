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
typedef double ld;

using namespace std;

int go[2200][2200];
int n, m, q;
vector<int> ed;
vector<pair<int, int> > eds;
int cnt[2200];
int ans[120000];



int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n + m; ++i)
		for (int j = 0; j <= max(n, m); ++j)
			go[i][j] = -1;
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		b += n;
		ed.push_back(a ^ b);
		eds.push_back(make_pair(a, b));
		++cnt[a];
		++cnt[b];
	}
	int mx = 0;
	for (int i = 0; i < n + m; ++i)
		mx = max(mx, cnt[i]);
	for (int it = 0; it < (int)ed.size(); ++it) {
		int a, b;
		tie(a, b) = eds[it];
		int fl = 0;
		for (int i = 0; i < mx; ++i)
			if (go[a][i] == -1 && go[b][i] == -1) {
				go[a][i] = go[b][i] = it;
				ans[it] = i;
				fl = 1;
				break;
			}
		if (fl)
			continue;
		int x1 = 0, x2 = 0;
		for (int i = 0; i < mx; ++i)
			if (go[a][i] == -1)
				x2 = i;
			else if (go[b][i] == -1)
				x1 = i;
		ans[it] = x2;
		go[a][x2] = it;
		int gg = x1 ^ x2;
		int now = b;
		int nowc = x2;
		int lst = it;
		while (true) {
			if (go[now][nowc] == -1) {
				go[now][nowc] = lst;
				go[now][nowc ^ gg] = -1;
				break;
			}
			int tmp = go[now][nowc];
			go[now][nowc] = lst;
			lst = tmp;
			nowc ^= gg;
			go[now][nowc] = lst;
			ans[lst] = nowc;
			now ^= ed[lst];
		}
	}
	printf("%d\n", mx);
	for (int i = 0; i < (int)ed.size(); ++i)
		printf("%d ", ans[i] + 1);
	return 0;
}