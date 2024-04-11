#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N;
vector <int> E[500050];
char color[500050];
int dp[1010][2], pw[10];

int chk(int v[]) {
	for(int i=1;i<=N;i++) if(v[i-1] != 0) {
		int cnt = 0;
		for(int e : E[i]) if(v[e-1] == v[i-1]) ++cnt;
		if(cnt >= 2) return 1;
	}
	return 0;
}

int dfs(int state, int turn) {
	if(dp[state][turn] != -1) return dp[state][turn];
	int v[7] = {}; int ti = state;
	for(int i=0;i<N;i++) v[i] = ti % 3, ti /= 3;
	
	int mx = -1, cnt = 0;
	for(int i=0;i<N;i++) if(v[i] == 0) ++cnt;
	if(cnt == 0) return 0;
	for(int i=0;i<N;i++) if(v[i] == 0) {
		v[i] = (turn + 1);
		if(chk(v)) return dp[state][turn] = 1;
		int val = -dfs(state + (turn + 1) * pw[i], 1 - turn);
		mx = max(mx, val);
		v[i] = 0;
	}
	return dp[state][turn] = mx;
}

int leaf[500050];

void solve() {
	scanf("%d", &N);
	for(int i=1;i<N;i++) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	scanf("%s", color + 1);
	if(N <= 6) {
		memset(dp, -1, sizeof dp);
		int state = 0;
		for(int i=1;i<=N;i++) {
			int c = (color[i] == 'N' ? 0 : 1);
			state += c * pw[i-1];
		}
		int ans = dfs(state, 0);
		if(ans == 1) puts("White");
		else puts("Draw");
		return;
	}
	int c3 = 0;
	for(int i=1;i<=N;i++) if(szz(E[i]) > 3) {
		puts("White");
		return;
	}
	for(int i=1;i<=N;i++) if(szz(E[i]) == 3) ++c3;
	if(c3 > 2) {
		puts("White");
		return;
	}
	for(int i=1;i<=N;i++) {
		if(szz(E[i]) == 1) leaf[i] = 1;
		else leaf[i] = 0;
	}
	for(int i=1;i<=N;i++) if(szz(E[i]) == 3) {
		int cnt = 0;
		for(int e : E[i]) if(leaf[e]) ++cnt;
		if(cnt <= 1) {
			puts("White");
			return;
		}
	}
	
	for(int i=1;i<=N;i++) if(color[i] == 'W' && szz(E[i]) > 1) {
		puts("White");
		return;
	}
	for(int i=1;i<=N;i++) if(color[i] == 'W') {
		for(int e : E[i]) if(szz(E[e]) == 3) {
			puts("White");
			return;
		}
	}
	int cw = 0;
	for(int i=1;i<=N;i++) if(color[i] == 'W') ++cw;
	if(c3 == 0) {
		if(cw <= 1) {
			puts("Draw");
		}
		else {
			if(N % 2 == 1) puts("White");
			else puts("Draw");
		}
	}
	else if(c3 == 1) {
		if(cw == 0) puts("Draw");
		else {
			if(N % 2 == 0) puts("White");
			else puts("Draw");
		}
	}
	else {
		if(N % 2 == 0) puts("Draw");
		else puts("White");
	}
}

int main() {
	pw[0] = 1; for(int i=1;i<10;i++) pw[i] = 3 * pw[i-1];
	int Tc;
	scanf("%d", &Tc);
	for(int t=1;t<=Tc;t++) {
		solve();
		for(int i=1;i<=N;i++) E[i].clear();
	}
	return 0;
}