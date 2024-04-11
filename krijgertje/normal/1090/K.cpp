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
const int MAXTOTLEN = 1000000;
struct TrieNode { int nxt[26]; int id; };

char s[MAXTOTLEN + 2 * MAXN]; int ns = 0;

int n;
char *a[MAXN], *b[MAXN]; int alen[MAXN], blen[MAXN];

int mask[MAXN];
pair<int, int> o[MAXN];

TrieNode tnode[MAXTOTLEN + 1]; int nt;
vector<int> group[MAXN];
int tmake() { assert(nt < MAXTOTLEN + 1); int ret = nt++; memset(tnode[ret].nxt, -1, sizeof(tnode[ret].nxt)); tnode[ret].id = -1; return ret; }

vector<vector<int>> ans;

void solve() {
	//REP(i, n) printf("%s %s\n", a[i], b[i]);
	REP(i, n) { mask[i] = 0; REP(j, blen[i]) mask[i] |= 1 << (b[i][j] - 'a'); }
	REP(i, n) while (alen[i] > 0 && (mask[i] & (1 << (a[i][alen[i] - 1] - 'a'))) != 0) a[i][--alen[i]] = '\0';
	//REP(i, n) { printf("'%s' ", a[i]); REP(k, 26) if (mask[i] & (1 << k)) printf("%c", 'a' + k); puts(""); }
	REP(i, n) o[i] = MP(mask[i], i); sort(o, o + n); REP(i, n) group[i].clear();
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n&&o[l].first == o[r].first) ++r;
		//printf("testing:"); FOR(i, l, r) printf(" %d", o[i].second + 1); puts("");
		nt = 0; int root = tmake();
		FOR(i, l, r) {
			int idx=o[i].second, at = root;
			REP(j, alen[idx]) {
				int x = a[idx][j] - 'a';
				if (tnode[at].nxt[x] == -1) tnode[at].nxt[x] = tmake();
				at = tnode[at].nxt[x];
			}
			if (tnode[at].id == -1) tnode[at].id = idx;
			group[tnode[at].id].PB(idx);
		}
	}
	ans.clear(); REP(i, n) if (SZ(group[i]) != 0) ans.PB(group[i]);
}

void run() {
	scanf("%d", &n);
	ns = 0; REP(i, n) REP(j, 2) { scanf("%s", s + ns); int len = strlen(s + ns); if (j == 0) a[i] = s + ns, alen[i] = len; else b[i] = s + ns, blen[i] = len; ns += len + 1; }
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { printf("%d", SZ(ans[i])); REPSZ(j, ans[i]) printf(" %d", ans[i][j] + 1); puts(""); }
}


int main() {
	run();
	return 0;
}