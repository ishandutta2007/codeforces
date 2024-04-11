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

const int MAXN = 1000;
const int INF = 1e7;

struct edge {
	int a, c, f, w;
};

int cnt[MAXN];
char s2[MAXN];
int cc[MAXN][MAXN];
int en[MAXN];
int dd[MAXN];
vector<edge> ed;
vector<int> eds[MAXN];
int n, s, t;
int go[MAXN];
int a[MAXN];

void make_edge(int a, int b, int c, int w) {
	edge x;
	x.a = a ^ b;
	x.c = c;
	x.w = w;
	x.f = 0;
	ed.push_back(x);
	x.w = -w;
	x.c = 0;
	ed.push_back(x);
	eds[a].push_back(ed.size() - 2);
	eds[b].push_back(ed.size() - 1);
}

pair<int, int> mincost() {
	pair<int, int> ans = make_pair(0, 0);
	while (true) {
		queue<int> qu;
		memset(en, 0, sizeof(en));
		fill(dd, dd + t + 1, INF);
		dd[s] = 0;
		qu.push(s);
		while (!qu.empty()) {
			int x = qu.front();
			qu.pop();
			en[x] = 0;
			for (int i = 0; i < (int)eds[x].size(); ++i) {
				int g = eds[x][i];
				int u = ed[g].a ^ x;
				if (ed[g].c - ed[g].f == 0)
					continue;
				int w = ed[g].w;
				if (dd[u] > dd[x] + w) {
					dd[u] = dd[x] + w;
					go[u] = g;
					if (!en[u])
						qu.push(u), en[u] = 1;
				}
			}
		}
		if (dd[t] == INF)
			break;
		int mn = INF;
		int now = t;
		while (now != s) {
			mn = min(mn, ed[go[now]].c - ed[go[now]].f);
			now = ed[go[now]].a ^ now;
		}
		ans.first += mn;
		ans.second += mn * (dd[t]);
		now = t;
		while (now != s) {
			ed[go[now]].f += mn;
			ed[go[now] ^ 1].f -= mn;
			now = ed[go[now]].a ^ now;
		}
	}
	return ans;
}


int main() {
	scanf(" %s", s2);
	int len = strlen(s2);
	for (int i = 0; i < len; ++i)
		++cnt[s2[i] - 'a'];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s %d", s2, a + i);
		int l = strlen(s2);
		for (int j = 0; j < l; ++j)
			++cc[i][s2[j] - 'a'];
	}
	s = n + 26;
	t = n + 27;
	for (int i = 0; i < 26; ++i)
		make_edge(s, n + i, cnt[i], 0);
	for (int i = 0; i < n; ++i) {
		make_edge(i, t, a[i], i + 1);
		for (int j = 0; j < 26; ++j)
			make_edge(n + j, i, cc[i][j], 0);
	}

	pair<int, int> ans = mincost();
	if (ans.first < len)
		cout << -1 << "\n";
	else
		cout << ans.second << "\n";
	return 0;
}