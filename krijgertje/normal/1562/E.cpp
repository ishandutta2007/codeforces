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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 5000;
const int MAXNODE = MAXN * (MAXN + 1) / 2 + 1;
const int MAXTRANS = MAXNODE - 1;

int n;
char s[MAXN + 1];

struct Node {
	int dp;
	int transhead;
};
struct Trans {
	char c;
	int to;
	int transnxt;
};

Node node[MAXNODE]; int nnode;
Trans trans[MAXTRANS]; int ntrans;
int root;

int makenode() {
	assert(nnode < MAXNODE);
	int ret = nnode++;
	node[ret].dp = 0;
	node[ret].transhead = -1;
	return ret;
}
int findto(int at, char c) {
	for (int x = node[at].transhead; x != -1; x = trans[x].transnxt) if (trans[x].c == c) return trans[x].to;
	return -1;
}
int maketrans(int at, char c, int to) {
	assert(ntrans < MAXTRANS);
	int ret = ntrans++;
	trans[ret].c = c;
	trans[ret].to = to;
	trans[ret].transnxt = node[at].transhead;
	node[at].transhead = ret;
	return ret;
}

void go(int pos, int at, int sofar) {
	char c = s[pos];
	for (int x = node[at].transhead; x != -1; x = trans[x].transnxt) if (trans[x].c < c) sofar = max(sofar, node[trans[x].to].dp);
	int to = findto(at, c);
	assert(to != -1);
	node[to].dp = max(node[to].dp, sofar + 1);
	if (pos + 1 < n) go(pos + 1, to, sofar + 1);
	node[at].dp = max(node[at].dp, node[to].dp);
}

int solve() {
	nnode = ntrans = 0;
	root = makenode();
	REP(i, n) {
		int at = root;
		FOR(j, i, n) {
			char c = s[j];
			int to = findto(at, c);
			if (to == -1) {
				to = makenode();
				maketrans(at, c, to);
			}
			at = to;
		}
	}
	REP(i, n) go(i, root, 0);
	int ret = 0;
	REP(i, nnode) ret = max(ret, node[i].dp);
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}