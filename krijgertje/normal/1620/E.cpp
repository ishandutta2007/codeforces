#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
#include <functional>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXQ = 500000;
const int MAXVAL = 500000;

int nq;
int qkind[MAXQ], qx[MAXQ], qy[MAXQ];
vector<int> ans;

int vhead[MAXVAL + 1], vtail[MAXVAL + 1], vnxt[MAXQ], vprv[MAXQ];
int pos[MAXQ];

void solve() {
	int anslen = 0;
	REP(i, nq) pos[i] = -1;
	FORE(i, 1, MAXVAL) vhead[i] = vtail[i] = -1;
	REP(i, nq) {
		if (qkind[i] == 1) {
			pos[i] = anslen++;
			int x = qx[i];
			vprv[i] = vtail[x]; if (vprv[i] != -1) vnxt[vprv[i]] = i; else vhead[x] = i;
			vnxt[i] = -1; vtail[x] = i;
		}
		if (qkind[i] == 2) {
			int x = qx[i], y = qy[i];
			int a = vhead[x];
			if (a != -1 && x != y) {
				vprv[a] = vtail[y]; if (vprv[a] != -1) vnxt[vprv[a]] = a; else vhead[y] = a;
				vtail[y] = vtail[x];
				vhead[x] = vtail[x] = -1;
			}
		}
	}
	ans = vector<int>(anslen, -1);
	FORE(v, 1, MAXVAL) for (int x = vhead[v]; x != -1; x = vnxt[x]) ans[pos[x]] = v;
}

void run() {
	scanf("%d", &nq);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d", &qx[i]);
		if (qkind[i] == 2) scanf("%d%d", &qx[i], &qy[i]);
	}
	solve();
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}