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

int n;

bool local = false;
string slocal;
double cost;

string convert(string s) {
	REPSZ(i, s) if (s[i] == 'a') s[i] = 'C'; else if (s[i] == 'b') s[i] = 'H'; else if (s[i] == 'c') s[i] = 'O'; else assert(false);
	return s;
}

vector<int> query(string s) {
	cost += 1.0 / SZ(s) / SZ(s);
	if (!local) {
		printf("? %s\n", convert(s).c_str()); fflush(stdout);
		int cnt; scanf("%d", &cnt); if (cnt == -1) exit(0); vector<int> ret(cnt); REP(i, cnt) scanf("%d", &ret[i]), --ret[i]; return ret;
	} else {
		vector<int> ret;
		REPE(i, SZ(slocal) - SZ(s)) {
			bool ok = true; REPSZ(j, s) if (slocal[i + j] != s[j]) ok = false; if (ok) ret.PB(i);
		}
		return ret;
	}
}

void process(string &s, const string &q) {
	vector<int> pos = query(q);
	REPSZ(i, pos) REPSZ(j, q) { int k = pos[i] + j; assert(k >= 0 && k < SZ(s) && (s[k] == '?' || s[k] == q[j])); s[k] = q[j]; }
}

string solve() {
	string ret(n, '?');
	process(ret, "bc");
	process(ret, "cb");
	process(ret, "ab");
	process(ret, "ac");
	if (n == 4 && ret[1] != '?'&&ret[2] != '?') {
		string mid = ret.substr(1, 2);
		REP(i, 3) if (ret[3] == '?') {
			char c = 'a' + i;
			if (i + 1 < 3) process(ret, mid + string(1, c)); else ret[3] = c;
		}
		string suff = ret.substr(1, 3);
		REP(i, 3) if (ret[0] == '?') {
			char c = 'a' + i;
			if (i + 1 < 3) process(ret, string(1, c) + suff); else ret[0] = c;
		}
		return ret;
	}
	if (ret == "????") {
		process(ret, "aaa");
		process(ret, "bbb");
		process(ret, "ccc");
		if (ret == "????") {
			process(ret, "bbaa");
			if (ret == "????") ret = "ccaa";
		} else if(ret=="?aaa") {
			process(ret, "baaa");
			if (ret == "?aaa") ret = "caaa";
		} else if (ret[3] == '?') {
			ret[3] = 'a';
		}
		return ret;
	}
	process(ret, "aa");
	REP(i, n - 2) if (ret[i] != '?'&&ret[i + 1] == '?') {
		assert(ret[i] == 'b' || ret[i] == 'c');
		ret[i + 1] = ret[i];
	}
	// only segment at the beginning and single item at the end may be unknown, with at most two options for each:
	// * if first segment is unknown, it has to be all same characters and cannot be a
	// * if last item is unknown, it can be a or same character as previous
	vector<string> opt;
	REP(x, 2) REP(y, 2) {
		string cur = ret;
		if (cur[0] != '?') { if (x == 1) continue; } else { char c = 'b' + x; REP(i, n - 1) if (cur[i] == '?') cur[i] = c; }
		if (cur[n - 1] != '?') { if (y == 1) continue; } else { char c = y == 0 ? 'a' : cur[n - 2]; if (y == 1 && c == 'a') continue; cur[n - 1] = c; }
		opt.PB(cur);
	}
	assert(SZ(opt) >= 1);
	REPSZ(i, opt) {
		if (i + 1 >= SZ(opt)) return opt[i];
		vector<int> pos = query(opt[i]);
		if (SZ(pos) > 0) return opt[i];
	}
	assert(false); return "error";
}

void run() {
	scanf("%d", &n);
	string ans = solve();
	printf("! %s\n", convert(ans).c_str()); fflush(stdout);
	int res; scanf("%d", &res); if (res == 0) exit(0);
}

void stress() {
	double mxcost = 0;
	for (n = 4; n <= 8; ++n) {
		string want(n, 'a');
		while (true) {
			slocal = want; local = true; cost = 0;
			string have = solve();
			if (cost > mxcost || have != want) printf("have=%s want=%s -> %lf\n", have.c_str(), want.c_str(), cost), mxcost = cost;
			assert(have == want);
			int idx = n - 1; while (idx >= 0 && want[idx] == 'c') want[idx--] = 'a'; if (idx >= 0) ++want[idx]; else break;
		}
		printf("done %d\n", n);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}