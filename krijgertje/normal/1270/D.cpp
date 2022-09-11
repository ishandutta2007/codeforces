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

const int MAXN = 500;

int n;
int sz;
ll val[MAXN];

pair<int, ll> query(const vector<int> &q) {
	printf("?"); REPSZ(i, q) printf(" %d", q[i] + 1); puts(""); fflush(stdout);
	int pos; scanf("%d", &pos); if (pos == -1) exit(0); --pos; ll val; scanf("%lld", &val); return MP(pos, val);
}

int solve() {
	int cnt = sz + 1;
	REP(i, cnt) {
		vector<int> cur(cnt); REP(j, cnt) cur[j] = j; cur.erase(cur.begin() + i);
		pair<int, ll> res = query(cur);
		val[i] = res.second;
	}
	sort(val, val + cnt);
	assert(val[0] != val[cnt - 1]); REP(i, cnt) assert(val[i] == val[0] || val[i] == val[cnt - 1]);
	int nlst = 0; REP(i, cnt) if (val[i] == val[cnt - 1]) ++nlst;
	return nlst - 1;
}

void run() {
	scanf("%d%d", &n, &sz);
	int ans = solve();
	printf("! %d\n", ans + 1); fflush(stdout);
}

int main() {
	run();
	return 0;
}