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

const int MAXN = 100;

int n;
char ans[MAXN + 1];

vector<string> query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1); fflush(stdout);
	vector<string> ret;
	int len = r - l + 1;
	int cnt = (1 + len) * len / 2;
	char buff[MAXN + 1];
	REP(i, cnt) { scanf("%s", buff); if (strcmp(buff, "-") == 0) exit(0); ret.PB(buff); }
	return ret;
}

char diff(string a, string b) {
	assert(SZ(a) == SZ(b) + 1);
	int idx = 0; while (idx < SZ(b) && a[idx] == b[idx]) ++idx;
	FORSZ(i, idx + 1, a) assert(a[i] == b[i - 1]);
	return a[idx];
}

void solve() {
	if (n == 1) { vector<string> fst = query(0, 0); assert(SZ(fst) == 1 && SZ(fst[0]) == 1); char fstchar = fst[0][0];  ans[0] = fstchar; ans[1] = '\0'; return; }
	vector<string> a = query(0, n - 1);
	vector<string> b = query(0, n - 2);
	REPSZ(i, a) sort(a[i].begin(), a[i].end());
	REPSZ(i, b) sort(b[i].begin(), b[i].end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<pair<int, string>> onlya, onlyb;
	int ata = 0, atb = 0;
	while (ata < SZ(a) || atb < SZ(b)) {
		if (ata < SZ(a) && (atb >= SZ(b) || a[ata] < b[atb])) { string s = a[ata++]; onlya.PB(MP(SZ(s), s)); continue; }
		if (atb < SZ(b) && (ata >= SZ(a) || b[atb] < a[ata])) { string s = b[atb++]; onlyb.PB(MP(SZ(s), s)); continue; }
		assert(ata < SZ(a) && atb < SZ(b) && a[ata] == b[atb]);
		++ata, ++atb;
	}
	sort(onlya.begin(), onlya.end());
	sort(onlyb.begin(), onlyb.end());
	assert(SZ(onlya) == n && SZ(onlyb) == 0);
	string prv = "";
	REP(i, n) {
		string s = onlya[i].second;
		ans[n - i - 1] = diff(s, prv);
		prv = s;
	}
	ans[n] = '\0';
}

void run() {
	scanf("%d", &n);
	solve();
	printf("! %s\n", ans); fflush(stdout);
}

int main() {
	run();
	return 0;
}