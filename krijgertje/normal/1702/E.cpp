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

int n;
int a[MAXN], b[MAXN];

vector<vector<int>> adj;
bool done[MAXN];

bool solve() {
	adj = vector<vector<int>>(n);
	REP(i, n) adj[a[i]].PB(i), adj[b[i]].PB(i);
	//REP(i, n) { printf("%d:", i + 1); for (int id : adj[i]) printf(" %d", id); puts(""); }
	REP(i, n) if (SZ(adj[i]) != 2) return false;
	REP(i, n) done[i] = false;
	REP(i, n) if (!done[i]) {
		int first = -1;
		int last = -1;
		int at = i;
		int len = 0;
		while (true) {
			//printf("at=%d first=%d last=%d len=%d\n", at + 1, first, last, len);
			if (first != -1 && at == i) break;
			if (done[at]) return false;
			done[at] = true;
			++len;
			int id = -1;
			for (int cid : adj[at]) if (cid != last) { id = cid; break; }
			assert(id != -1);
			if (first == -1) first = id;
			last = id;
			at = a[id] ^ b[id] ^ at;
		}
		if (len % 2 != 0) return false;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &a[i], &b[i]), --a[i], --b[i];
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}