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

const int MAXN = 300000;
const int MAXMSG = 300000;
const int MAXID = MAXN + MAXMSG;

int n, nmsg;
int msg[MAXMSG];
int mnpos[MAXN], mxpos[MAXN];

int lastid[MAXN];
int bit[MAXID + 1];
void bmod(int idx, int by) { ++idx; while (idx <= n + nmsg) { bit[idx] += by; idx += idx & -idx; } }
int bget(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += bit[idx]; idx -= idx & -idx; } return ret; }

void solve() {
	REP(i, n) mnpos[i] = mxpos[i] = i;
	REP(i, n) lastid[i] = n - i - 1;
	REPE(i, n + nmsg) bit[i] = 0;
	REP(i, n) bmod(lastid[i], +1);
	REP(i, nmsg) {
		int cur = msg[i];
		bmod(lastid[cur], -1);
		int pos = n - bget(lastid[cur]) - 1;
		//printf("%d was at %d\n", cur + 1, pos + 1);
		mnpos[cur] = min(mnpos[cur], 0);
		mxpos[cur] = max(mxpos[cur], pos);
		lastid[cur] = n + i;
		bmod(lastid[cur], +1);
	}
	REP(i, n) {
		int pos = n - bget(lastid[i]);
		//printf("%d ends at %d\n", i + 1, pos + 1);
		mxpos[i] = max(mxpos[i], pos);
	}
}

void run() {
	scanf("%d%d", &n, &nmsg);
	REP(i, nmsg) scanf("%d", &msg[i]), --msg[i];
	solve();
	REP(i, n) printf("%d %d\n", mnpos[i] + 1, mxpos[i] + 1);
}

int main() {
	run();
	return 0;
}