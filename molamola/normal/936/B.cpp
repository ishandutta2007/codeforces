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
typedef pair<ldouble, ldouble> pdd;

int n, m;
int d[100010][2], pre[100010][2];
queue <pii> que;
vector <int> E[100010], F[100010];
int color[100010];
int DW;

void dfs(int x) {
	color[x] = 1;
	for(int e : E[x]) {
		if(color[e] == 0) dfs(e);
		else if(color[e] == 1) DW = 1;
	}
	color[x] = 2;
}

void solve() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		while(x--) {
			int y; scanf("%d", &y);
			E[i].push_back(y);
			F[y].push_back(i);
		}
		if(szz(E[i]) == 0) d[i][1] = 1, que.push(pii(i, 1));
	}
	while(!que.empty()) {
		pii t = que.front(); que.pop();
		for(int e : F[t.first]) {
			if(d[e][t.second ^ 1] == 0) {
				d[e][t.second ^ 1] = 1;
				pre[e][t.second ^ 1] = t.first;
				que.push(pii(e, (t.second ^ 1)));
			}
		}
	}
	int s; scanf("%d", &s);
	if(d[s][0]) {
		puts("Win");
		vector <int> res;
		int p = s, px = 0;
		res.pb(s);
		while(pre[p][px] > 0) {
			p = pre[p][px];
			res.pb(p);
			px ^= 1;
		}
		for(int e : res) printf("%d ", e); puts("");
	}
	else {
		dfs(s);
		if(DW) puts("Draw");
		else puts("Lose");
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}