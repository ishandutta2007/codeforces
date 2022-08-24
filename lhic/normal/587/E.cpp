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

const int MAXN = 210000;

vector<int> rmq[MAXN * 4];
int dd[MAXN * 4];
int a[MAXN];
int n;
int q;

vector<int> merge(const vector<int> &a, const vector<int> &b) {
	vector<int> ans = a;
	for (int i = 0; i < (int)b.size(); ++i)
		ans.push_back(b[i]);
	int now = 0;
	for (int i = 0; i < 32; ++i) {
		int fl = -1;
		for (int j = now; j < (int)ans.size(); ++j)
			if ((ans[j] >> i) & 1) {
				fl = j;
				break;
			}
		if (fl == -1)
			continue;
		swap(ans[now], ans[fl]);
		for (int j = now + 1; j < (int)ans.size(); ++j)
			if ((ans[j] >> i) & 1)
				ans[j] ^= ans[now];
		++now;
	}
	while (!ans.empty() && ans.back() == 0)
		ans.pop_back();
	return ans;
}


void add(int v, int tl, int tr, int l, int r, int k) {
	if (tr <= l || r <= tl)
		return;
	if (l <= tl && tr <= r) {
		dd[v] ^= k;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, k);
	add(v * 2 + 2, m, tr, l, r, k);
}

int get(int v, int tl, int tr, int x) {
	if (tl + 1 == tr)
		return dd[v];
	int m = (tl + tr) >> 1;
	if (x < m)
		return get(v * 2 + 1, tl, m, x) ^ dd[v];
	else
		return get(v * 2 + 2, m, tr, x) ^ dd[v];
}

void buildd(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v] = {a[tl] ^ a[tl + 1]};
		return;
	}
	int m = (tl + tr) >> 1;
	buildd(v * 2 + 1, tl, m);
	buildd(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void addd(int v, int tl, int tr, int x, int k) {
	if (tl + 1 == tr) {
		rmq[v][0] ^= k;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		addd(v * 2 + 1, tl, m, x, k);
	else
		addd(v * 2 + 2, m, tr, x, k);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

vector<int> getd(int v, int tl, int tr, int l, int r) {
	if (tr <= l || r <= tl)
		return {};
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return merge(getd(v * 2 + 1, tl, m, l, r), getd(v * 2 + 2, m, tr, l, r));
}



int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	buildd(0, 0, n);
	for (int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			--l;
			--r;
			add(0, 0, n, l, r + 1, k);
			if (l > 0)
				addd(0, 0, n, l - 1, k);
			addd(0, 0, n, r, k);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			--r;
			vector<int> ans = getd(0, 0, n, l, r);
			ans = merge(ans, {get(0, 0, n, l) ^ a[l]});
			printf("%lld\n", 1ll << ans.size());
		}
	}
	return 0;
}