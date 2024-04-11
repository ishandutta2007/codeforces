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

const int MAXN = 1000;
struct P { int x, y; };
bool operator<(const P &a, const P &b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }

int n;
P p[MAXN];

string ans;

bool solve() {
	sort(p, p + n);
	REP(i, n - 1) if (p[i + 1].y < p[i].y) return false;
	int x = 0, y = 0; ans = "";
	REP(i, n) {
		assert(x <= p[i].x); while (x < p[i].x) ans += "R", ++x;
		assert(y <= p[i].y); while (y < p[i].y) ans += "U", ++y;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n", ans.c_str());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}