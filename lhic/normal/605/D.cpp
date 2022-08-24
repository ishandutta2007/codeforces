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


const int INF = 1e9 + 10000;
const int MAXN = 150000;

int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int n;
pair<int, int> rmq[MAXN * 4];

vector<int> vv;

int dd[MAXN];
int go[MAXN];

queue<int> qu;

bool cmp(int x, int y) {
	return a[x] < a[y];
}




void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = make_pair(b[vv[tl]], tl);
		return;
	}
	int m = (tl + tr) >> 1;

	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return make_pair(INF, 0);
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl + 1 == tr) {
		rmq[v] = make_pair(y, x);
		return;
	}
	
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x, y);
	else
		upd(v * 2 + 2, m, tr, x, y);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}




int cc[MAXN];

void kill(int x) {
	upd(0, 0, n, cc[x], INF);
}



int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	a[0] = b[0] = c[0] = d[0] = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
	++n;
	for (int i = 0; i < n; ++i)
		vv.push_back(i);
	sort(vv.begin(), vv.end(), cmp);
	qu.push(0);
	for (int i = 0; i < n; ++i)
		cc[vv[i]] = i;
	for (int i = 1; i < n; ++i)
		dd[i] = INF;
	build(0, 0, n);
	kill(0);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		int l = -1;
		int r = n;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (a[vv[m]] <= c[x])
				l = m;
			else
				r = m;
		}
		while (r > 0) {
			pair<int, int> xx = get(0, 0, n, 0, r);
			swap(xx.first, xx.second);
			xx.first = vv[xx.first];
			if (xx.second > d[x]) {
				break;
			}
			go[xx.first] = x;
			dd[xx.first] = dd[x] + 1;
			kill(xx.first);
			qu.push(xx.first);
		}
	}
	vector<int> ans;
	if (dd[n - 1] == INF) {
		cout << -1 << "\n";
		return 0;
	}
	printf("%d\n", dd[n - 1]);
	int now = n - 1;
	while (now != 0)
		ans.push_back(now), now = go[now];
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}