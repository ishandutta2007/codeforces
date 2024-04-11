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

const int MAXDISC = 200000;
const int MAXTOWER = 200000;

int ndisc, ntower;
int sontower[MAXDISC];
int q[MAXTOWER - 1][2];
int ans[MAXTOWER];

int mp[MAXTOWER];
int ontower[MAXDISC];
vector<int> towerlst[MAXTOWER];

void solve() {
	int curans = 0;
	REP(i, ndisc) ontower[i] = sontower[i];
	FOR(i, 1, ndisc) if (ontower[i - 1] != ontower[i]) ++curans;
	REP(i, ntower) towerlst[i].clear();
	REP(i, ndisc) towerlst[ontower[i]].PB(i);
	REP(i, ntower) mp[i] = i;
	ans[0] = curans;
	REP(i, ntower - 1) {
		int a = mp[q[i][0]], b = mp[q[i][1]]; assert(a != -1 && b != -1);
		if (SZ(towerlst[a]) > SZ(towerlst[b])) swap(a, b);
		REPSZ(j, towerlst[a]) {
			int id = towerlst[a][j];
			if (id - 1 >= 0 && ontower[id - 1] != ontower[id]) --curans;
			if (id + 1 < ndisc && ontower[id + 1] != ontower[id]) --curans;
			ontower[id] = b;
			if (id - 1 >= 0 && ontower[id - 1] != ontower[id]) ++curans;
			if (id + 1 < ndisc && ontower[id + 1] != ontower[id]) ++curans;
			towerlst[b].PB(id);
		}
		towerlst[a].clear();
		ans[i + 1] = curans;

		int aa = q[i][0], bb = q[i][1];
		mp[aa] = b; mp[bb] = -1;
		//{ int tot = 0; REP(j, ntower) REPSZ(k, towerlst[j]) { int id = towerlst[j][k]; assert(ontower[id] == j); ++tot; } assert(tot == ndisc); }
	}
}

void run() {
	scanf("%d%d", &ndisc, &ntower);
	REP(i, ndisc) scanf("%d", &sontower[i]), --sontower[i];
	REP(i, ntower - 1) REP(j, 2) scanf("%d", &q[i][j]), --q[i][j];
	solve();
	REP(i, ntower) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}