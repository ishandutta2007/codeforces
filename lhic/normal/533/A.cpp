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
const int MAXN = 510000;

using namespace std;
const int INF = 1000000001;
int h[MAXN];
vector<int> vv[MAXN];
int was[MAXN];
int nn[MAXN];
vector<int> eds[MAXN];
int gg[MAXN];
vector<int> go[MAXN];

multiset<int> ss;
int n, k;


void dfs(int v, int mn1, int mn2) {
	if (h[v] < h[mn2])
		mn2 = v;
	if (h[mn2] < h[mn1])
		swap(mn2, mn1);
	vv[mn1].push_back(h[mn2]);
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u])
			dfs(u, mn1, mn2);
	}
}

bool cmp(int a, int b) {
	return h[a] < h[b];
}



void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &h[i]);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &nn[i]);
}


void gentest() {
	n = rand() % 4 + 1;
	for (int i = 0; i < n; ++i)
		h[i] = rand() % 5 + 1;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 1; i < n; ++i) {
		int a = rand() % i;
		eds[a].push_back(i);
		eds[i].push_back(a);
	}
	k = rand() % 7 + 1;
	for (int i = 0; i < k; ++i)
		nn[i] = rand() % 5 + 1;
}

int en[100];

void dfs2(int v, int mn) {
	mn = min(mn, h[v]);
	was[v] = 1;
	for (int i = k - 1; i >= 0; --i)
		if (!en[i] && nn[i] <= mn) {
			en[i] = 1;
			break;
		}
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u])
			dfs2(u, mn);
	}
}

int solve2() {
	sort(nn, nn + k);
	int ans = 100;
	for (int i = 0; i < n; ++i) {
		for (int kk = 0; kk < 10; ++kk) {
			h[i] += kk;
			memset(en, 0, sizeof(en[0]) * k);
			memset(was, 0, sizeof(was[0]) * n);
			dfs2(0, 100);
			h[i] -= kk;
			int fl = 0;
			for (int iu = 0; iu < k; ++iu)
				if (!en[iu])
					fl = 1;
			if (!fl) {
				ans = min(ans, kk);
			}
		}
	}

	if (ans == 100)
		return -1;
	return ans;
}



int solve() {
	h[n] = 1000000001;
	h[n + 1] = 1000000001;
	sort(nn, nn + k);
	memset(was, 0, sizeof(was[0]) * n);
	for (int i = 0; i < n; ++i)
		vv[i].clear(), go[i].clear();
	ss.clear();
	dfs(0, n, n + 1);
	for (int i = 0; i < n; ++i)
		sort(vv[i].begin(), vv[i].end());
	/*for (int i = 0; i < n; ++i) {
		cout << i << ":\n";
		for (int j = 0; j < (int)vv[i].size(); ++j)
			cout << vv[i][j] << " ";
		cout << "\n";
	}*/


	for (int i = 0; i < n; ++i)
		gg[i] = i;
	sort(gg, gg + n, cmp);
	//for (int i = 0; i < n; ++i)
	//	cout << gg[i] << " ";
	//cout << "\n";

	int now = 0;
	for (int i = 0; i < n; ++i) {
		int k2 = gg[i];
		int cnt = 0;
		while (cnt < (int)vv[k2].size() && now < k && nn[now] <= h[k2])
			go[i].push_back(nn[now++]), ++cnt;
		reverse(go[i].begin(), go[i].end());
	}
	if (now == k)
		return 0;
	for (int i = now; i < k; ++i)
		ss.insert(nn[i]);

	int ans = INF;
	int cc = 0;

	for (int i = n - 1; i >= 0; --i) {
		int k2 = gg[i];
		for (int j = 0; j < (int)go[i].size(); ++j) {
			if (!cc)
				ss.insert(go[i][j]);
			else
				--cc;
		}

		/*cout << k2 << " " << ss.size() << "\n";
		cout << "SS\n";
		for (int ii: ss)
			cout << ii << " ";
		cout << "\n";*/


		if ((int)ss.size() <= (int)vv[k2].size()) {
			auto it = ss.end();
			--it;
			int now = vv[k2].size() - 1;
			int fl = 0;
			while (true) {
				if (*it > vv[k2][now]) {
					fl = 1;
					break;
				}
				if (it == ss.begin())
					break;
				--it;
				--now;
			}
			if (!fl)
				ans = min(ans, *ss.rbegin() - h[k2]);
		}



		for (int i = 0; i < (int)vv[k2].size(); ++i) {
			auto it = ss.upper_bound(h[k2]);
			if (it == ss.begin())
				++cc;
			else {
				--it;
				ss.erase(it);
			}
		}
	}

	if (ans == INF)
		return -1;
	else
		return ans;
}






int main() {
	read();
	cout << solve();
/*	do
		gentest();
	while (solve() == solve2());

	cout << n << "\n";
	for (int i = 0; i < n; ++i)
		cout << h[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (int)eds[i].size(); ++j)
			if (eds[i][j] > i)
				cout << i + 1 << " " << eds[i][j] + 1 << "\n";
	cout << k << "\n";
	for (int i = 0; i < k; ++i)
		cout << nn[i] << " ";
	cout << "\n";
	cout << solve() << " " << solve2() << "\n";*/

	return 0;
}