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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long value[200000];
vector<long long> vertexs[200000];
pair<long long,long long> backing[64][200000];
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void dfs(int now, int back) {
	backing[0][now].first = back;
	REP(q, vertexs[now].size()) {
		int going = vertexs[now][q];
		if (going == back) continue;
		dfs(going, now);
	}
	return;
}
int main() {
#define int long long
	int n;
	scanf("%lld", &n);
	REP(i, n) {
		scanf("%lld", &value[i+1]);
	}
	REP(i, n - 1) {
		int a, b;
		scanf("%lld%lld", &a, &b);
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 2; i <= n; ++i) {
		backing[0][i].second = gcd(value[i], value[backing[0][i].first]);
	}
	for (int q = 0; q < 60; ++q) {
		for (int i = 1; i <= n; ++i) {
			long long hoge = gcd(backing[q][i].second, backing[q][backing[q][i].first].second);
			long long next_go = backing[q][backing[q][i].first].first;
			backing[q + 1][i] = make_pair(next_go, hoge);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		int now_here = i;
		int now_value = value[i];
		while (now_here != 0) {
			long long next_move = 0;
			for (long long q = 0; q <= 60; ++q) {
				if (backing[q][now_here].first == 0 || gcd(backing[q][now_here].second, now_value) != now_value) {
					next_move = q-1;
					break;
				}
			}
			next_move = max(next_move, 0LL);
			ans += (now_value * (1LL << next_move)) % MAX_MOD;
			ans %= MAX_MOD;
			now_value = gcd(backing[next_move][now_here].second, now_value);
			now_here = backing[next_move][now_here].first;
		}
	}
	printf("%lld\n", ans);
}