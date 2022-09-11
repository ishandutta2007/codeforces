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

const int MAXLEN = 500000;

char s[MAXLEN + 1]; int slen;

char a[MAXLEN + 1];
int bal[MAXLEN + 1];

bool solve() {
	int nopen = 0, nclose = 0, nquestion = 0;
	REP(i, slen) if (s[i] == '(') ++nopen; else if (s[i] == ')') ++nclose; else if (s[i] == '?') ++nquestion; else assert(false);
	assert(slen % 2 == 0);
	assert(nopen <= slen / 2 && nclose <= slen / 2);
	int remopen = slen / 2 - nopen, remclose = slen / 2 - nclose;
	REPE(i, slen) a[i] = s[i];
	REP(i, slen) if (a[i] == '?') {
		if (remopen > 0) a[i] = '(', --remopen;
		else if (remclose > 0) a[i] = ')', --remclose;
		else assert(false);
	}
	assert(remopen == 0 && remclose == 0);
	bal[0] = 0; REP(i, slen) bal[i + 1] = bal[i] + (a[i] == '(' ? +1 : -1);
	assert(bal[slen] == 0);
	REPE(i, slen) assert(bal[i] >= 0);
	bool haveopen = false;
	REP(i, slen) {
		if (s[i] == '?' && a[i] == '(') haveopen = true;
		else if (bal[i] < 2) haveopen = false;
		if (s[i] == '?' && a[i] == ')' && haveopen) return false;
	}
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}