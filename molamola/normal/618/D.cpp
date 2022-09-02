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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n;
vector <int> E[200020];
int c, d[200020];

void dfs(int x, int fa) {
	for(int e : E[x]) if(e != fa) {
		dfs(e, x);
		if(d[e] < 2 && d[x] < 2) d[e]++, d[x]++, c++;
	}
}

void solve() {
	int x, y;
	scanf("%d%d%d", &n, &x, &y);
	rep(i, n-1) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y); E[y].pb(x);
	}
	if(x <= y) {
		dfs(1, -1);
		printf("%lld\n", c * (ll)x + (n - 1 - c) * (ll)y);
	}
	else {
		int ok = 0;
		for(int i=1;i<=n;i++) if(szz(E[i]) == n-1) ok = 1;
		if(ok) printf("%lld\n", x + (n-2) * (ll)y);
		else printf("%lld\n", (n-1) * (ll)y);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}