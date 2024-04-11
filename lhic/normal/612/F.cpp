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

const int MAXN = 2100;

vector<int> gg[MAXN];
vector<int> dp[MAXN];
int a[MAXN];
vector<int> go[MAXN];
int n;
int was[MAXN];

vector<int> ansv;


void upd(int v, int s, int k) {
	if (gg[v].size() == 1) {
		if (dp[v][0] > k + min(abs(s - gg[v][0]), n - abs(s - gg[v][0])))
			dp[v][0] = k + min(abs(s - gg[v][0]), n - abs(s - gg[v][0])), go[v][0] = s;
		return;
	}
	for (int i = 0; i < (int)gg[v].size(); ++i) {
		int bst = 1e8;
		int nn = gg[v].size();
		if ((gg[v][(i + 1) % nn] - gg[v][i] + n) % n < (s - gg[v][i] + n) % n)
			bst = min(bst, n - (gg[v][(i + 1) % nn] - gg[v][i]) + (s - gg[v][(i + 1) % nn] + n) % n);
		else
			bst = min(bst, n - (s - gg[v][i] + n) % n);


		if ((gg[v][(i - 1 + nn) % nn] - gg[v][i] + n) % n > (s - gg[v][i] + n) % n)
			bst = min(bst, n - (gg[v][i] - gg[v][(i - 1 + nn) % nn]) + (gg[v][(i - 1 + nn) % nn] - s + n) % n);
		else 
			bst = min(bst, (s - gg[v][i] + n) % n);

		if (bst + k < dp[v][i])
			dp[v][i] = bst + k, go[v][i] = s;
	}
}

int dst(int a, int b) {
	return min(abs(a - b), n - abs(a - b));
}

void genans(int v, int e, int s) {
	if (gg[v].size() == 1) {
		ansv.push_back(gg[v][0]);
		return;
	}
	memset(was, 0, sizeof(was));
	int x = lower_bound(gg[v].begin(), gg[v].end(), s) - gg[v].begin();
	if (x == (int)gg[v].size())
		x = 0;
	vector<int> tmpans1;
	vector<int> tmpans2;
	int now = x;
	while (now != e) {
		was[now] = 1;
		tmpans1.push_back(gg[v][now]);
		++now;
		if (now == (int)gg[v].size())
			now = 0;
	}
	do {
		--now;
		if (now == -1)
			now = gg[v].size() - 1;
		if (!was[now]) {
			was[now] = 1;
			tmpans1.push_back(gg[v][now]);
		}
	} while (now != e);
	x = upper_bound(gg[v].begin(), gg[v].end(), s) - gg[v].begin();
	--x;
	memset(was, 0, sizeof(was));
	if (x == -1)
		x = (int)gg[v].size() - 1;
	now = x;
	while (now != e) {
		was[now] = 1;
		tmpans2.push_back(gg[v][now]);
		--now;
		if (now == -1)
			now = gg[v].size() - 1;
	}
	do {
		++now;
		if (now == (int)gg[v].size())
			now = 0;
		if (!was[now]) {
			was[now] = 1;
			tmpans2.push_back(gg[v][now]);
		}
	} while (now != e);
	int dd1 = dst(s, tmpans1[0]);
	for (int i = 0; i < (int)tmpans1.size() - 1; ++i)
		dd1 += dst(tmpans1[i], tmpans1[i + 1]);
	int dd2 = dst(s, tmpans2[0]);
	for (int i = 0; i < (int)tmpans2.size() - 1; ++i)
		dd2 += dst(tmpans2[i], tmpans2[i + 1]);
	if (dd2 < dd1)
		tmpans1 = tmpans2;
	reverse(tmpans1.begin(), tmpans1.end());
	for (int i = 0; i < (int)tmpans1.size(); ++i)
		ansv.push_back(tmpans1[i]);
}

int main() {
	int s;
	scanf("%d%d", &n, &s);
	if (n == 1) {
		cout << 0 << "\n";
		cout << "+0\n";
		return 0;
	}
	--s;
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		vv.push_back(a[i]);
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i = 0; i < n; ++i)
		a[i] = lower_bound(vv.begin(), vv.end(), a[i]) - vv.begin() + 1;
	for (int i = 0; i < n; ++i)
		gg[a[i]].push_back(i);
	int cc = vv.size() + 1;
	vv.clear();
	gg[0].push_back(s);
	for (int i = 0; i < cc; ++i) {
		dp[i].resize(gg[i].size(), (int)1e8);
		go[i].resize(gg[i].size(), -1);
	}
	dp[0][0] = 0;
	go[0][0] = -1;

	for (int i = 1; i < cc; ++i) {
		for (int j = 0; j < (int)gg[i - 1].size(); ++j)
			upd(i, gg[i - 1][j], dp[i - 1][j]);
	}

	int ans = 1e8;
	int ansp = -1;
	for (int i = 0; i < (int)gg[cc - 1].size(); ++i) {
		if (dp[cc - 1][i] < ans)
			ans = dp[cc - 1][i], ansp = gg[cc - 1][i];
	}
	printf("%d\n", ans);
	for (int i = cc - 1; i > 0; --i) {
		int xx = lower_bound(gg[i].begin(), gg[i].end(), ansp) - gg[i].begin();
		genans(i, xx, go[i][xx]);
		ansp = go[i][xx];
	}
	ansv.push_back(s);
	reverse(ansv.begin(), ansv.end());
	for (int i = 0; i < (int)ansv.size() - 1; ++i) {
		int d = ansv[i + 1] - ansv[i];
		if (d < 0) {
			if (abs(d) > abs(d + n))
				d = d + n;
		}
		else {
			if (abs(d) > abs(d - n))
				d = d - n;
		}
		if (d >= 0)
			printf("+%d\n", d);
		else
			printf("%d\n", d);
	}

	return 0;
}