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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int R[200020];
int mx[200020], mn[200020];
vector <int> E[200020], F[200020];
vector <int> v;
int chk[200020];
int num[200020];

void dfs(int x) {
	chk[x] = 1;
	for(int e : E[x]) {
		if(chk[e] == 0) dfs(e);
	}
	v.pb(x);
	num[x] = sz(v);
}

vector <int> V[200020];

void solve() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++) scanf("%d", R+i);
	rep(i, m) {
		int x, y; scanf("%d%d", &x, &y);
		F[x].pb(y);
		E[y].pb(x);
	}
	for(int i=1;i<=n;i++) if(chk[i] == 0) dfs(i);
	int ok = 1;
	for(int i=1;i<=n;i++) for(int e : E[i]) if(num[i] < num[e]) ok = 0;
	if(ok == 0) { puts("-1"); return; }
	for(int i=1;i<=n;i++) mx[i] = (R[i] ? R[i] : k), mn[i] = (R[i] ? k + 1 - R[i] : k);
	for(int e : v) {
		for(int f : F[e]) mx[f] = min(mx[f], mx[e] - 1);
	}
	reverse(all(v));
	for(int e : v) for(int f : E[e]) mn[f] = min(mn[f], mn[e] - 1);
	for(int i=1;i<=n;i++) mn[i] = k + 1 - mn[i];
	for(int i=1;i<=n;i++) if(mn[i] > mx[i]) { puts("-1"); return; }
	for(int i=1;i<=n;i++) V[mn[i]].pb(i);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for(int i=1;i<=k;i++) {
		for(int e : V[i]) pq.push(pii(mx[e], e));
		if(pq.empty()) {
			puts("-1"); return;
		}
		pii t = pq.top(); pq.pop();
		R[t.Se] = i;
		while(!pq.empty() && pq.top().Fi == i) {
			pii t = pq.top(); pq.pop();
			R[t.Se] = i;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ", R[i]); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}