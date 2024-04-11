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
#include <functional>
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

const int MAXLEN = 300000;
const int MAXS = 4 * (MAXLEN + 1);

char s[MAXLEN + 1]; int slen;
string ans;

int bal[MAXLEN + 1];
int nxt[MAXLEN + 1];


string go(int l, int r) {
	//printf("go(%d,%d)\n", l, r);
	vector<string> parts;
	int at = l;
	while (at != r) {
		int to = nxt[at];
		assert(to != -1 && to <= r);
		string cur = "(" + go(at + 1, to - 1) + ")";
		while (SZ(parts) > 0 && cur < parts.back()) parts.pop_back();
		parts.PB(cur);
		at = to;
	}
	string ret;
	REPSZ(i, parts) ret += parts[i];
	return ret;
}

void solve() {
	bal[0] = 0;
	REP(i, slen) bal[i + 1] = bal[i] + (s[i] == '(' ? +1 : -1);

	int lobal = 0;
	REPE(i, slen) lobal = min(lobal, bal[i]);
	REPE(i, slen) bal[i] -= lobal;
	int hibal = 0;
	REPE(i, slen) hibal = max(hibal, bal[i]);

	vector<int> last(hibal + 1, -1);
	for (int i = slen; i >= 0; --i) {
		nxt[i] = last[bal[i]];
		last[bal[i]] = i;
	}

	ans = "";
	int at = 0;
	while (at < slen) {
		if (s[at] == ')') {
			ans += ")";
			++at;
			continue;
		}
		int to = nxt[at];
		while (true) {
			if (to == -1 || to >= slen || s[to] == ')') break;
			to = nxt[to];
		}
		if (to == -1 || to == slen) {
			assert(bal[slen] >= bal[at]);
			REP(i, bal[slen] - bal[at]) ans += "(";
			break;
		}
		ans += go(at, to);
		at = to;
	}
}

void run() {
	scanf("%s", s); slen = strlen(s);
	solve();
	printf("%s\n", ans.c_str());
}

int main() {
	run();
	return 0;
}