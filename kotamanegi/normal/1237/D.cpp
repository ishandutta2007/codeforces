//J^!w

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
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
int ans[300000];
long long seg_tree[seg_size*4];
long long seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (w_r <= n_l || n_r <= w_l) return LONG_INF;
	return min(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r));
}
long long seg_set(long long now) {
	seg_tree[now] = min(seg_tree[now * 2], seg_tree[now * 2 + 1]);
	if (now != 1) seg_set(now / 2);
	return 0;
}
long long seconds[seg_size * 4];
long long seg(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seconds[now];
	if (w_r <= n_l || n_r <= w_l) return 0;
	return max(seg(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), seg(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r));
}
long long segt(long long now) {
	seconds[now] = max(seconds[now * 2], seconds[now * 2 + 1]);
	if (now != 1) segt(now / 2);
	return 0;
}
int main() {
#define int long long
	int n;
	vector<int> inputs;
	scanf("%lld", &n);
	REP(i, n) {
		int a;
		scanf("%lld", &a);
		inputs.push_back(a);
	}
	REP(q, 2) {
		REP(i, n) {
			inputs.push_back(inputs[i]);
		}
	}
	REP(i, seg_size * 4) {
		seg_tree[i] = LONG_INF;
	}
	REP(i, inputs.size()) {
		seg_tree[(i + seg_size)] = inputs[i];
		//seg_set((i + seg_size) / 2);
		seconds[(i + seg_size)] = inputs[i];
		//segt((i + seg_size) / 2);
	}
	for (int i = seg_size; i >= 0; --i) {
		seg_tree[i] = min(seg_tree[i * 2], seg_tree[i * 2 + 1]);
		seconds[i] = max(seconds[i * 2], seconds[i * 2 + 1]);
	}
	int now_ans = 1;
	int now_max = inputs[n-1];
	for (int i = n; i < inputs.size(); ++i) {
		if (now_max > inputs[i] * 2) {
			break;
		}
		now_max = max(now_max, inputs[i]);
		now_ans++;
	}
	ans[n - 1] = now_ans;
	for (int i = n; i < inputs.size();++i) {
		ans[i] = now_ans - (i - n + 1);
	}
	for (long long i = n - 2; i >= 0; --i) {
		long long bot = 2 * n - 1;
		long long top = i;
		while (bot - top > 1) {
			long long mid = (bot + top) / 2;
			if (seg(1, 0, seg_size, i + 1, mid + 1) >= inputs[i]) {
				bot = mid;
			}
			else {
				top = mid;
			}
		}
		top = bot;
		bot = i;
		if (inputs[i] <= seg_find(1, 0, seg_size, i + 1, top)*2) {
			ans[i] = ans[top] + (top - i);
		}
		else {
			while (top - bot > 1) {
				long long mid = (top + bot) / 2;
				long long hoge = seg_find(1, 0, seg_size, i + 1, mid + 1);
				if (inputs[i] > hoge * 2) {
					top = mid;
				}
				else {
					bot = mid;
				}
			}
			ans[i] = bot - i+1;
		}
	}
	REP(i, n) {
		if (ans[i] >= 2 * n) ans[i] = -1;
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}