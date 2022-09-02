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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

vector <int> E[1000010];
int A[1000010];
int S[1000010];
int D[1000010];
int tot;
int ok;

void dfs(int x) {
	S[x] = A[x];
	vector <int> can;
	for(int e : E[x]) {
		dfs(e);
		if(D[e]) D[x] = D[e], can.pb(D[e]);
		S[x] += S[e];
	}
	if(S[x] == tot / 3) D[x] = x;
	if(ok == 0 && sz(can) >= 2) {
		printf("%d %d\n", can[0], can[1]);
		ok = 1;
	}
	if(ok == 0 && D[x] && S[x] == tot / 3 * 2 && S[x] != tot / 3) {
		ok = 1;
		printf("%d %d\n", x, D[x]);
	}
}

void solve(){
	int n; scanf("%d", &n);
	int rt = -1;
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		if(x) E[x].pb(i);
		else rt = i;
		tot += y;
		A[i] = y;
	}
	if(tot % 3 != 0) {
		printf("-1\n");
		return;
	}
	dfs(rt);
	if(ok == 0) puts("-1");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};