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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLAMP = 300000;
const int MAXSWITCH = 300000;

int nlamp, nswitch;
char slamp[MAXLAMP + 1];
vector<int> sw[MAXSWITCH];
int ans[MAXLAMP + 1];

vector<int> who[MAXLAMP];
int ufpar[MAXSWITCH], ufsz[MAXSWITCH], ufchange[MAXSWITCH], ufopt[MAXSWITCH], ufcnt[MAXSWITCH][2];
int totalcost;

int uffind(int x) { if (ufpar[x] == x) return x; int ret = uffind(ufpar[x]); if (ufpar[x] != ret) assert(ufpar[ufpar[x]] == ret), ufchange[x] ^= ufchange[ufpar[x]]; ufpar[x] = ret; return ret; }

int calccost(int idx) {
	int ret = INT_MAX;
	REP(par, 2) {
		if ((ufopt[idx] & (1 << par)) == 0) continue;
		int cur = ufcnt[idx][1 - par];
		ret = min(ret, cur);
	}
	assert(ret != INT_MAX); return ret;
}

void setsingle(int x, int val) {
	//printf("setting single %d to %d\n", x, val);
	int xx = uffind(x);
	if (x != xx) assert(ufpar[x] == xx), val ^= ufchange[x];
	totalcost -= calccost(xx);
	ufopt[xx] &= 1 << val;
	totalcost += calccost(xx);
}
void setedge(int x, int y, int val) {
	//printf("setting edge %d-%d to %d\n", x, y, val);
	int xx = uffind(x);
	int yy = uffind(y);
	if (x != xx) assert(ufpar[x] == xx), val ^= ufchange[x];
	if (y != yy) assert(ufpar[y] == yy), val ^= ufchange[y];
	if (xx == yy) {
		assert(val == 0);
	} else {
		if (ufsz[xx] < ufsz[yy]) swap(x, y), swap(xx, yy);
		totalcost -= calccost(xx) + calccost(yy);
		ufpar[yy] = xx, ufsz[xx] += ufsz[yy], ufchange[yy] = val; REP(z, 2) if ((ufopt[yy] & (1 << z)) == 0) ufopt[xx] &= 1 << (val == 0 ? 1 - z : z); REP(z, 2) ufcnt[xx][z] += ufcnt[yy][val == 0 ? z : 1 - z];
		totalcost += calccost(xx);
	}
}

void solve() {
	REP(i, nlamp) who[i].clear(); REP(i, nswitch) REPSZ(j, sw[i]) who[sw[i][j]].PB(i);
	REP(i, nlamp) assert(SZ(who[i]) <= 2);
	//REP(i, nlamp) { printf("%d:", i); REPSZ(j, who[i]) printf(" %d", who[i][j]); puts(""); }

	REP(i, nswitch) ufpar[i] = i, ufsz[i] = 1, ufopt[i] = 3, ufcnt[i][0] = 1, ufcnt[i][1] = 0;
	totalcost = 0; REP(i, nswitch) totalcost += calccost(i);

	REP(i, nlamp) {
		if (SZ(who[i]) == 0) {
			assert(slamp[i] == '1');
		} else if (SZ(who[i]) == 1) {
			int x = who[i][0];
			setsingle(x, slamp[i] == '1' ? 0 : 1);
		} else {
			assert(SZ(who[i]) == 2);
			int x = who[i][0], y = who[i][1];
			setedge(x, y, slamp[i] == '1' ? 0 : 1);
		}
		ans[i + 1] = totalcost;
	}
}

void run() {
	scanf("%d%d", &nlamp, &nswitch);
	scanf("%s", slamp); assert(strlen(slamp) == nlamp);
	REP(i, nswitch) { int cnt; scanf("%d", &cnt); sw[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &sw[i][j]), --sw[i][j]; }
	solve();
	FORE(i, 1, nlamp) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}