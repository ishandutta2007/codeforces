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

const int MAXLEN = 1000;

char s[MAXLEN + 1]; int slen;
int x;

map<string, int> mp;
vector<string> lst;
vector<vector<int>> trans;
set<string> forbidden;

void gen() {
	lst.clear(); mp.clear(); forbidden.clear();
	queue<string> q;
	q.push("");
	while (!q.empty()) {
		string s = q.front(); q.pop();
		lst.PB(s); mp[s] = SZ(lst) - 1;
		int sum = 0; REPSZ(i, s) sum += s[i] - '0';
		FORE(d, 1, 9) if (sum + d <= x) {
			int cur = d;
			bool ok = true;
			for (int i = SZ(s); i >= 0; --i) {
				if (i < SZ(s)) cur += s[i] - '0';
				if (cur < x && x % cur == 0) ok = false;
			}
			if (!ok) continue;
			string ns = s + string(1, '0' + d);
			if (sum + d == x) forbidden.insert(ns); else q.push(ns);
		}
	}
	//printf("%d: %d %d\n", x, SZ(lst), SZ(forbidden));
	trans = vector<vector<int>>(SZ(lst), vector<int>(10, -1));
	REPSZ(i, lst) FORE(d, 1, 9) {
		string ns = lst[i] + string(1, '0' + d);
		while(true) {
			if (forbidden.count(ns)) break;
			if (mp.count(ns)) { trans[i][d] = mp[ns]; break; }
			ns = ns.substr(1);
		}
	}
	//REPSZ(i, lst) { printf("'%s':", lst[i].c_str()); FORE(d, 1, 9) if (trans[i][d] == -1) printf(" X"); else printf(" '%s'", lst[trans[i][d]].c_str()); puts(""); }
}

vector<int> dp[MAXLEN + 1];

int solve() {
	gen();
	REPE(i, slen) dp[i] = vector<int>(SZ(lst), INT_MAX);
	dp[0][mp[""]] = 0;
	REPE(i, slen) REPSZ(j, lst) if (dp[i][j] != INT_MAX) {
		//printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
		if (i == slen) continue;
		int d = s[i] - '0', nj = trans[j][d];
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
		if (nj != -1) dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + 0);
	}
	int ret = INT_MAX; REPSZ(j, lst) ret = min(ret, dp[slen][j]); return ret;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &x);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}