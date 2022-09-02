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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;
typedef pair<double, double> pdd;

int n, k;
vector <int> E[100010];
int C[100010], deg[100010];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	if(n <= 3) {
		puts("No");
		return 0;
	}
	
	vector <int> v[100050];
	int cnt = 0;
	for(int i=1;i<=n;i++) {
		deg[i] = szz(E[i]);
		if(deg[i] == 1) {
			v[0].pb(i);
			C[i] = 1;
		}
	}
	for(cnt=0;;cnt++) {
		vector <int> w;
		rep(i, szz(v[cnt])) {
			int t = v[cnt][i];
			for(int e : E[t]) {
				--deg[e];
				if(deg[e] > 1) continue;
				if(C[e] == 0) {
					C[e] = C[t] + 1;
					w.pb(e);
				}
			}
		}
		v[cnt+1] = w;
		if(szz(w) == 0) break;
	}
	int mx = 0;
	for(int i=1;;i++) if(szz(v[i]) == 0) { mx = i - 1; break; }
	if(mx != k || szz(v[mx]) > 1) { puts("No"); return 0; }
	int rt = v[mx][0];
	if(szz(E[rt]) <= 2) { puts("No"); return 0; }
	for(int i=1;i<=n;i++) {
		int cnt = 0;
		for(int e : E[i]) {
			if(C[i] == C[e] || abs(C[i] - C[e]) > 1) {
				puts("No");
				return 0;
			}
			if(C[e] == C[i] - 1) ++cnt;
		}
		if(C[i] > 1 && cnt < 3) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}