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

int N;
pii P[300030];
map <pii, int> MX;
vector <int> PE[300030];
int uf[300030], ufz[300030];
int Find(int x) { return uf[x] == x ? x : uf[x] = Find(uf[x]); }
vector <pii> HX;
vector <int> T[300030];
vector <int> L[300030];

int cut[300030], down[300030];

void pdfs(int x, int fa) {
	down[x] = ufz[x];
	for(int e : T[x]) if(e != fa && cut[e] == 0) {
		pdfs(e, x);
		down[x] += down[e];
	}
}

int cut_v[300030];
int up[300030][20];
int upl[300030][20], uplv[300030][20];

void Do(int x, int lev) {
	pdfs(x, -1);
	int h = down[x] / 2;
	while(1) {
		int f = 0;
		for(int e : T[x]) if(cut[e] == 0 && down[e] < down[x] && down[e] > h) {
			x = e; f = 1; break;
		}
		if(f == 0) break;
	}
	
	queue <int> que;
	for(int e : L[x]) {
		up[e][lev] = x;
		upl[e][lev] = 0;
		uplv[e][lev] = P[e].second;
		que.push(e);
	}
	while(!que.empty()) {
		int t = que.front(); que.pop();
		for(int e : PE[t]) if(cut_v[e] == 0 && up[e][lev] == -1) {
			up[e][lev] = x;
			upl[e][lev] = upl[t][lev] + 1;
			uplv[e][lev] = uplv[t][lev];
			que.push(e);
		}
	}
	
	for(int e : L[x]) {
		cut_v[e] = 1;
	}
	cut[x] = 1;
	for(int e : T[x]) if(cut[e] == 0) {
		Do(e, lev + 1);
	}
}

int LY[300030], SY[300030];
vector <int> TT[300030];
set <pii> TXX;

void init_v(int v, int rt, int l, int r) {
	int m = (l + r) >> 1;
	TT[v][rt] = 1e9;
	if(l < m) init_v(v, rt<<1, l, m - 1);
	if(m < r) init_v(v, rt<<1|1, m+1, r);
}

void update_v2(int v, int rt, int l, int r, int x, int val) {
	int m = (l + r) >> 1;
	TT[v][rt] = min(TT[v][rt], val + abs(x - m));
	if(x < m) update_v2(v, rt<<1, l, m-1, x, val);
	if(m < x) update_v2(v, rt<<1|1, m+1, r, x, val);
}

int read_v2(int v, int rt, int l, int r, int x) {
	int m = (l + r) >> 1;
	int res = TT[v][rt] + abs(x - m);
	if(x < m) res = min(res, read_v2(v, rt << 1, l, m - 1, x));
	if(m < x) res = min(res, read_v2(v, rt << 1 | 1, m + 1, r, x));
	return res;
}

vector <pii> J[300030];
void update_v(int v, int x, int val) {
	x -= LY[v];
	update_v2(v, 1, 0, SY[v] - 1, x, val);
//	J[v].pb(pii(x, val));
}

int read_v(int v, int x) {
	x -= LY[v];
	int res = 1e9;
//	for(pii e : J[v]) res = min(res, abs(x - e.first) + e.second);
	res = read_v2(v, 1, 0, SY[v] - 1, x);
	return res;
}

void ADD(int x, int y) {
	int px = MX[pii(x, y)];
	for(int i=0;i<20;i++) if(up[px][i] != -1) {
		update_v(up[px][i], uplv[px][i], upl[px][i]);
	}
}

int QUERY(int x, int y) {
	int res = 1e9;
	int px = MX[pii(x, y)];
	for(int i=0;i<20;i++) if(up[px][i] != -1) {
		res = min(res, read_v(up[px][i], uplv[px][i]) + upl[px][i]);
	}
	
	return res == 1e9 ? -1 : res;
}

int DEBU = 0;;

void solve() {
	memset(up, -1, sizeof up);
	N = 300000;
	if(!DEBU) scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		if(DEBU) P[i] = pii(i / 300 + 1, i % 300 + 1);
		else scanf("%d%d", &P[i].first, &P[i].second);
	}
	for(int i=1;i<=N;i++) MX[P[i]] = i;
	for(int i=1;i<=N;i++) uf[i] = i;
	for(int i=1;i<=N;i++) {
		int x = P[i].first, y = P[i].second;
		if(MX.find(pii(x - 1, y)) != MX.end()) {
			int v = MX[pii(x - 1, y)];
			PE[i].pb(v);
			PE[v].pb(i);
			HX.pb(pii(i, v));
		}
		if(MX.find(pii(x, y - 1)) != MX.end()) {
			int v = MX[pii(x, y - 1)];
			PE[i].pb(v);
			PE[v].pb(i);
			uf[i] = Find(v);
		}
	}
	for(pii e : HX) {
		int x = Find(e.first), y = Find(e.second);
		if(TXX.find(pii(x, y)) != TXX.end()) continue;
		T[x].pb(y);
		T[y].pb(x);
		TXX.insert(pii(x, y));
		TXX.insert(pii(y, x));
	}
	for(int i=1;i<=N;i++) ufz[Find(i)]++, L[Find(i)].pb(i);
	for(int i=1;i<=N;i++) if(uf[i] == i) LY[i] = P[i].second, SY[i] = szz(L[i]);
//	if(DEBU) printf("%f\n", (double)clock() / CLOCKS_PER_SEC);
	Do(Find(1), 0);
//	if(DEBU) printf("%f\n", (double)clock() / CLOCKS_PER_SEC);
	/*
	for(int i=1;i<=N;i++) {
		printf("%d : \n", i);
		rep(j, 3) printf("%d ", up[i][j]); puts("");
		rep(j, 3) printf("%d ", upl[i][j]); puts("");
		rep(j, 3) printf("%d ", uplv[i][j]); puts("");
	}
	 */
	for(int i=1;i<=N;i++) if(uf[i] == i) {
		TT[i].resize(szz(L[i]) * 4 + 5);
		init_v(i, 1, 0, SY[i] - 1);
	}
	int q = 300000;
	if(!DEBU) scanf("%d", &q);
	while(q--) {
		int cmd, x, y;
		if(DEBU==0) scanf("%d%d%d", &cmd, &x, &y);
		else {
			cmd = rand() % 2 + 1;
			int t = rand() % N + 1;
			x = P[t].first, y = P[t].second;
		}
		if(cmd == 1) {
			ADD(x, y);
		}
		else {
			int res = QUERY(x, y);
			printf("%d\n", res);
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}