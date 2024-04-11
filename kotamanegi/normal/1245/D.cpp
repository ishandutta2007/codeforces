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
pair<long long, long long> union_tree[200000];
long long cost_power[200000];
long long cost_line[200000];
long long union_find(long long now) {
	if (union_tree[now].first == now) return now;
	return union_tree[now].first = union_find(union_tree[now].first);
}
long long union_merge(long long a, long long b) {
	a = union_find(a);
	b = union_find(b);
	if (a == b) return 0;
	union_tree[a].second |= union_tree[b].second;
	union_tree[b].first = union_tree[a].first;
	return 0;
}
int main(){
	iostream::sync_with_stdio(false);
#define int long long
	int n;
	cin >> n;
	vector<pair<long long, long long>> inputs;
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(a, b));
	}
	REP(i, n) {
		cin >> cost_power[i];
	}
	REP(i, n) {
		cin >> cost_line[i];
		union_tree[i].first = i;
		union_tree[i].second = 0;
	}
	vector<tuple<long long, long long, long long, long long>> events;
	REP(i, n) {
		events.push_back(make_tuple(cost_power[i], 0, i+1, -1));
		for (int q = i + 1; q < n; ++q) {
			long long final_cost = llabs(inputs[i].first - inputs[q].first) + llabs(inputs[i].second - inputs[q].second);
			final_cost *= (cost_line[i] + cost_line[q]);
			events.push_back(make_tuple(final_cost, 1, i+1, q+1));
		}
	}
	sort(events.begin(), events.end());
	vector<pair<int, int>> links;
	vector<int> power_station;
	long long ans = 0;
	REP(i, events.size()) {
		if (get<1>(events[i]) == 0) {
			int target = union_find(get<2>(events[i]));
			if (union_tree[target].second == 0) {
				union_tree[target].second = 1;
				power_station.push_back(get<2>(events[i]));
				ans += get<0>(events[i]);
			}
		}
		else {
			int target_a = union_find(get<2>(events[i]));
			int target_b = union_find(get<3>(events[i]));
			if (union_tree[target_a].second + union_tree[target_b].second == 2) continue;
			if (union_find(get<2>(events[i])) != union_find(get<3>(events[i]))) {
				union_merge(get<2>(events[i]), get<3>(events[i]));
				links.push_back(make_pair(get<2>(events[i]), get<3>(events[i])));
				ans += get<0>(events[i]);
			}
		}
	}
	cout << ans << endl;
	cout << power_station.size() << endl;
	REP(i, power_station.size()) {
		cout << power_station[i] << " ";
	}
	cout << endl;
	cout << links.size() << endl;
	REP(i, links.size()) {
		cout << links[i].first << " " << links[i].second << endl;
	}
}