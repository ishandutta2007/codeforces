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

int n, m;
ll a[MAXN];
ll b[MAXN];
ll sum = 0;

vector<pair<ll, int> > vv;

bool cmp(const pair<ll, int> &a, const pair<ll, int>& b) {
	return a.first < b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i), a[i] *= 2, sum += a[i];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
		scanf("%lld", b + i), b[i] *= 2, sum -= b[i];
	sum /= 2;
	int bk = 0;
	ll bst = abs(sum);
	int l = 0;
	int r = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			vv.push_back(make_pair(a[i] + a[j], (i << 12) + (j << 1) + 0));
		}
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j) {
			vv.push_back(make_pair(b[i] + b[j] + sum, (i << 12) + (j << 1) + 1));
		}
	sort(vv.begin(), vv.end(), cmp);
	for (int i = 0; i < (int)vv.size() - 1; ++i) {
		int x1 = vv[i].second & 1;
		int x2 = vv[i + 1].second & 1;
		if (x1 == x2)
			continue;
		if (abs(vv[i].first - vv[i + 1].first) < bst)
			bk = 2, l = i, bst = abs(vv[i].first - vv[i + 1].first);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (abs(sum - (a[i] - b[j])) < bst) {
				bk = 1;
				l = i;
				r = j;
				bst = abs(sum - (a[i] - b[j]));
			}
		}
	}
	cout << bst << "\n";
	cout << bk << "\n";
	if (bk == 1) {
		cout << l + 1 << " " << r + 1 << "\n";
	}
	else if (bk == 2) {
		int x1 = vv[l].second;
		int x2 = vv[l + 1].second;
		if (x1 & 1)
			swap(x1, x2);
		x1 >>= 1;
		x2 >>= 1;
		cout << (x1 & 2047) + 1 << " " << (x2 & 2047) + 1 << "\n";
		x1 >>= 11;
		x2 >>= 11;
		cout << x1 + 1 << " " << x2 + 1 << "\n";
	}

	return 0;
}