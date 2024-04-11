#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int inp[200020][4];
int vl[200020][4], vr[200020][4];
int N;
const int INF = 1e9 + 100;

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) rep(j, 4) scanf("%d", inp[i] + j);
	for(int i=1;i<=N;i++) swap(inp[i][1], inp[i][2]);
	rep(i, 4) vl[0][i] = (i % 2 == 0 ? -INF : INF);
	for(int i=1;i<=N;i++) {
		rep(j, 4) {
			if(j % 2 == 0) vl[i][j] = max(vl[i-1][j], inp[i][j]);
			else vl[i][j] = min(vl[i-1][j], inp[i][j]);
		}
	}
	rep(i, 4) vr[N+1][i] = (i % 2 == 0 ? -INF : INF);
	for(int i=N;i;i--) {
		rep(j, 4) {
			if(j % 2 == 0) vr[i][j] = max(vr[i+1][j], inp[i][j]);
			else vr[i][j] = min(vr[i+1][j], inp[i][j]);
		}
	}
	for(int i=1;i<=N;i++) {
		int ok = 1;
		int ans[2];
		rep(j, 2) {
			int lf = j*2, rf = j*2+1;
			int lval = max(vl[i-1][lf], vr[i+1][lf]);
			int rval = min(vl[i-1][rf], vr[i+1][rf]);
			ans[j] = lval;
			if(lval > rval) ok = 0;
		}
		if(ok) { printf("%d %d\n", ans[0], ans[1]); return 0; }
	}
	return 0;
}