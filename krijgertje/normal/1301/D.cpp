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

int h, w, len;

int anslen;
vector<pair<int, string>> ans;

void updans(int times, string s) {
	int rem = len - anslen;
	int cnt = min(times, rem / SZ(s));
	if (cnt > 0) {
		ans.PB(MP(cnt, s));
		anslen += cnt * SZ(s);
		times -= cnt;
		rem -= cnt * SZ(s);
	}
	if (times > 0 && rem > 0) {
		assert(rem < SZ(s));
		ans.PB(MP(1, s.substr(0, rem)));
		anslen += rem;
	}
}

bool solve() {
	anslen = 0; ans.clear();
	updans(w - 1, "R");
	updans(w - 1, "L");
	REP(x, h - 1) {
		updans(1, "D");
		updans(w - 1, "RUD");
		updans(w - 1, "L");
	}
	updans(h - 1, "U");
	return anslen == len;
}

void run() {
	scanf("%d%d%d", &h, &w, &len);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %s\n", ans[i].first, ans[i].second.c_str());
}

int main() {
	run();
	return 0;
}