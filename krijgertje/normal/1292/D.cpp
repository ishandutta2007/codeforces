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

const int MAXN = 1000000;
const int MAXA = 5000;
struct Node { vector<int> ch; int leafcnt; ll leafsum; Node() { ch.clear(); leafcnt = 0; leafsum = 0; } };

int n;
int a[MAXN];

int pmn[MAXA + 1];
int pidx[MAXA + 1];
vector<int> p;

vector<int> pcnt[MAXA + 1];
int acnt[MAXA + 1];


vector<Node> nodes;
int makenode() { int ret = SZ(nodes); nodes.PB(Node()); return ret; }

ll go(int at, ll sofar, int pathsum) {
	//if (nodes[at].leafcnt > 0) printf("go(%d,%lld,%d)\n", at, sofar, pathsum);
	int donecnt = n - nodes[at].leafcnt, remcnt = nodes[at].leafcnt; ll totsum = sofar + nodes[at].leafsum - (ll)nodes[at].leafcnt * pathsum;
	ll ret = totsum;
	REPSZ(i, nodes[at].ch) {
		int to = nodes[at].ch[i];
		if (to != -1) {
			ll cursum = totsum - (nodes[to].leafsum - ((ll)nodes[to].leafcnt * (pathsum + i)));
			//printf("\tgo(%d,%lld,%d) -> i=%d -> cursum=%lld (totsum=%lld,leafsum=%lld)\n", at, sofar, pathsum, i, cursum, totsum, nodes[to].leafsum);
			ll cur = go(to, cursum, pathsum + i); ret = min(ret, cur);
		}
		int curcnt = to == -1 ? 0 : nodes[to].leafcnt;
		donecnt += curcnt, remcnt -= curcnt;
		totsum -= remcnt, totsum += donecnt;
	}
	return ret;
}

ll solve() {
	REPE(i, MAXA) pmn[i] = -1; FORE(i, 2, MAXA) if (pmn[i] == -1) for (int j = i; j <= MAXA; j += i) if (pmn[j] == -1) pmn[j] = i;
	REPE(i, MAXA) pidx[i] = -1; p.clear(); REPE(i, MAXA) if (pmn[i] == i) { pidx[i] = SZ(p); p.PB(i); }
	pcnt[0] = vector<int>(SZ(p), 0);
	FORE(i, 1, MAXA) { pcnt[i] = pcnt[i - 1]; int x = i; while (pmn[x] != -1) { ++pcnt[i][pidx[pmn[x]]]; x /= pmn[x]; } }
	REPE(i, MAXA) acnt[i] = 0; REP(i, n) ++acnt[a[i]];

	//REPE(i, MAXA) { printf("%d:", i); REPSZ(j, pcnt[i]) printf(" %d", pcnt[i][j]); puts(""); }

	nodes.clear(); int root = makenode();
	REPE(i, MAXA) {
		int at = root;
		int psum = 0; REPSZ(j, p) psum += pcnt[i][j];
		for (int j = SZ(p) - 1; j >= 0; --j) {
			nodes[at].leafcnt += acnt[i]; nodes[at].leafsum += (ll)acnt[i] * psum;
			int x = pcnt[i][j];
			while (x >= SZ(nodes[at].ch)) nodes[at].ch.PB(-1);
			int to = nodes[at].ch[x]; if (to == -1) { to = makenode(); nodes[at].ch[x] = to; }
			at = to;
		}
		nodes[at].leafcnt += acnt[i]; nodes[at].leafsum += (ll)acnt[i] * psum;
	}

	return go(root, 0, 0);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}