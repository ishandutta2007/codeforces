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

const int MAXN = 100000;

int n, m;
set<pair<int, int>> compare;

int a[MAXN];
int b[MAXN];

int mp[MAXN];

bool solve() {
	REP(i, n) FOR(j, i + 1, n) if (!compare.count(MP(i, j))) {
		REP(k, n) mp[k] = -1; mp[i] = mp[j] = -2;
		int at = 2; REP(k, n) if (mp[k] == -1) mp[k] = at++;
		REP(k, n) a[k] = k == i ? 0 : k == j ? 1 : mp[k];
		REP(k, n) b[k] = k == i ? 0 : k == j ? 0 : mp[k];
		return true;
	}
	return false;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; compare.insert(MP(a, b)); compare.insert(MP(b, a)); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i] + 1); } puts("");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i] + 1); } puts("");
}


int main() {
	run();
	return 0;
}