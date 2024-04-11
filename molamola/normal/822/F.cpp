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

vector <int> E[110];
map <pii, int> M;
int n;

void make(int u, int v, double X) {
	if(X < 1) printf("1 %d %d %d %.12f\n", M[pii(u, v)], u, v, X);
	else printf("1 %d %d %d %.12f\n", M[pii(u, v)], v, u, X - 1);
}

void dfs(int x, int fa, double L) {
	int N = sz(E[x]);
	double now = L;
	for(int e : E[x]) if(e != fa) {
		now += 2.0 / N;
		if(now > 2) now -= 2;
		make(x, e, now);
		dfs(e, x, fmod(now+1, 2));
	}
}

void solve(){
	scanf("%d", &n);
	rep(i, n-1) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
		M[pii(x, y)] = i + 1;
		M[pii(y, x)] = i + 1;
	}
	printf("%d\n", n-1);
	dfs(1, -1, 0);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};