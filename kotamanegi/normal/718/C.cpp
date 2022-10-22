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
struct Kake {
	long long a, b, c, d;
	const Kake operator+(const Kake x) {
		return Kake{ (a + x.a) % MAX_MOD,(b + x.b) % MAX_MOD,(c + x.c) % MAX_MOD,(d + x.d) % MAX_MOD };
	}
	const Kake operator*(const Kake x) {
		return Kake{ (a * x.a + b * x.c) % MAX_MOD,(a * x.b + b * x.d) % MAX_MOD,(c * x.a + d * x.c) % MAX_MOD,(c * x.b + d * x.d) % MAX_MOD };
	}
	const bool operator!=(const Kake x) {
		return (x.a != a|| x.b != b || x.c != c || x.d != d);
	}
};
Kake seg_tree[seg_size*4];
Kake lazy_tree[seg_size * 4];
Kake powing(int n) {
	Kake base = Kake{ 1,1,1,0 };
	Kake ans = Kake{ 1,0,0,1 };
	while (n != 0) {
		if (n % 2 == 1) {
			ans = ans * base;
		}
		base = base * base;
		n /= 2;
	}
	return ans;
}
void seg_set(int now);
void merge(int now) {
	seg_tree[now] = seg_tree[now] * lazy_tree[now];
	lazy_tree[now * 2] = lazy_tree[now * 2] * lazy_tree[now];
	lazy_tree[now * 2 + 1] = lazy_tree[now * 2 + 1] * lazy_tree[now];
	lazy_tree[now] = Kake{ 1,0,0,1 };
	seg_set(now / 2);
}
void seg_set(int now) {
	if (now == 0) return;
	if (lazy_tree[now * 2] != Kake{ 1,0,0,1 })merge(now * 2);
	if (lazy_tree[now * 2 + 1] != Kake{ 1,0,0,1 })merge(now * 2 + 1);
	seg_tree[now] = seg_tree[now * 2] + seg_tree[now * 2 + 1];
	if (now >= 2) {
		seg_set(now / 2);
	}
}
Kake seg_find(int now, int n_l, int n_r, int w_l, int w_r, Kake setting) {
	if (w_l <= n_l && n_r <= w_r) {
		lazy_tree[now] = lazy_tree[now] * setting;
	}
	merge(now);
	if (w_l <= n_l && n_r <= w_r) {
		return seg_tree[now];
	}
	if (w_r <= n_l || n_r <= w_l) {
		return Kake{ 0,0,0,0 };
	}
	return seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r, setting) + seg_find(now * 2 + 1, (n_l + n_r)/2, n_r, w_l, w_r, setting);
}
int main(){
	iostream::sync_with_stdio(false);
#define int long long
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		int a;
		cin >> a;
		a--;
		seg_tree[i + seg_size] = powing(a);
	}
	REP(q, seg_size * 4) {
		lazy_tree[q] = Kake{ 1,0,0,1 };
	}
	for (int i = seg_size - 1; i >= 0; --i) {
		seg_tree[i] = seg_tree[i * 2] + seg_tree[i * 2 + 1];
	}
	REP(i, m) {
		int a;
		cin >> a;
		if (a == 2) {
			int b, c;
			cin >> b >> c;
			Kake ans = seg_find(1, 0, seg_size, b - 1, c, Kake{ 1,0,0,1 });
			cout << ans.a << endl;
		}
		else {
			int b, c, d;
			cin >> b >> c >> d;
			seg_find(1, 0, seg_size, b - 1, c, powing(d));
		}
	}
}