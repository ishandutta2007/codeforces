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

const int MAXLEN = 200;
const int ALPH = 26;

char s[MAXLEN + 1]; int slen;
char ans[ALPH + 1];

vector<int> adj[ALPH];
bool done[ALPH];

bool solve() {
	REP(i, ALPH) adj[i].clear();
	REP(i, slen - 1) {
		int x = s[i] - 'a', y = s[i + 1] - 'a';
		adj[x].PB(y); adj[y].PB(x);
	}
	REP(i, ALPH) { sort(adj[i].begin(), adj[i].end()); adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end()); }
	//printf("SZ(adj):"); REP(i, ALPH) printf(" %d", SZ(adj[i])); puts("");
	REP(i, ALPH) if (SZ(adj[i]) >= 3) return false;
	int one = -1; REP(i, ALPH) if (SZ(adj[i]) == 1 && one == -1) one = i;
	if (one == -1) {
		REP(i, ALPH) if (SZ(adj[i]) >= 1) return false;
		REP(i, ALPH) ans[i] = 'a' + i; ans[ALPH] = '\0'; return true;
	}
	REP(i, ALPH) done[i] = false;
	int at = one, idx = 0;
	while (true) {
		ans[idx++] = 'a' + at; done[at] = true;
		int to = -1; REPSZ(i, adj[at]) { int tmp = adj[at][i]; if (done[tmp]) continue; assert(to == -1); to = tmp; } if (to == -1) break;
		at = to;
	}
	REP(i, ALPH) assert(done[i] == (SZ(adj[i]) >= 1));
	REP(i, ALPH) if (!done[i]) ans[idx++] = 'a' + i;
	assert(idx == ALPH);
	ans[ALPH] = '\0';
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}