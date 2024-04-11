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

const int MAXN = 300000;

int n;
int startlabel[MAXN];
vector<int> adj[MAXN];
ll anst;
int anslabel[MAXN];

int par[MAXN];
int dep[MAXN];
vector<int> ch[MAXN];

int curlabel[MAXN];
int curpos[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

int dfsanslabel(int at,int lab) {
	int ret = 1;
	anslabel[at] = lab;
	for (int to : ch[at]) ret += dfsanslabel(to, lab + ret);
	return ret;
}

int expectlabel[MAXN];
int ord[MAXN], nord;
bool blocked[MAXN];

int dfspushed(int at, int rem) {
	int ret = 0;
	for (int to : ch[at]) ret += dfspushed(to, rem - ret);
	if (ret < rem) blocked[at] = true, ord[nord++] = at, ++ret, anst += dep[at];
	return ret;
}
void dfsother(int at) {
	if (!blocked[at]) ord[nord++] = at;
	for (int to : ch[at]) dfsother(to);
}

bool solve() {
	par[0] = -1; dfsinit(0);
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);

	REP(i, n) sort(ch[i].begin(), ch[i].end(), [&](const int& a, const int& b) { return startlabel[a] < startlabel[b]; });
	anst = 0;
	dfsanslabel(0, 0);

	REP(i, n) curlabel[i] = startlabel[i];
	REP(i, n) curpos[curlabel[i]] = i;
	
	if (curlabel[0] != 0) {
		int lab = curlabel[0] - 1;
		while (curpos[lab] != 0) {
			int at = curpos[lab];
			int to = par[at];
			++anst;
			swap(curlabel[at], curlabel[to]);
			swap(curpos[curlabel[at]], curpos[curlabel[to]]);
		}
	}
	int finpushes = anst;

	nord = 0;
	REP(i, n) blocked[i] = false;
	dfspushed(0, curlabel[0]);
	dfsother(0);
	REP(i, n) expectlabel[ord[i]] = i;
	//printf("ord:"); REP(i, nord) printf(" %d", ord[i] + 1); puts("");
	//printf("curlabel:"); REP(i, n) printf(" %d", curlabel[i]); puts("");
	//printf("expectlabel:"); REP(i, n) printf(" %d", expectlabel[i]); puts("");

	REP(i, n) if (expectlabel[i] != curlabel[i]) return false;

	if (finpushes != 0) {
		int lab = curlabel[0];
		REP(i, finpushes) {
			int at = curpos[lab];
			int best = -1;
			for (int to : ch[at]) if (lab < curlabel[to] && (best == -1 || curlabel[to] < curlabel[best])) best = to;
			if (best == -1) return false;
			swap(curlabel[at], curlabel[best]);
			swap(curpos[curlabel[at]], curpos[curlabel[best]]);
		}
	}
	REP(i, n) if (startlabel[i] != curlabel[i]) return false;

	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &startlabel[i]), --startlabel[i];
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%lld\n", anst);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", anslabel[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}