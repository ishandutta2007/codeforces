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
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
#define int long long
set<pair<int, int>> bridges;
vector<int> vertexs[300000];
pair<long long, pair<long long, long long >> union_tree[300000];
long long union_find(long long now) {
	if (union_tree[now].first == now) return now;
	return union_tree[now].first = union_find(union_tree[now].first);
}
void union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	if (a == b) return;
	union_tree[a].second = make_pair(union_tree[a].second.first + union_tree[b].second.first,union_tree[a].second.second + union_tree[b].second.second);
	union_tree[b].first = union_tree[a].first;
	union_tree[b].second = make_pair(0,0);
	return;
}
int pre[300000];
int low[300000];
int now_itr = 1;
void dfs(int now,int back) {
	pre[now] = now_itr;
	now_itr++;
	low[now] = pre[now];
	for (int q = 0; q < vertexs[now].size(); ++q) {
		int go = vertexs[now][q];
		if (go == back) continue;
		if (pre[go] != 0) {
			low[now] = min(low[now], low[go]);
			continue;
		}
		dfs(go,now);
		if (pre[go] == low[go]) {
			if (now < go) {
				bridges.insert(make_pair(now, go));
			}
			else {
				bridges.insert(make_pair(go, now));
			}
		}
		low[now] = min(low[now], low[go]);
	}
	return;
}
#undef int
vector<int> next_vertexs[300000];
long long can_back[300000];
void dfs_sec(int now, int back) {
	if (union_tree[now].second.second !=  1) {
		can_back[now] = 1;
	}
	REP(q, next_vertexs[now].size()) {
		int go = next_vertexs[now][q];
		if (go == back) continue;
		dfs_sec(go, now);
		can_back[now] = max(can_back[now], can_back[go]);
	}
	return;
}
vector<int> final_vertexs[300000];
long long finding_ans_dfs(long long now,long long back) {
	long long ans = union_tree[now].second.first;
	long long now_max = 0;
	for (int q = 0; q < final_vertexs[now].size(); ++q) {
		int go = final_vertexs[now][q];
		if (go == back) continue;
		now_max = max(now_max, finding_ans_dfs(go, now));
	}
	return ans + now_max;
}
int main(){
#define int long long
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	scanf("%lld%lld", &n, &m);
	REP(i, n) {
		scanf("%lld", &union_tree[i].second.first);
		union_tree[i].first = i;
		union_tree[i].second.second = 1;
	}
	REP(i, m)
	{
		int a, b;
		scanf("%lld%lld", &a, &b);
		a--;
		b--;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	int start_point;
	scanf("%lld", &start_point);
	start_point--;
	//first we need to find bridge
	for (int i = 0; i < n; ++i) {
		if (pre[i] == 0) {
			//finding bridges
			dfs(i, -1);
		}
	}
	//now start merging
	for (int i = 0; i < n; ++i) {
		for (int q = 0; q < vertexs[i].size(); ++q) {
			int go = vertexs[i][q];
			if (i > go) continue;
			if (bridges.find(make_pair(i, go)) != bridges.end()) {
				continue;
			}
			union_merge(i, go);
		}
	}
	start_point = union_find(start_point);
	for (auto i = bridges.begin(); i != bridges.end(); ++i) {
		int a = (*i).first;
		int b = (*i).second;
		a = union_find(a);
		b = union_find(b);
		next_vertexs[a].push_back(b);
		next_vertexs[b].push_back(a);
	}
	dfs_sec(start_point, -1);
	for (auto i = bridges.begin(); i != bridges.end(); ++i) {
		int a = (*i).first;
		int b = (*i).second;
		a = union_find(a);
		b = union_find(b);
		if (can_back[a] == 1 && can_back[b] == 1) {
			union_merge(a, b);
		}
	}
	for (auto i = bridges.begin(); i != bridges.end(); ++i) {
		int a = (*i).first;
		int b = (*i).second;
		a = union_find(a);
		b = union_find(b);
		if (!(can_back[a] == 1 && can_back[b] == 1)) {
			final_vertexs[a].push_back(b);
			final_vertexs[b].push_back(a);
		}
	}
	printf("%lld\n", finding_ans_dfs(union_find(start_point), -1));
	return 0;
}