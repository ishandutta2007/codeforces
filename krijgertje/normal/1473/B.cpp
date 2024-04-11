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

const int MAXLEN = 20;

char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1]; int tlen;
string ans;

bool solve() {
	int anslen = slen / gcd(slen, tlen) * tlen;
	ans = string(anslen, '?');
	REP(i, anslen) ans[i] = s[i % slen];
	REP(i, anslen) if (ans[i] != t[i % tlen]) return false;
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	if (!solve()) { printf("-1\n"); return; }
	cout << ans << endl;
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}