#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <stack>
#include <iostream>
#include <functional>
#include <fstream>

#define mp make_pair
#define pb push_back

using ll = long long;
using ld = long double;

using namespace std;

const int MAXN = 200001;

vector <int> e[MAXN];
int f[MAXN];
int p[MAXN];

bool bad[MAXN];

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void gcd2(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	gcd2(b, a % b, y, x);
	y -= (a / b) * x;
}


int n, m;

vector <int> ans;

void calc(int x, int y) {
	if (f[x] < f[y] + e[x].size()) {
		f[x] = f[y] + e[x].size();
		p[x] = y;
	}
}

void edge(int x, int y) {
	int c1, c2;
	gcd2(x, m, c1, c2);
	c1 %= m;
	if (c1 < 0) c1 += m;
	int vl = ((ll)x * (ll)c1) % m;
	assert(y % vl == 0);
	ans.push_back(((ll)c1 * (ll)(y / vl)) % m);
}

int last = -1;

void ad(int x) {
	if (last != -1) {
		edge(x, last);
	}
	last = x;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cout.setf(ios::fixed); cout.precision(20);
	cin >> n >> m;
	memset(bad, 0, sizeof(bad));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bad[x] = true;
	}
	for (int i = 0; i < m; i++) {
		if (bad[i]) continue;
		e[gcd(i, m)].push_back(i);
	}
	p[1] = 0;
	f[1] = e[1].size();
	for (int i = 2; i <= m; i++) {
		if (e[i].size() == 0) continue;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				calc(i, j);
				if (j != 1) calc(i, i / j);
			}
		}
	}

	int mxid = 1;
	for (int i = 2; i <= m; i++) {
		if (f[i] > f[mxid]) mxid = i;
	}

	int mf = f[mxid];

	while (mxid != 0) {
		for (int i = 0; i < e[mxid].size(); i++) ad(e[mxid][i]);
		mxid = p[mxid];
	}

	ans.push_back(last);
	assert(ans.size() == mf);

	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}