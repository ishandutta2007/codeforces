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
#include <functional>
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

const int MAXN = 200000;
const int MAXM = 200000;
const int IRRELEVANT = 1;
const int DESTINED = 2;

int n, m;
int ekind[MAXM], e[MAXM][2];
char ansdir[MAXN]; int ansx[MAXN];

bool solve() {
	vector<vector<int>> oppo(n);
	REP(i, m) { int a = e[i][0], b = e[i][1]; oppo[a].PB(b); oppo[b].PB(a); }

	vector<int> col(n, -1); // 0==right, 1==left
	REP(i, n) if (col[i] == -1) {
		queue<int> q;
		col[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : oppo[at]) {
				if (col[to] == col[at]) return false;
				if (col[to] == -1) col[to] = 1 - col[at], q.push(to);
			}
		}
	}
	REP(i, n) ansdir[i] = col[i] == 0 ? 'R' : 'L';

	vector<vector<int>> after(n);
	REP(i, m) {
		int a = e[i][0], b = e[i][1];
		assert(col[a] != col[b]);
		if (col[a] > col[b]) swap(a, b);
		if (ekind[i] == IRRELEVANT) after[b].PB(a);
		if (ekind[i] == DESTINED) after[a].PB(b);
	}
	vector<int> deg(n, 0);
	REP(at, n) for (int to : after[at]) ++deg[to];
	queue<int> q;
	int x = 0;
	REP(at, n) if (deg[at] == 0) ansx[at] = x++, q.push(at);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : after[at]) if (--deg[to] == 0) ansx[to] = x++, q.push(to);
	}
	REP(i, n) if (deg[i] != 0) return false;
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &ekind[i], &e[i][0], &e[i][1]), --e[i][0], --e[i][1];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) printf("%c %d\n", ansdir[i], ansx[i]);
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}