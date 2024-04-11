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

const int MAXLEN = 300000;

char s[MAXLEN + 1]; int slen;

pair<char, int> t[MAXLEN]; int tlen;

int solve() {
	tlen = 0;
	for (int l = 0, r = l; l < slen; l = r) {
		while (r < slen&&s[r] == s[l]) ++r;
		t[tlen++] = MP(s[l], r - l);
	}
	if (tlen % 2 != 1) return 0;
	int mid = (tlen - 1) / 2;
	if (t[mid].second + 1 < 3) return 0;
	REP(i, mid) if (t[mid - i - 1].first != t[mid + i + 1].first || t[mid - i - 1].second + t[mid + i + 1].second < 3) return 0;
	return t[mid].second + 1;
}


void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}