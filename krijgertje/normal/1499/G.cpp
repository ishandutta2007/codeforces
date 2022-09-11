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

const int MAXSIDE = 200000;
const int MAXN = MAXSIDE + MAXSIDE;
const int MAXMINIT = 200000;
const int MAXQ = 200000;
const int MAXM = MAXMINIT + MAXQ;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }
struct Path { 
	bool alive; int start, end, evensum, oddsum; mutable deque<int> edges; mutable bool revedges; 
	void reverse() { swap(start, end); revedges = !revedges; if (SZ(edges) % 2 == 0) swap(evensum, oddsum); }
	void normalize() const { if (revedges) { revedges = !revedges; std::reverse(edges.begin(), edges.end()); } }
};

int na, nb;
int anshash;
vector<int> ans;

int n, m;
int endpoint[MAXN];
vector<Path> paths;
vector<Path> cycles;
int w[MAXM];

void appendedge(Path& p, int id) {
	if (SZ(p.edges) % 2 == 0) inc(p.evensum, w[id]); else inc(p.oddsum, w[id]);
	if (!p.revedges) p.edges.push_back(id); else p.edges.push_front(id);
}
void appendpath(Path& p, const Path& q) {
	q.normalize();
	for (int id : q.edges) appendedge(p, id);
}

void init() {
	n = na + nb;
	m = 0;
	REP(i, n) endpoint[i] = -1;
	anshash = 0;
	paths.clear();
	cycles.clear();
}
void addedge(int a, int b) {
	int id = m++;
	w[id] = id == 0 ? 2 : 2 * w[id - 1] % MOD;
	b += na;
	if (endpoint[a] == -1 && endpoint[b] == -1) {
		Path p; p.alive = true; p.start = a; p.end = b; p.evensum = p.oddsum = 0; p.edges.clear(); p.revedges = false; appendedge(p, id);
		int pid = SZ(paths); paths.PB(p);
		endpoint[a] = endpoint[b] = pid;
		inc(anshash, p.evensum);
	} else if (endpoint[a] == -1 || endpoint[b] == -1) {
		if (endpoint[a] == -1) swap(a, b);
		int pid = endpoint[a];
		Path& p = paths[pid];
		dec(anshash, p.evensum);
		if (p.end != a) p.reverse();
		appendedge(p, id);
		p.end = b;
		endpoint[a] = -1, endpoint[b] = pid;
		inc(anshash, p.evensum);
	} else if (endpoint[a] != endpoint[b]) {
		int pida = endpoint[a], pidb = endpoint[b];
		if (SZ(paths[pida].edges) < SZ(paths[pidb].edges)) swap(a, b), swap(pida, pidb);
		Path& pa = paths[pida], & pb = paths[pidb];
		dec(anshash, pa.evensum);
		dec(anshash, pb.evensum);
		if (pa.end != a) pa.reverse();
		if (pb.start != b) pb.reverse();
		appendedge(pa, id);
		appendpath(pa, pb);
		pa.end = pb.end;
		pb.alive = false;
		endpoint[a] = endpoint[b] = -1;
		endpoint[pa.end] = pida;
		inc(anshash, pa.evensum);
	} else {
		int pid = endpoint[a];
		Path& p = paths[pid];
		dec(anshash, p.evensum);
		if (p.end != b) p.reverse();
		assert(a == p.start && b == p.end && SZ(p.edges) % 2 == 1);
		appendedge(p, id);
		p.end = a;
		cycles.PB(p);
		endpoint[a] = endpoint[b] = -1;
		inc(anshash, p.evensum);
		p.alive = false;
	}
	//printf("endpoint:"); REP(i, n) printf(" %d", endpoint[i]); puts("");
	//for (const Path& p : paths) if (p.alive) { p.normalize(); printf("path %d->%d [%d vs %d]:", p.start + 1, p.end + 1, p.evensum, p.oddsum); for (int id : p.edges) printf(" %d", id + 1); puts(""); }
	//for (const Path& p : cycles) if (p.alive) { p.normalize(); printf("cycle %d->%d [%d vs %d]:", p.start + 1, p.end + 1, p.evensum, p.oddsum); for (int id : p.edges) printf(" %d", id + 1); puts(""); }
}
void reconstruct() {
	ans.clear();
	for (const Path& p : paths) if (p.alive) { p.normalize(); bool take = true; for (int id : p.edges) { if (take) ans.PB(id); take = !take; } }
	for (const Path& p : cycles) if (p.alive) { p.normalize(); bool take = true; for (int id : p.edges) { if (take) ans.PB(id); take = !take; } }
}

void run() {
	int minit;
	scanf("%d%d%d", &na, &nb, &minit);
	init();
	REP(i, minit) {
		int a, b; scanf("%d%d", &a, &b); --a, --b;
		addedge(a, b); 
	}
	int nq;
	scanf("%d", &nq);
	REP(i, nq) {
		int kind; scanf("%d", &kind);
		if (kind == 1) {
			int a, b; scanf("%d%d", &a, &b); --a, --b;
			addedge(a, b);
			printf("%d\n", anshash); fflush(stdout);
		}
		if (kind == 2) {
			reconstruct();
			printf("%d", SZ(ans)); REPSZ(j, ans) printf(" %d", ans[j] + 1); puts(""); fflush(stdout);
		}
	}
}


int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}