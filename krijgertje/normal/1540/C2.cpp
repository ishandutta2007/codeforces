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

const int MAXN = 100;
const int MAXQ = 100000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n;
int lim[MAXN];
int diff[MAXN - 1];
int nq;
int qx[MAXQ];
int qans[MAXQ];

int sumlim[MAXN];
int sumdiff[MAXN];

int calc(vector<int> need) {
	//printf("need:"); REPSZ(i, need) printf(" %d", need[i]); puts("");
	vector<int> ways(sumlim[n - 1] + 1, 0);
	vector<int> sumways(sumlim[n - 1] + 1);
	inc(ways[0], 1);
	REP(i, n) {
		int sum = 0;
		REPE(j, sumlim[i]) { sumways[j] = ways[j]; if (j - 1 >= 0) inc(sumways[j], sumways[j - 1]); }
		REPE(j, sumlim[i]) {
			ways[j] = sumways[j];
			if (j > lim[i]) dec(ways[j], sumways[j - lim[i] - 1]);
		}
		REP(j, need[i]) ways[j] = 0;
	}
	int ret = 0;
	REPE(j, sumlim[n - 1]) inc(ret, ways[j]);
	return ret;
}

void solve() {
	REP(i, n) sumlim[i] = (i == 0 ? 0 : sumlim[i - 1]) + lim[i];
	sumdiff[0] = 0; REP(i, n - 1) sumdiff[i + 1] = sumdiff[i] + diff[i];
	map<int, int> mem;
	int all = 1;
	REP(i, n) all = (ll)all * (lim[i] + 1) % MOD;
	REP(i, nq) {
		int x = qx[i];
		if (mem.count(x)) { qans[i] = mem[x]; continue; }
		vector<int> need(n);
		REP(i, n) need[i] = (i == 0 ? 0 : need[i - 1]) + x + sumdiff[i];
		REP(i, n) need[i] = max(0, need[i]);
		bool ok = true;
		REP(i, n) if (need[i] > sumlim[i]) ok = false;
		if (!ok) { qans[i] = 0; continue; }
		bool allzero = true;
		REP(i, n) if (need[i] != 0) allzero = false;
		if (allzero) { qans[i] = all; continue; }
		qans[i] = calc(need);
		mem[x] = qans[i];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &lim[i]);
	REP(i, n - 1) scanf("%d", &diff[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qx[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}