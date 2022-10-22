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
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define int long long
long long seg_tree[seg_size * 4];
long long seg_go[seg_size * 4];
long long seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (w_r <= n_l || n_r <= w_l) return 0;
	return seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r) + seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
}
void seg_set(long long now) {
	seg_tree[now] = seg_tree[now * 2] + seg_tree[now * 2 + 1];
	if (now != 1) seg_set(now / 2);
}
#undef int
int main(){
	iostream::sync_with_stdio(false);
#define int long long
	int n;
	cin >> n;
	vector<pair<int, int>> inputs;
	map<int, int> x, y;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(b, a));
		y[b] = 0;
		x[a] = 0;
	}
	int itr = 0;
	for (auto i = x.begin(); i != x.end(); ++i) {
		i->second = itr;
		itr++;
	}
	itr = 0;
	for (auto i = y.begin(); i != y.end(); ++i) {
		i->second = itr;
		itr++;
	}
	REP(i, n) {
		inputs[i] = make_pair(y[inputs[i].first], x[inputs[i].second]);
		seg_go[(inputs[i].second + seg_size)]++;
		if (seg_go[(inputs[i].second + seg_size)] == 1) {
			seg_tree[(inputs[i].second + seg_size)]++;
			seg_set((inputs[i].second + seg_size) / 2);
		}
	}
	sort(inputs.begin(), inputs.end());
	long long ans = 0;
	for (int i = 0; i < inputs.size(); ++i) {
		if (i != 0 && inputs[i].first == inputs[i - 1].first) {
			ans += seg_find(1, 0, seg_size, inputs[i-1].second+1, inputs[i].second + 1) * seg_find(1, 0, seg_size, inputs[i].second, seg_size);
		}
		else {
			ans += seg_find(1, 0, seg_size, 0, inputs[i].second + 1) * seg_find(1, 0, seg_size, inputs[i].second, seg_size);
		}
		seg_go[(inputs[i].second + seg_size)]--;
		if (seg_go[(inputs[i].second + seg_size)] == 0) {
			seg_tree[(inputs[i].second + seg_size)]--;
			seg_set((inputs[i].second + seg_size) / 2);
		}
	}
	cout << ans << endl;
	return 0;
}