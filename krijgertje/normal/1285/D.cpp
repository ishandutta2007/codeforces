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

const int MAXN = 100000;
struct Node { int c[2]; Node() { c[0] = c[1] = -1; } };

int n;
int a[MAXN];

vector<Node> nodes;
int makenode() { int ret = SZ(nodes); nodes.PB(Node()); return ret; }

ll go(int at, int bit) {
	if (bit < 0) return 0;
	ll ret = LLONG_MAX;
	REP(x, 2) if (nodes[at].c[x] != -1) ret = min(ret, go(nodes[at].c[x], bit - 1));
	if (nodes[at].c[0] != -1 && nodes[at].c[1] != -1) ret += 1LL << bit;
	return ret;
}

ll solve() {
	sort(a, a + n); n = unique(a, a + n) - a;
	int mx = a[n - 1];
	if (mx == 0) return 0;
	int mxbit = 0; while (mx >= (2LL << mxbit)) ++mxbit;
	//printf("mx=%d mxbit=%d\n", mx, mxbit);
	
	nodes.clear();
	int root = makenode();
	REP(i, n) {
		int at = root;
		for (int bit = mxbit; bit >= 0; --bit) {
			int x = (a[i] >> bit) & 1;
			int to = nodes[at].c[x]; if (to == -1) { to = makenode(); nodes[at].c[x] = to; }
			at = to;
		}
	}
	return go(root, mxbit);
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