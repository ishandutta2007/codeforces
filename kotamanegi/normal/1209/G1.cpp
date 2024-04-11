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
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<int> inputs;
int next_canvisit[600000];
int is_starter[600000];
int cnt[600000];
int next_move[600000] = {};
int dp[600000];
int visited[600000];
long long seg_tree[seg_size * 4];
long long seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (w_r <= n_l || n_r <= w_l) return 0;
	return max(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r));
}
void seg_set(int now) {
	seg_tree[now] = max(seg_tree[now * 2], seg_tree[now * 2 + 1]);
	if (now != 1) seg_set(now / 2);
}
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n, query;
	cin >> n >> query;
	REP(i, 300000) {
		next_canvisit[i] = -1;
	}
	REP(i, n) {
		int a;
		cin >> a;
		inputs.push_back(a);
		cnt[a]++;
		if (next_canvisit[a] == -1) {
			is_starter[i] = true;
		}
		next_canvisit[a] = i;
	}
	priority_queue<pair<int, int>> go;
	REP(i, 300000) {
		if (next_canvisit[i] != -1) {
			go.push(make_pair(next_canvisit[i], i));
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		next_move[i] = max(go.top().first,(int)seg_find(1,0,seg_size,0,go.top().first+1));
		seg_tree[seg_size + i] = next_move[i];
		seg_set((seg_size + i) / 2);
		if (is_starter[i] == true) {
			visited[inputs[i]] = 1;
			while (go.empty() == false&&visited[go.top().second] == true) {
				go.pop();
			}
		}
	}
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		dp[i + 1] = max(dp[i + 1], dp[i]);//do nothing
		if (is_starter[i] == true) {
			//doing
			int next_win = dp[i] + cnt[inputs[i]];
			int next_go = next_move[i] + 1;
			dp[next_go] = max(dp[next_go], next_win);
		}
	}
	cout << n - dp[n] << endl;
}