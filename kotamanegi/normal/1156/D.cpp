#define _CRT_SECURE_NO_WARNINGS
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
#include <omp.h>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
#define ll long long
tuple<ll, ll, ll> union_tree[2][300000];
int union_find(int a,int c) {
	if (get<0>(union_tree[c][a]) == a) return a;
	return get<0>(union_tree[c][a]) = union_find(get<0>(union_tree[c][a]),c);
}
int union_merge(int a, int b,int c) {
	a = union_find(a,c);
	b = union_find(b,c);
	if (a == b) return 0;
	get<1>(union_tree[c][b]) += get<1>(union_tree[c][a]);
	get<1>(union_tree[c][a]) = 0;
	get<0>(union_tree[c][a]) = get<0>(union_tree[c][b]);
	return 0;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		union_tree[0][i] = make_tuple(i, 1, 0);
		union_tree[1][i] = make_tuple(i, 1, 0);
	}
	vector<tuple<ll, ll, ll>> edges;
	REP(i, n-1) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges.push_back(make_tuple(a, b, c));
	}
	for (int i = 0; i < edges.size(); ++i) {
		union_merge(get<0>(edges[i]), get<1>(edges[i]), get<2>(edges[i]));
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (union_find(i, 0) == i) {
			//_
			ans += get<1>(union_tree[0][i]) * (get<1>(union_tree[0][i]) - 1LL);
		}
		if (union_find(i, 1) == i) {
			//_
			ans += get<1>(union_tree[1][i]) * (get<1>(union_tree[1][i]) - 1LL);
		}
		long long next_itr = union_find(i, 1);
		ans += (get<1>(union_tree[0][union_find(i,0)]) - 1LL) * ((get<1>(union_tree[1][next_itr]))-1LL);
	}
	cout << ans << endl;
	return 0;
}