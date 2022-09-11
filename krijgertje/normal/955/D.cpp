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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXLEN = 500000;

int slen, tlen, sz;
char s[MAXLEN + 1];
char t[MAXLEN + 1];

int pref[MAXLEN + 1],fst; // pref[i] is minimum k>=sz such that s[0..k) ends with t[0..i)
int suff[MAXLEN + 1],lst; // suff[i] is maximum k<=slen-sz such that s[k..slen) starts with t[i..tlen)

int nxt[MAXLEN + 1]; // nxt[i] is maximum k<i such that t[0..i) starts and ends with t[0..k)

void calc(int *res,int &fst) {
	nxt[0] = nxt[1] = 0;
	FORE(i, 2, tlen) {
		int cur = nxt[i - 1];
		while (cur > 0 && t[cur] != t[i - 1]) cur = nxt[cur];
		if (t[cur] == t[i - 1]) ++cur;
		nxt[i] = cur;
	}
	//printf("nxt:"); REPE(i, tlen) printf(" %d", nxt[i]); puts("");

	int at = 0;
	REPE(i, tlen) res[i] = -1; fst = -1;
	if (at >= sz) res[at] = 0;
	REP(i, slen) {
		while (at > 0 && t[at] != s[i]) at = nxt[at];
		if (t[at] == s[i]) ++at;
		if (i + 1 >= sz && res[at] == -1) res[at] = i + 1;
		if (at == tlen && fst == -1) fst = i + 1;
		if (at == tlen) at = nxt[at];
	}
	for (int i = tlen; i > 0; --i) if (res[i] != -1 && (res[nxt[i]] == -1 || res[i] < res[nxt[i]])) res[nxt[i]] = res[i];
	//printf("res:"); REPE(i, tlen) printf(" %d", res[i]); puts("");
}

void run() {
	scanf("%d%d%d", &slen, &tlen, &sz); scanf("%s", s); scanf("%s", t);

	calc(pref, fst);
	reverse(s, s + slen); reverse(t, t + tlen);
	calc(suff, lst);
	reverse(s, s + slen); reverse(t, t + tlen);
	reverse(suff, suff + tlen + 1); REPE(i, tlen) if (suff[i] != -1) suff[i] = slen - suff[i];  if (lst != -1) lst = slen - lst;
	//printf("fst: %d, lst: %d\n", fst, lst);
	//printf("pref:"); REPE(i, tlen) printf(" %d", pref[i]); puts("");
	//printf("suff:"); REPE(i, tlen) printf(" %d", suff[i]); puts("");

	if (fst != -1 && fst < sz || lst != -1 && lst > slen - sz) { printf("Yes\n%d %d\n", 1, slen - sz + 1); return; }
	REPE(i, tlen) if (pref[i] != -1 && suff[i] != -1 && pref[i] <= suff[i] && i <= sz&&tlen - i <= sz) { printf("Yes\n%d %d\n", pref[i] - sz + 1, suff[i] + 1); return; }
	printf("No\n");
}

int main() {
	run();
	return 0;
}