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

const int MAXLEN = 100000;

char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1]; int tlen;

vector<int> zarray(char *s) {
	//printf("%s\n", s);
	int n = strlen(s), l = 0, r = 1; vector<int> z(n, -1); // [l,r) is a prefix of s
	FOR(i, 1, n) if (i < r && z[i - l] < r - i) z[i] = z[i - l]; else { l = i, r = max(r, i); while (r < n&&s[r - l] == s[r]) ++r; z[i] = r - l; }
	//printf("z:"); REP(i, n) printf(" %d", z[i]); puts("");
	return z;
}
vector<int> kmparray(char *s) {
	//printf("%s\n", s);
	int n = strlen(s); vector<int> kmp(n + 1, 0);
	FORE(i, 2, n) { int cur = kmp[i - 1]; while (cur != 0 && s[i - 1] != s[cur]) cur = kmp[cur]; if (s[i - 1] == s[cur]) ++cur; kmp[i] = cur; }
	//printf("kmp:"); REPE(i, n) printf(" %d", kmp[i]); puts("");
	return kmp;
}

char tmp[MAXLEN + 1 + MAXLEN + 1]; int tmplen;
vector<int> z;
vector<int> kmp;
int cnt[MAXLEN + 1];

ll solve() {
	tmplen = 0; REP(i, tlen) tmp[tmplen++] = t[i]; tmp[tmplen++] = '#'; REP(i, slen) tmp[tmplen++] = s[i]; tmp[tmplen] = '\0';
	z = zarray(tmp);
	kmp = kmparray(t);
	REPE(i, tlen) cnt[i] = 0;
	FORE(i, 1, tlen) if (kmp[i] != 0) ++cnt[i - kmp[i]];
	FORE(i, 1, tlen) cnt[i] += cnt[i - 1];
	//printf("cnt:"); REPE(i, tlen) printf(" %d", cnt[i]); puts("");
	ll ret = 0;
	FORE(i, 1,slen) {
		int common = i == slen ? 0 : z[tlen + 1 + i];
		int cur = tlen - cnt[common];
		//printf("%d: common=%d -> cur=%d\n", i, common, cur);
		ret += cur;
	}
	return ret;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}