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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;

ll a[MAXN];
ll gl[MAXN * 4];
ll gr[MAXN * 4];
ll rmq[MAXN * 4];
ll us[MAXN * 4];
int p[MAXN];

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		gl[v] = a[tl];
		gr[v] = a[tl];
		rmq[v] = a[tl];
		us[v] = 0;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	us[v] = us[v * 2 + 1] + us[v * 2 + 2];
	rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
	gl[v] = gr[v] = rmq[v];
}

void del(int v, int tl, int tr, int x) {
	if (tl + 1 == tr) {
		gl[v] = 0;
		gr[v] = 0;
		rmq[v] = 0;
		us[v] = 1;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		del(v * 2 + 1, tl, m, x);
	else
		del(v * 2 + 2, m, tr, x);
	us[v] = max(us[v * 2 + 1], us[v * 2 + 2]);
	rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	rmq[v] = max(rmq[v], gr[v * 2 + 1] + gl[v * 2 + 2]);
	gl[v] = gl[v * 2 + 1];
	if (us[v * 2 + 1] == 0)
		gl[v] = gl[v * 2 + 1] + gl[v * 2 + 2];
	gr[v] = gr[v * 2 + 2];
	if (us[v * 2 + 2] == 0)
		gr[v] = gr[v * 2 + 1] + gr[v * 2 + 2];
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> p[i], --p[i];
	build(0, 0, n);
	for (int i = 0; i < n; ++i) {
		del(0, 0, n, p[i]);
		cout << rmq[0] << "\n";
	}
	return 0;
}