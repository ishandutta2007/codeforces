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

const int MAXLEN = 2000000;

int slen;
char s[MAXLEN + 1];
int ansl, ansr;

map<pair<int, int>, int> last;

bool solve() {
	int x = 0, y = 0; bool ret = false;
	last.clear(); last[MP(x, y)] = 0;
	REP(i, slen) {
		if (s[i] == 'R') ++x; else if (s[i] == 'L') --x; else if (s[i] == 'U') ++y; else if (s[i] == 'D') --y; else assert(false);
		pair<int, int> key = MP(x, y);
		if (last.count(key)) { int cl = last[key], cr = i; if (!ret || cr - cl < ansr - ansl) ret = true, ansl = cl, ansr = cr; }
		last[key] = i + 1;
	}
	return ret;
}

void run() {
	scanf("%d", &slen);
	scanf("%s", s); assert(strlen(s) == slen);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d %d\n", ansl + 1, ansr + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}