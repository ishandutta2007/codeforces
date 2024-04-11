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

int N;
vector <int> E[510];
int X[510][510];

vector <int> L[30030];
int choose[30030], cs;

int Do(vector <int> W, int depth = 1) {
	if(depth >= 11) while(1);
	int cnt[510] = {};
	int ch = -1, opt = 1e9;
	for(int e : W) {
		for(int g : E[e]) cnt[g] = 0;
		for(int f : W) if(f != e) {
			vector <int> mnv;
			for(int g : E[e]) {
				if(szz(mnv) == 0) mnv.pb(g);
				else if(X[mnv[0]][f] > X[g][f]) { mnv.clear(); mnv.pb(g); }
				else if(X[mnv[0]][f] == X[g][f]) mnv.pb(g);
			}
			for(int x : mnv) cnt[x]++;
		}
		int mx = -1;
		for(int g : E[e]) mx = max(mx, cnt[g]);
		if(opt > mx) {
			opt = mx;
			ch = e;
		}
	}
	int me = ++cs;
	choose[cs] = ch;
	vector <vector<int> > NT;
	NT.resize(szz(E[ch]));
	for(int f : W) if(f != ch) {
		vector <int> mnv;
		rep(gg, szz(E[ch])) {
			int g = E[ch][gg];
			if(szz(mnv) == 0) mnv.pb(gg);
			else if(X[E[ch][mnv[0]]][f] > X[g][f]) { mnv.clear(); mnv.pb(gg); }
			else if(X[E[ch][mnv[0]]][f] == X[g][f]) mnv.pb(gg);
		}
		for(int gg : mnv) NT[gg].pb(f);
		
	}
	L[me].resize(szz(E[ch]));
	rep(vv, szz(NT)) {
		auto v = NT[vv];
		if(szz(v)) {
			L[me][vv] = Do(v, depth + 1);
		}
	}
	return me;
}

void query(int rt) {
	int me = choose[rt];
	printf("%d\n", me);
	fflush(stdout);
	char buf[10]; scanf("%s", buf);
	if(!strcmp(buf, "FOUND")) return;
	int x; scanf("%d", &x);
	rep(i, szz(E[me])) {
		if(E[me][i] == x) {
			query(L[rt][i]);
			return;
		}
	}
}

int main() {
	int m; scanf("%d%d", &N, &m);
	rep(i, m) {
		int k; scanf("%d", &k);
		int p = -1;
		while(k--) {
			int x; scanf("%d", &x);
			if(p != -1) E[x].pb(p), E[p].pb(x);
			p = x;
		}
	}
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) X[i][j] = (i != j ? 1e9 : 0);
	for(int i=1;i<=N;i++) for(int e : E[i]) X[i][e] = 1;
	for(int k=1;k<=N;k++) for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) X[i][j] = min(X[i][j], X[i][k] + X[k][j]);
	
	vector <int> w; for(int i=1;i<=N;i++) w.pb(i);
	int rt = Do(w);
	rep(tt, N) {
		query(rt);
	}
	
	return 0;
}