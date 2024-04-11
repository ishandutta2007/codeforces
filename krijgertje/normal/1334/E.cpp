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


const int MAXQ = 300000;
const int MOD = 998244353;
const int MAXEXP = 60;

ll D;
int nq;
ll qa[MAXQ], qb[MAXQ]; int qans[MAXQ];

vector<ll> p;
int C[MAXEXP + 1][MAXEXP + 1];

int calc(const vector<int>& parts) {
	int ret = 1, sum = 0;
	REPSZ(i, parts) sum += parts[i], assert(sum <= MAXEXP), ret = (ll)ret * C[sum][parts[i]] % MOD;
	return ret;
}

void solve() {
	{ p.clear(); ll x = D; for (int i = 2; (ll)i * i <= x; ++i) if (x % i == 0) { p.PB(i); while (x % i == 0) x /= i; } if (x != 1) p.PB(x);  }
	//printf("p:"); REPSZ(i, p) printf(" %lld", p[i]); puts("");
	REPE(i, MAXEXP) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; }

	REP(i, nq) {
		vector<int> a(SZ(p), 0); { ll x = qa[i]; REPSZ(j, p) while (x % p[j] == 0) ++a[j], x /= p[j]; assert(x == 1); }
		vector<int> b(SZ(p), 0); { ll x = qb[i]; REPSZ(j, p) while (x % p[j] == 0) ++b[j], x /= p[j]; assert(x == 1); }
		vector<int> aparts, bparts; REPSZ(j, p) if (a[j] < b[j]) aparts.PB(b[j] - a[j]); else if (b[j] < a[j]) bparts.PB(a[j] - b[j]);
		qans[i] = (ll)calc(aparts) * calc(bparts) % MOD;
	}
}

void run() {
	scanf("%lld", &D);
	scanf("%d", &nq);
	REP(i, nq) scanf("%lld%lld", &qa[i], &qb[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}