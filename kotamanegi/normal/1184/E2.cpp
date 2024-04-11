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
int final_ans[1100000] = {};
int union_tree[200000];
int union_find(int now) {
	if (union_tree[now] == now) return now;
	return union_tree[now] = union_find(union_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	if (a == b) return 0;
	union_tree[a] = b;
	return 1;
}
queue<tuple<int, int, int, int, int, int>> nexter[200002];// bot/top/city a/city b/edge_itr/edge_cost
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int, int>> edges;
	REP(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		final_ans[i] = 1e9+1;
		a--;
		b--;
		edges.push_back(make_tuple(c, a, b, i));
	}
	sort(edges.begin(), edges.end());
	vector<tuple<int, int, int,int>> required;
	REP(i, n) {
		union_tree[i] = i;
	}
	for (int q = 0; q < edges.size(); ++q) {
		if (union_merge(get<1>(edges[q]), get<2>(edges[q])) == 1) {
			required.push_back(edges[q]);
		}
		else {
			nexter[(n - 2) / 2].push(make_tuple(n - 2, -1, get<1>(edges[q]), get<2>(edges[q]), get<3>(edges[q]), get<0>(edges[q])));
		}
	}
	REP(te, 30) {
		REP(i, n) {
			union_tree[i] = i;
		}
		for (int q = 0; q < required.size(); ++q) {
			union_merge(get<1>(required[q]), get<2>(required[q]));
			while (nexter[q].empty() == false) {
				tuple<int, int, int, int, int, int> now = nexter[q].front();
				nexter[q].pop();
				if (get<0>(now) - get<1>(now) == 1) {
					//ok
					final_ans[get<4>(now)] = get<0>(required[get<0>(now)]);
					continue;
				}
				if (union_find(get<2>(now)) == union_find(get<3>(now))) {
					get<0>(now) = q;
				}
				else {
					get<1>(now) = q;
				}
				nexter[(get<0>(now) + get<1>(now)+1) / 2].push(now);
			}
			queue<tuple<int, int, int, int, int, int>>().swap(nexter[q]);
		}
	}
	for (int q = required.size() - 2; q >= 0; --q) {
		final_ans[get<3>(required[q])] = min(final_ans[get<3>(required[q])], final_ans[get<3>(required[q + 1])]);
	}
 	REP(i, m) {
		if (final_ans[i] != 1e9+1) {
			printf("%d\n", final_ans[i]);
		}
	}
}