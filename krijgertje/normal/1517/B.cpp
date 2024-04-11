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

const int MAXSEG = 100;
const int MAXOPT = 100;

int nseg, nopt;
int cost[MAXSEG][MAXOPT];
int ans[MAXSEG][MAXOPT];

void solve() {
	vector<pair<int, pair<int, int>>> o;
	REP(i, nseg) REP(j, nopt) o.PB(MP(cost[i][j], MP(i, j)));
	sort(o.begin(), o.end());
	//printf("o:"); for (auto z : o) printf(" (%d,%d)=%d", z.second.first, z.second.second, z.first); puts("");
	vector<vector<bool>> blocked(nseg, vector<bool>(nopt, false));
	REP(j, nopt) { int x, y; tie(x, y) = o[j].second; blocked[x][y] = true; }
	vector<int> at(nseg, 0);
	REP(j, nopt) {
		REP(i, nseg) {
			if (o[j].second.first == i) {
				assert(blocked[i][o[j].second.second]);
				ans[i][j] = o[j].first;
			} else {
				while (at[i] < nopt && blocked[i][at[i]]) ++at[i];
				assert(at[i] < nopt);
				ans[i][j] = cost[i][at[i]];
				blocked[i][at[i]] = true;
				++at[i];
			}
		}
	}
}

void run() {
	scanf("%d%d", &nseg, &nopt);
	REP(i, nseg) REP(j, nopt) scanf("%d", &cost[i][j]);
	solve();
	REP(i, nseg) { REP(j, nopt) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}