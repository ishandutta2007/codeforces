#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

const int MAXN = 120000;

vector<int> rr[MAXN];
vector<int> cc[MAXN];
vector<pair<int, int> > rmqr[MAXN * 4];
vector<pair<int, int> > rmqc[MAXN * 4];
vector<int> mxr[MAXN * 4];
vector<int> mxc[MAXN * 4];


int n, m, q, k;

void buildr(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		sort(rr[tl].begin(), rr[tl].end());
		for (int i = 0; i < (int)rr[tl].size() - 1; ++i) {
			rmqr[v].push_back(make_pair(rr[tl][i], rr[tl][i + 1]));
		}
		int mx = 0;
		for (int i = 0; i < (int)rmqr[v].size(); ++i)
			mx = max(mx, rmqr[v][i].second), mxr[v].push_back(mx);
		return;
	}
	int m = (tl + tr) >> 1;
	buildr(v * 2 + 1, tl, m);
	buildr(v * 2 + 2, m, tr);
	rmqr[v].resize(rmqr[v * 2 + 1].size() + rmqr[v * 2 + 2].size());
	merge(rmqr[v * 2 + 1].begin(), rmqr[v * 2 + 1].end(), rmqr[v * 2 + 2].begin(), rmqr[v * 2 + 2].end(), rmqr[v].begin());
	int mx = 0;
	for (int i = 0; i < (int)rmqr[v].size(); ++i)
		mx = max(mx, rmqr[v][i].second), mxr[v].push_back(mx);
}

int getr(int v, int tl, int tr, int l, int r, int k) {
	if (tr <= l || r <= tl)
		return 0;
	if (l <= tl && tr <= r) {
		int x = lower_bound(rmqr[v].begin(), rmqr[v].end(), make_pair(k, 0)) - rmqr[v].begin() - 1;
		return mxr[v][x];
	}
	int m = (tl + tr) >> 1;
	return max(getr(v * 2 + 1, tl, m, l, r, k), getr(v * 2 + 2, m, tr, l, r, k));
}


void buildc(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		sort(cc[tl].begin(), cc[tl].end());
		for (int i = 0; i < (int)cc[tl].size() - 1; ++i) {
			rmqc[v].push_back(make_pair(cc[tl][i], cc[tl][i + 1]));
		}
		int mx = 0;
		for (int i = 0; i < (int)rmqc[v].size(); ++i)
			mx = max(mx, rmqc[v][i].second), mxc[v].push_back(mx);
		return;
	}
	int m = (tl + tr) >> 1;
	buildc(v * 2 + 1, tl, m);
	buildc(v * 2 + 2, m, tr);
	rmqc[v].resize(rmqc[v * 2 + 1].size() + rmqc[v * 2 + 2].size());
	merge(rmqc[v * 2 + 1].begin(), rmqc[v * 2 + 1].end(), rmqc[v * 2 + 2].begin(), rmqc[v * 2 + 2].end(), rmqc[v].begin());
	int mx = 0;
	for (int i = 0; i < (int)rmqc[v].size(); ++i)
		mx = max(mx, rmqc[v][i].second), mxc[v].push_back(mx);
}

int getc(int v, int tl, int tr, int l, int r, int k) {
	if (tr <= l || r <= tl)
		return 0;
	if (l <= tl && tr <= r) {
		int x = lower_bound(rmqc[v].begin(), rmqc[v].end(), make_pair(k, 0)) - rmqc[v].begin() - 1;
		return mxc[v][x];
	}
	int m = (tl + tr) >> 1;
	return max(getc(v * 2 + 1, tl, m, l, r, k), getc(v * 2 + 2, m, tr, l, r, k));
}


int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	++n;
	++m;
	for (int i = 0; i < n; ++i)
		rr[i].push_back(0), rr[i].push_back(m);
	for (int i = 0; i < m; ++i)
		cc[i].push_back(0), cc[i].push_back(n);

	scanf("%d%d", &k, &q);
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		rr[x].push_back(y);
		cc[y].push_back(x);
	}

	buildr(0, 0, n);
	buildc(0, 0, m);


	for (int i = 0; i < q; ++i) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (getr(0, 0, n, x1, x2 + 1, y1) > y2 && getc(0, 0, m, y1, y2 + 1, x1) > x2)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}