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

const int MAXTYPE = 200000;
const int MAXQ = 200000;

int ntype, nq;
int x[MAXTYPE], y[MAXTYPE];
int qkind[MAXQ], qtype[MAXQ];
int qans[MAXQ];

int activator[MAXTYPE];
int mate[MAXQ];

void solve() {
	REP(i, ntype) activator[i] = -1;
	REP(i, nq) mate[i] = -1;
	REP(i, nq) {
		int t = qtype[i];
		if (qkind[i] == 1) { assert(activator[t] == -1); activator[t] = i; }
		if (qkind[i] == 2) { assert(activator[t] != -1); mate[i] = activator[t]; mate[mate[i]] = i; activator[t] = -1; }
	}
	//printf("mate:"); REP(i, nq) printf(" %d", mate[i]); puts("");

	int lim = sqrt(1.0 * nq);
	vector<int> delta(nq, 0);
	vector<vector<int>> pdelta(lim + 1); FORE(p, 2, lim) pdelta[p] = vector<int>(p, 0);
	int curans = 0;
	REP(i, nq) {
		int t = qtype[i], p = x[t] + y[t];
		if (qkind[i] == 1) {
			if (p <= lim) {
				int start = (i + x[t]) % p, end = i % p;
				++pdelta[p][start], --pdelta[p][end], ++curans;
			} else {
				for (int k = i; k < nq && (mate[i] == -1 || k + x[t] < mate[i]); k += p) {
					int l = k + x[t], r = k + p;
					if (mate[i] != -1) r = min(r, mate[i]);
					assert(l < r);
					if (l < nq) ++delta[l];
					if (r < nq) --delta[r];
				}
			}
		}
		if (qkind[i] == 2) {
			if (p <= lim) {
				int start = (mate[i] + x[t]) % p, end = mate[i] % p, me = i % p;
				--pdelta[p][start], ++pdelta[p][end];
				//printf("i=%d mate=%d start=%d end=%d me=%d\n", i, mate[i], start, end, me);
				if (start < me && me <= end || me <= end && end < start || end < start && start < me) --curans;
			}
		}
		curans += delta[i];
		FORE(p, 2, lim) { 
			curans += pdelta[p][i % p]; 
			//int z = pdelta[p][i % p]; if (z != 0) printf("i=%d p=%d z=%d\n", i, p, z); 
		}
		qans[i] = curans;
	}
}

void run() {
	scanf("%d%d", &ntype, &nq);
	REP(i, ntype) scanf("%d%d", &x[i], &y[i]);
	REP(i, nq) scanf("%d%d", &qkind[i], &qtype[i]), --qtype[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}