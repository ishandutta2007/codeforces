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
const int MAXQ = 200000;

int n;
int initval[MAXN];
int initperm[MAXN];
int nq;
int qkind[MAXQ], qa[MAXQ], qb[MAXQ];
ll qans[MAXQ];



int pnxt[MAXN], pprv[MAXN];
int blocksz, heavysz;
int block[MAXN], nblock;
int pathid[MAXN];
queue<int> pathless;
ll curval[MAXN];
vector<ll> blocksum;
set<int> heavypaths;

struct Path {
	vector<int> seq;
	ll lazy;
	bool isheavy, isalive;
	vector<int> blocksum; // only if isheavy: blocksum[i] = cnt(j in seq: block[j]<i)
	Path() { lazy = 0; isheavy = false; isalive = true; }
	bool iscycle() { return pnxt[seq.back()] == seq[0]; }
};

vector<Path> paths;

void destroypath(int id) {
	if (id == -1) return;
	Path path = paths[id];
	paths[id] = Path(); paths[id].isalive = false;
	for (int x : path.seq) pathid[x] = -1, pathless.push(x);
	if (path.lazy != 0) for (int x : path.seq) curval[x] += path.lazy, blocksum[block[x]] += path.lazy;
	heavypaths.erase(id);
}

void addpath(Path path) {
	for (int x : path.seq) pathid[x] = SZ(paths);
	if (SZ(path.seq) >= heavysz) {
		path.isheavy = true;
		path.blocksum = vector<int>(nblock + 1, 0);
		for (int x : path.seq) ++path.blocksum[block[x] + 1];
		REP(i, nblock) path.blocksum[i + 1] += path.blocksum[i];
		heavypaths.insert(SZ(paths));
	}
	paths.PB(path);
}

void printpaths() {
	printf("curval:"); REP(i, n) printf(" %lld", curval[i]); puts("");
	printf("blocksum:"); REP(i, nblock) printf(" %lld", blocksum[i]); puts("");
	REPSZ(id, paths) if (paths[id].isalive) {
		printf("path%d:", id); for (int x : paths[id].seq) printf(" %d", x + 1); printf(" (%d) lazy=%lld%s\n", pnxt[paths[id].seq.back()] + 1, paths[id].lazy, heavypaths.count(id) ? " heavy" : "");
		if (paths[id].isheavy) { printf("\t"); REPSZ(i, paths[id].blocksum) printf(" %d", paths[id].blocksum[i]); puts(""); }
	}
}

void makepaths() {
	while (!pathless.empty()) {
		int at = pathless.front(); pathless.pop();
		if (pathid[at] != -1) continue;
		int front = at;
		while (pprv[front] != at&&pathid[pprv[front]] == -1) front = pprv[front];
		Path path;
		at = front;
		while (true) {
			path.seq.PB(at);
			at = pnxt[at];
			if (at == front || pathid[at] != -1) break;
		}
		while (SZ(path.seq) < heavysz && !path.iscycle()) {
			int prvid = pathid[pprv[path.seq[0]]];
			path.seq.insert(path.seq.begin(), paths[prvid].seq.begin(), paths[prvid].seq.end());
			destroypath(prvid);
		}
		while (SZ(path.seq) < heavysz && !path.iscycle()) {
			int nxtid = pathid[pnxt[path.seq.back()]];
			path.seq.insert(path.seq.end(), paths[nxtid].seq.begin(), paths[nxtid].seq.end());
			destroypath(nxtid);
		}
		while (SZ(path.seq) >= 2 * heavysz) {
			Path tailpath;
			tailpath.seq = vector<int>(path.seq.end() - heavysz, path.seq.end());
			path.seq.erase(path.seq.end() - heavysz, path.seq.end());
			addpath(tailpath);
		}
		addpath(path);
	}
	//printpaths();
}

void solve() {
	REP(i, n) pnxt[i] = initperm[i];
	REP(i, n) pprv[pnxt[i]] = i;

	blocksz = sqrt(1.0*n);
	heavysz = sqrt(1.0*n);
	nblock = (n + blocksz - 1) / blocksz;
	REP(i, n) block[i] = i / blocksz;
	blocksum = vector<ll>(nblock, 0);
	REP(i, n) curval[i] = initval[i];
	REP(i, n) blocksum[block[i]] += curval[i];
	paths.clear();
	pathless = queue<int>();
	REP(i, n) pathid[i] = -1, pathless.push(i);
	heavypaths = set<int>();
	makepaths();

	REP(i, nq) {
		//printf("q%d:\n", i);
		if (qkind[i] == 1) {
			int l = qa[i], r = qb[i];
			ll ans = 0;
			while (l <= r && l % blocksz != 0) {
				ans += curval[l] + paths[pathid[l]].lazy;
				++l;
			}
			while (l <= r && r % blocksz != blocksz - 1) {
				ans += curval[r] + paths[pathid[r]].lazy;
				--r;
			}
			if (l <= r) {
				int bl = l / blocksz, br = r / blocksz;
				FORE(b, bl, br) ans += blocksum[b];
				for (int id : heavypaths) ans += paths[id].lazy*(paths[id].blocksum[br + 1] - paths[id].blocksum[bl]);
			}
			qans[i] = ans;
		}
		if (qkind[i] == 2) {
			int at = qa[i], by = qb[i];
			int front = pathid[at];
			if (!paths[front].isheavy) {
				for (int x : paths[front].seq) curval[x] += by, blocksum[block[x]] += by;
			} else {
				at = front;
				while (true) {
					assert(paths[at].isheavy);
					paths[at].lazy += by;
					at = pathid[pnxt[paths[at].seq.back()]];
					if (at == front) break;
				}
			}
			//printpaths();
		}
		if (qkind[i] == 3) {
			int a = qa[i], b = qb[i];
			destroypath(pathid[a]);
			destroypath(pathid[b]);
			swap(pnxt[a], pnxt[b]);
			pprv[pnxt[a]] = a, pprv[pnxt[b]] = b;
			makepaths();
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &initval[i]);
	REP(i, n) scanf("%d", &initperm[i]), --initperm[i];
	scanf("%d", &nq);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
		if (qkind[i] == 2) scanf("%d%d", &qa[i], &qb[i]), --qa[i];
		if (qkind[i] == 3) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 1) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}