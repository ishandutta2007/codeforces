#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXOP = 10;
const int MAXOPLEN = 3;
const int MAXLEN = MAXOPLEN*MAXOP + (MAXOP - 1);

char s[MAXLEN + 1];
char d[MAXOPLEN]; int nd;

void run() {
	scanf("%s", s);
	int ans = 0, at = 0, sgn = +1;
	while (true) {
		int cur = 0; while (s[at] >= '0'&&s[at] <= '9') cur = cur * 10 + s[at++] - '0';
		ans += sgn*cur;
		char c = s[at++]; if (c == '+') sgn = +1; else if (c == '-') sgn = -1; else break;
	}
	nd = 0; if (ans == 0) d[nd++] = '0'; else for (int x = ans; x > 0; x /= 10) d[nd++] = '0' + x % 10;
	for (int i = nd - 1; i >= 0; --i) { if (i != nd - 1) printf(">"); int t = (int)d[i]; REP(j, t) printf("+"); printf("."); } puts("");
}

int main() {
	run();
	return 0;
}