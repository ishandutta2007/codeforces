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

const int MAXN = 160000;
const ld eps = 1e-8;

int t[MAXN];
int p[MAXN];
ll T;
ld mn[MAXN];
ld mx[MAXN];
int n;
vector<int> cmpr;
vector<int> vv;
ll sb[MAXN];
ll st[MAXN];
int gr[MAXN];
int p2[MAXN]; 

bool cmp1(int a, int b) {
	return (ll)t[a] * (ll)p[b] < (ll)t[b] * (ll)p[a];
}

int check(ld c) {
	for (int i = 0; i < (int)cmpr.size(); ++i)
		mn[i] = 1e8 + 100, mx[i] = 0;
	for (int i = 0; i < n; ++i) {
		ld mx1 = p[i] * (1.0 - c * ((ld)sb[gr[i]] + t[i]) / T);
		ld mn1 = p[i] * (1.0 - c * (ld)sb[gr[i] + 1] / T);
		mn[p2[i]] = min(mn[p2[i]], mn1);
		mx[p2[i]] = max(mx[p2[i]], mx1);
	}
	ld mx1 = 0;
	for (int i = 0; i < (int)cmpr.size(); ++i) {
		if (mx1 > mn[i])
			return 0;
		mx1 = max(mx1, mx[i]);
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i), cmpr.push_back(p[i]);
	sort(cmpr.begin(), cmpr.end());
	cmpr.resize(unique(cmpr.begin(), cmpr.end()) - cmpr.begin());
	for (int i = 0; i < n; ++i)
		p2[i] = lower_bound(cmpr.begin(), cmpr.end(), p[i]) - cmpr.begin();
	for (int i = 0; i < n; ++i)
		scanf("%d", t + i);
	for (int i = 0; i < n; ++i)
		vv.push_back(i);
	sort(vv.begin(), vv.end(), cmp1);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		st[cnt] += t[vv[i]];
		gr[vv[i]] = cnt;
		if (i == n - 1 || cmp1(vv[i], vv[i + 1])) {
			++cnt;
			sb[cnt] += sb[cnt - 1] + st[cnt - 1];
		}
	}
	T = sb[cnt];
	ld l = 0;
	ld r = 1;
	while (r - l > eps) {
		ld m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << l << "\n";
	return 0;
}