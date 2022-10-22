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
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
pair<int, int> seg_tree[seg_size * 4];
int lazy_tree[seg_size * 4];
void seg_set(int now);
void denpan(int now) {
	if (lazy_tree[now] == 0) return;
	seg_tree[now].first += lazy_tree[now];
	seg_tree[now].second += lazy_tree[now];
	lazy_tree[now * 2] += lazy_tree[now];
	lazy_tree[now * 2 + 1] += lazy_tree[now];
	lazy_tree[now] = 0;
	seg_set(now / 2);
}
void seg_set(int now) {
	denpan(now * 2);
	denpan(now * 2 + 1);
	seg_tree[now].first = max(seg_tree[now * 2].first, seg_tree[now * 2 + 1].first);
	seg_tree[now].second = min(seg_tree[now * 2].second, seg_tree[now * 2 + 1].second);
	if (now > 1) seg_set(now / 2);
}
pair<int,int> seg_find(int now, int n_l, int n_r, int w_l, int w_r, int setting) {
	if (w_l <= n_l && n_r <= w_r) {
		lazy_tree[now] += setting;
	}
	denpan(now);
	if (w_l <= n_l && n_r <= w_r) {
		return seg_tree[now];
	}
	if (w_r <= n_l || n_r <= w_l) {
		return make_pair(-1e9, 1e9);
	}
	pair<int, int> a = seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r, setting);
	pair<int, int> b = seg_find(now * 2 + 1, (n_l+n_r)/2, n_r, w_l, w_r, setting);
	return make_pair(max(a.first, b.first), min(a.second, b.second));
}
char memorization[1000000];
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int now_itr = 0;
	int cnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'L') {
			now_itr--;
			now_itr = max(now_itr, 0);
		}
		else if (s[i] == 'R') {
			now_itr++;
		}
		else {
			if (memorization[now_itr] == '(') {
				cnt--;
				seg_find(1, 0, seg_size, now_itr, seg_size, -1);
			}
			else if (memorization[now_itr] == ')') {
				cnt++;
				seg_find(1, 0, seg_size, now_itr, seg_size, 1);
			}
			memorization[now_itr] = s[i];
			if (memorization[now_itr] == '(') {
				cnt++;
				seg_find(1, 0, seg_size, now_itr, seg_size, 1);
			}
			else if (memorization[now_itr] == ')') {
				cnt--;
				seg_find(1, 0, seg_size, now_itr, seg_size, -1);
			}
		}
		if (cnt != 0) {
			cout << -1 << " ";
			continue;
		}
		pair<int, int> now = seg_find(1, 0, seg_size, 0, seg_size, 0);
		if (now.second == 0) {
			cout << now.first << " ";
		}
		else {
			cout << -1 << " ";
		}
	}
	cout << endl;
}