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
int sizing;
int seg_tree[seg_size * 4];
int seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (w_r <= n_l || n_r <= w_l) return 0;
	return max(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r));
}
int n;
int cnter[200000];
int main() {
	int test_case;
	scanf("%d", &test_case);
	REP(t, test_case) {
		scanf("%d", &n);
		sizing = 1;
		while (sizing <= n) {
			sizing *= 2;
		}
		REP(t, sizing + 1) {
			seg_tree[t + sizing] = 0;
		}
		REP(i, n) {
			scanf("%d", &seg_tree[sizing + i]);
		}
		for (int i = sizing - 1; i >= 1; --i) {
			seg_tree[i] = max(seg_tree[i * 2], seg_tree[i * 2 + 1]);
		}
		REP(i, n) {
			cnter[i+1] = 0;
		}
		int m;
		scanf("%d", &m);
		REP(q, m) {
			int a, b;
			scanf("%d%d", &a, &b);
			cnter[b] = max(cnter[b], a);
		}
		for (int i = n - 1; i >= 1; --i) {
			cnter[i] = max(cnter[i], cnter[i + 1]);
		}
		int now = 0;
		int ans = 0;
		while (now != n) {
			if (seg_tree[sizing + now] > cnter[1]) {
				ans = -1;
				break;
			}
			int bot = 1;
			int top = n - now + 1;
			while (top - bot > 1) {
				int mid = (bot + top) / 2;
				int judge = 0;
				{
					int now_max_value = seg_find(1, 0, sizing, now, now + mid);
					if (cnter[mid] >= now_max_value) {
						judge = 1;
					}
					else {
						judge = 0;
					}
				}
				if (judge == 0) {
					top = mid;
				}
				else {
					bot = mid;
				}
			}
			ans++;
			now += bot;
		}

		printf("%d\n", ans);
	}
}