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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int union_tree[200000];
int union_find(int now) {
	if (union_tree[now] == now) return now;
	return union_tree[now] = union_find(union_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_tree[a] = b;
	return 0;
}
vector<tuple<int, int, int>> edges;
int main() {
	int n, m;
	cin >> n >> m;
	pair<int, int> now;
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i != 0) {
			edges.push_back(make_tuple(c,a, b));
		}
		else {
			now = make_pair(a, b);
		}
	}
	sort(edges.begin(), edges.end());
	edges.push_back(make_tuple(1e9, now.first, now.second));
	for (int q = 1; q <= n; ++q) {
		union_tree[q] = q;
	}
	for (int i = 0; i < edges.size(); ++i) {
		union_merge(get<1>(edges[i]), get<2>(edges[i]));
		if (union_find(now.first) == union_find(now.second)) {
			cout << get<0>(edges[i]) << endl;
			return 0;
		}
	}
}