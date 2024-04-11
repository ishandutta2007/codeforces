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

const int MAXN = 200000;
const int MAXNODE = MAXN * 32 + 1;
struct Subnet { int col; unsigned int val; int x; Subnet() {} Subnet(unsigned int val, int x) :col(1), val(val), x(x) {} };
struct Node { int c[2], mymask, subtreemask; };

int n;
char buff[100];
Subnet subnet[MAXN];
Subnet ans[MAXN]; int nans;

Node node[MAXNODE]; int nnode, root;
int makenode() { assert(nnode < MAXNODE); int ret = nnode++; node[ret].c[0] = node[ret].c[1] = -1; node[ret].mymask = node[ret].subtreemask = 0; return ret; }

bool dfs(int at, int dep, unsigned int val) {
	if (node[at].subtreemask == 0) return true;
	if (node[at].subtreemask == 1) return true;
	if (node[at].subtreemask == 2) { ans[nans++] = Subnet(val, dep); return true; }
	if (node[at].mymask != 0) return false;
	REP(k, 2) if (node[at].c[k] != -1) if (!dfs(node[at].c[k], dep + 1, val | k << (32 - dep - 1))) return false;
	return true;
}

bool solve() {
	nnode = 0; root = makenode();
	REP(i, n) {
		int at = root;
		REP(j, subnet[i].x) {
			node[at].subtreemask |= 1 << subnet[i].col;
			int k = (subnet[i].val >> (32 - j - 1)) & 1;
			if (node[at].c[k] == -1) node[at].c[k] = makenode();
			at = node[at].c[k];
		}
		node[at].subtreemask |= 1 << subnet[i].col;
		node[at].mymask |= 1 << subnet[i].col;
	}

	nans = 0;
	return dfs(root, 0, 0);
}

void run() {
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", buff);
		int at = 0; subnet[i].val = 0;
		{ char c = buff[at++]; assert(c == '-' || c == '+'); subnet[i].col = c == '-' ? 1 : 0; }
		{ unsigned int a = 0; while (isdigit(buff[at])) a = 10 * a + (buff[at++] - '0'); subnet[i].val |= a << 24; } assert(buff[at++] == '.');
		{ unsigned int b = 0; while (isdigit(buff[at])) b = 10 * b + (buff[at++] - '0'); subnet[i].val |= b << 16; } assert(buff[at++] == '.');
		{ unsigned int c = 0; while (isdigit(buff[at])) c = 10 * c + (buff[at++] - '0'); subnet[i].val |= c <<  8; } assert(buff[at++] == '.');
		{ unsigned int d = 0; while (isdigit(buff[at])) d = 10 * d + (buff[at++] - '0'); subnet[i].val |= d <<  0; }
		if (buff[at] != '/') subnet[i].x = 32; else { ++at; subnet[i].x = 0; while (isdigit(buff[at])) subnet[i].x = subnet[i].x * 10 + (buff[at++] - '0'); }
		assert(buff[at] == '\0');
	}
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", nans);
	REP(i, nans) printf("%d.%d.%d.%d/%d\n", ans[i].val >> 24, ans[i].val >> 16 & 255, ans[i].val >> 8 & 255, ans[i].val & 255, ans[i].x);
}

int main() {
	run();
	return 0;
}