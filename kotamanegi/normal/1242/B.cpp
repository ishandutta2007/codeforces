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
pair<int,vector<int>> union_tree[200000];
int union_find(int now) {
	if (union_tree[now].first == now) return now;
	return union_tree[now].first = union_find(union_tree[now].first);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	if (a == b) return 0;
	if (union_tree[a].second.size() < union_tree[b].second.size()) swap(a, b);
	while (union_tree[b].second.size() != 0) {
		union_tree[a].second.push_back(union_tree[b].second.back());
		union_tree[b].second.pop_back();
	}
	union_tree[b].first = union_tree[a].first;
	return 0;
}
set<pair<int, int>> bad_edges;

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	REP(i, n) {
		union_tree[i].first = i;
		union_tree[i].second.push_back(i);
	}
	REP(i, m) {
		long long a, b;
		cin >> a >> b;
		a--; b--;
		if (a > b) swap(a, b);
		bad_edges.insert(make_pair(a, b));
	}
	vector<pair<int, int>> gogo[2];
	for (int i = 0; i < n; ++i) {
		int getting = 0;
		for (int q = 0; q < gogo[0].size(); ++q) {
			if (union_find(gogo[0][q].first) != union_find(i)) {
				int going = union_find(gogo[0][q].first);
				int ok = 0;
				for (int j = 0; j < union_tree[going].second.size(); ++j) {
					if (bad_edges.find(make_pair(union_tree[going].second[j], i)) == bad_edges.end()) {
						ok = 1;
						break;
					}
				}
				if (ok == 0) continue;
				union_merge(gogo[0][q].first, i);
				if (getting == 0) {
					getting = 1;
					gogo[0][q].first = i;
				}
				else {
					gogo[0][q].second = 1;//die
				}
			}
		}
		if (getting == 0) {
			gogo[0].push_back(make_pair(i, 0));
		}
		while (gogo[0].empty() == false) {
			if (gogo[0].back().second == 0) {
				gogo[1].push_back(gogo[0].back());
			}
			gogo[0].pop_back();
		}
		swap(gogo[0], gogo[1]);
	}
	set<int> final_ans;
	REP(i, n) {
		final_ans.insert(union_find(i));
	}
	cout << final_ans.size() - 1 << endl;
}