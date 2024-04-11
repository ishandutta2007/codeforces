#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int memo[50000];
int seg_tree[seg_size * 8];
int lazy_tree[seg_size * 8];
int seg_setter(int now) {
	REP(q, 2) {
		int ta = now * 2 + q;
		seg_tree[ta] += lazy_tree[ta];
		lazy_tree[ta * 2] += lazy_tree[ta];
		lazy_tree[ta * 2 + 1] += lazy_tree[ta];
		lazy_tree[ta] = 0;
	}
	seg_tree[now] = max(seg_tree[now * 2], seg_tree[now * 2 + 1]);
	if (now != 1) seg_setter(now / 2);
	return 0;
}
int seg_find(int now, int n_l, int n_r, int w_l, int w_r, int settings) {
	seg_tree[now] += lazy_tree[now];
	lazy_tree[now * 2] += lazy_tree[now];
	lazy_tree[now * 2 + 1] += lazy_tree[now];
	lazy_tree[now] = 0;
	if (w_l <= n_l && n_r <= w_r) {
		lazy_tree[now] = settings;
		seg_tree[now] += lazy_tree[now];
		lazy_tree[now * 2] += lazy_tree[now];
		lazy_tree[now * 2 + 1] += lazy_tree[now];
		lazy_tree[now] = 0;
		if (settings != 0) seg_setter(now / 2);
		return seg_tree[now];
	}
	if (w_r <= n_l || n_r <= w_l) return 0;
	return max(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r, settings), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r, settings));
}
int cnt[50000];
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> inputs;
	REP(i, n) {
		int a;
		cin >> a;
		a--;
		inputs.push_back(a);
	}
	REP(i, k) {
		REP(t, n) {
			cnt[t] = 0;
		}
		REP(q, seg_size * 4) {
			seg_tree[q] = 0;
			lazy_tree[q] = 0;
		}
		REP(q, n + 1) {
			seg_tree[(seg_size + q)] += memo[q];
		}
		for (int q = seg_size - 1; q >= 1; --q) {
			seg_tree[q] = max(seg_tree[q * 2], seg_tree[q * 2 + 1]);
		}
		for (int j = 0; j < n; ++j) {
			int target = inputs[j];
			seg_find(1, 0, seg_size, cnt[target], j + 1, 1);
			cnt[target] = j + 1;
			memo[j + 1] = seg_find(1, 0, seg_size, 0, j + 1, 0);
		}
	}
	cout << memo[n] << endl;
}