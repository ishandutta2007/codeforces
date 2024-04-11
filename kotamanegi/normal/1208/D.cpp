/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
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
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
long long seg_tree[seg_size*4] = {};
long long seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (w_l >= n_r||w_r <= n_l) return 0;
	return seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r) + seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
}
long long seg_merge(long long now) {
	seg_tree[now] = seg_tree[now * 2] + seg_tree[now * 2 + 1];
	if (now != 1) seg_merge(now / 2);
	return 0;
}
int main() {
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> hoge;
	REP(i, n) {
		long long a;
		cin >> a;
		hoge.push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		seg_tree[seg_size+i] = i;
		seg_merge((seg_size + i) / 2);
	}
	reverse(hoge.begin(), hoge.end());
	vector<long long> ans;
	REP(i, hoge.size()) {
		long long bot = 1;
		long long top = n + 1;
		while (top - bot > 1) {
			long long mid = (top + bot) / 2;
			if (seg_find(1, 0, seg_size, 1, mid) > hoge[i]) {
				top = mid;
			}
			else {
				bot = mid;
			}
		}
		ans.push_back(bot);
		seg_tree[(seg_size + bot)] = 0;
		seg_merge((seg_size + bot) / 2);
	}
	reverse(ans.begin(), ans.end());
	cout << ans[0];
	REP(i, ans.size()-1) {
		cout << " ";
		cout << ans[i + 1];
	}
	cout << endl;
}