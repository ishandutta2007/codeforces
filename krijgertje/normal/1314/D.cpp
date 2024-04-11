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

const int MAXN = 80;
const int MAXLEN = 10;

int n, len;
int d[MAXN][MAXN];

vector<pair<int, int>> opt[MAXN][MAXN];

bool isblue[MAXN];
int lstblue[MAXLEN / 2 + 1];
int ans;

void calc(int nlst) {
	int ret = 0;
	REP(i, nlst - 1) {
		int a = lstblue[i], b = lstblue[i + 1];
		int cur = INT_MAX; REPSZ(j, opt[a][b]) if (!isblue[opt[a][b][j].second]) { cur = opt[a][b][j].first; break; } if (cur == INT_MAX) return;
		ret += cur;
	}
	ans = min(ans, ret);
}

void rec(int nlst, int rem) {
	if (rem == 0) { lstblue[nlst] = 0; calc(nlst + 1); return; }
	REP(i, n) {
		bool wasblue = isblue[i];
		isblue[i] = true; lstblue[nlst] = i;
		rec(nlst + 1, rem - 1);
		isblue[i] = wasblue; lstblue[nlst] = -1;
	}
}

int solve() {
	REP(i, n) REP(j, n) { opt[i][j].clear(); REP(k, n) if (k != i && k != j) opt[i][j].PB(MP(d[i][k] + d[k][j], k)); sort(opt[i][j].begin(), opt[i][j].end()); }
	REP(i, n) isblue[i] = false;
	isblue[0] = true; lstblue[0] = 0;
	ans = INT_MAX;
	rec(1, len / 2 - 1);
	return ans;
}

void run() {
	scanf("%d%d", &n, &len);
	REP(i, n) REP(j, n) scanf("%d", &d[i][j]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}