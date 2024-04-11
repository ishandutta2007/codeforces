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

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) { return MP(a.first + b.first, a.second + b.second); }
void inc(pair<int, int>& a, pair<int, int> b) { a.first += b.first; a.second += b.second; }
void dec(pair<int, int>& a, pair<int, int> b) { a.first -= b.first; a.second -= b.second; }

unsigned int calcmxbit(unsigned int x) { x = x | (x >> 1); x = x | (x >> 2); x = x | (x >> 4); x = x | (x >> 8); x = x | (x >> 16); return x ^ (x >> 1); }
//unsigned long long calcmxbit(unsigned long long x) { x = x | (x >> 1); x = x | (x >> 2); x = x | (x >> 4); x = x | (x >> 8); x = x | (x >> 16); x = x | (x >> 32); return x ^ (x >> 1); }
template<class T,class U=unsigned int> struct IntegerMap {
	struct Node {
		int lft, rgt;
		U key; // if lft!=-1 or rgt!=-1, then this node represents the range [key-(key&-key)..key+(key&-key)-1]
		T val;
		Node(U key, T val) :lft(-1), rgt(-1), key(key), val(val) {}
	};
	vector<Node> nodes;
	queue<int> pool;

	void reset() {
		nodes.clear();
		pool = queue<int>();
	}
	int make(U key, T val) {
		if (pool.empty()) {
			nodes.PB(Node(key, val));
			return SZ(nodes) - 1;
		} else {
			int ret = pool.front(); pool.pop();
			nodes[ret] = Node(key, val);
			return ret;
		}
	}
	int merge(int a, int b) {
		if (a == -1) return b;
		if (b == -1) return a;
		U akey = nodes[a].key, bkey = nodes[b].key;
		U abit, alo, ahi; if (nodes[a].lft == -1 && nodes[a].rgt == -1) abit = 0, alo = akey, ahi = akey; else abit = akey & -akey, alo = akey - abit, ahi = akey + abit - 1;
		U bbit, blo, bhi; if (nodes[b].lft == -1 && nodes[b].rgt == -1) bbit = 0, blo = bkey, bhi = bkey; else bbit = bkey & -bkey, blo = bkey - bbit, bhi = bkey + bbit - 1;
		if (alo > blo || alo == blo && ahi < bhi) swap(a, b), swap(akey, bkey), swap(abit, bbit), swap(alo, blo), swap(ahi, bhi);
		if (ahi < blo) {
			U diffbit = calcmxbit(akey ^ bkey);
			U nkey = (akey & ~(diffbit - 1)) | diffbit;
			int ret = make(nkey, nodes[a].val + nodes[b].val);
			nodes[ret].lft = a, nodes[ret].rgt = b;
			return ret;
		} else if (alo == ahi) {
			assert(blo == alo && bhi == alo);
			nodes[a].val = nodes[a].val + nodes[b].val;
			pool.push(b);
			return a;
		} else if (alo == blo && ahi == bhi) {
			int nlft = merge(nodes[a].lft, nodes[b].lft); 
			int nrgt = merge(nodes[a].rgt, nodes[b].rgt);
			nodes[a].lft = nlft, nodes[a].rgt = nrgt, nodes[a].val = nodes[nlft].val + nodes[nrgt].val;
			pool.push(b);
			return a;
		} else {
			assert(bhi <= ahi);
			int nlft = (bkey & abit) == 0 ? merge(nodes[a].lft, b) : nodes[a].lft;
			int nrgt = (bkey & abit) != 0 ? merge(nodes[a].rgt, b) : nodes[a].rgt;
			nodes[a].lft = nlft, nodes[a].rgt = nrgt, nodes[a].val = nodes[nlft].val + nodes[nrgt].val;
			return a;
		}
	}
	pair<int, int> split(int a, U key) {
		if (a == -1) return MP(-1, -1);
		U akey = nodes[a].key;
		U abit, alo, ahi; if (nodes[a].lft == -1 && nodes[a].rgt == -1) abit = -1, alo = akey, ahi = akey; else abit = akey & -akey, alo = akey - abit, ahi = akey + abit - 1;
		if (key <= alo) return MP(-1, a);
		if (ahi < key) return MP(a, -1);
		if ((key & abit) == 0) {
			pair<int, int> sub = split(nodes[a].lft, key);
			pool.push(a);
			return MP(sub.first, merge(sub.second, nodes[a].rgt)); 
		} else {
			pair<int, int> sub = split(nodes[a].rgt, key);
			pool.push(a);
			return MP(merge(nodes[a].lft, sub.first), sub.second);
		}
	}
	void print(int a) {
		if (a == -1) return;
		if (nodes[a].lft == -1 && nodes[a].rgt == -1) printf(" %u", nodes[a].key); else print(nodes[a].lft), print(nodes[a].rgt);
	}
};


const int MAXN = 50000;
const int MAXDAY = 50000;

int n, nday;
int tregrow[MAXN];
int par[MAXN];
int visit[MAXDAY];
pair<int, int> ans[MAXDAY];

vector<int> ch[MAXN];
int dep[MAXN];
int prelst[MAXN], lpre[MAXN], rpre[MAXN], npre;
vector<int> who[MAXDAY];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	prelst[npre] = at, lpre[at] = npre, ++npre;
	for (int to : ch[at]) dfsinit(to);
	rpre[at] = npre - 1;
}


void solve() {
	int mnbig = max(1, (int)sqrt(1.0 * nday) / 2);
	int mxsmall = mnbig - 1;
	REP(i, nday) ans[i] = MP(0, 0);

	REP(i, n) ch[i].clear();
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	npre = 0; dfsinit(0);

	set<int> big;
	REP(i, n) if (tregrow[i] >= mnbig) big.insert(lpre[i]);
	vector<vector<int>> regrow(nday);
	REP(i, nday) {
		REPSZ(j, regrow[i]) { int at = regrow[i][j]; big.insert(lpre[at]); }
		int at = visit[i];
		int l = lpre[at], r = rpre[at];
		while (true) {
			auto it = big.lower_bound(l);
			if (it == big.end() || *it > r) break;
			int to = prelst[*it];
			//printf("%d: %d picks %d\n", i, at + 1, to + 1);
			big.erase(it);
			ans[i].first += dep[to];
			ans[i].second++;
			if (i + tregrow[to] < nday) regrow[i + tregrow[to]].PB(to);
		}
	}

	FORE(i, 1, nday) who[i].clear();
	REP(i, n) who[tregrow[i]].PB(i);
	FORE(v, 1, mxsmall) if(SZ(who[v])!=0) {
		IntegerMap<pair<int, int>> im;
		vector<int> avail(nday, -1);
		REPSZ(i, who[v]) { int at = who[v][i]; int id = im.make(lpre[at], MP(dep[at], 1)); avail[0] = im.merge(avail[0], id); }
		REP(i, nday) {
			int l = lpre[visit[i]], r = rpre[visit[i]];
			int a, b, c; tie(a, b) = im.split(avail[i], l); tie(b, c) = im.split(b, r + 1);
			if (b != -1) inc(ans[i], im.nodes[b].val);
			if (i + v < nday) avail[i + v] = b;
			if (i + 1 < nday) avail[i + 1] = im.merge(avail[i + 1], im.merge(a, c));
		}
	}
	REP(i, nday) ans[i].first -= dep[visit[i]] * ans[i].second;
}

void run() {
	scanf("%d%d", &n, &nday);
	REP(i, n) scanf("%d", &tregrow[i]);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	REP(i, nday) scanf("%d", &visit[i]), --visit[i];
	solve();
	REP(i, nday) printf("%d %d\n", ans[i].first, ans[i].second);
}

pair<int, int> ansstupid[MAXDAY];

pair<int, int> dfsstupid(int at, int t, vector<int>& avail) {
	pair<int, int> ret = MP(0, 0);
	if (avail[at] <= t) inc(ret, MP(0, 1)), avail[at] = t + tregrow[at];
	for (int to : ch[at]) {
		pair<int, int> sub = dfsstupid(to, t, avail);
		sub.first += sub.second;
		inc(ret, sub);
	}
	return ret;
}

void solvestupid() {
	REP(i, n) ch[i].clear();
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	vector<int> avail(n, 0);
	REP(i, nday) {
		ansstupid[i] = dfsstupid(visit[i], i, avail);
	}
}

void stress() {
	REP(rep, 10000) {
		n = 100, nday = 10000;
		int gtregrow = rnd() % min(nday, 10) + 1;
		REP(i, n) tregrow[i] = rnd() % 2 == 0 ? gtregrow : rnd() % min(nday, 10) + 1;
		par[0] = -1; FOR(i, 1, n) par[i] = rnd() % i;
		REP(i, nday) visit[i] = rnd() % n;
		solve();
		solvestupid();
		bool ok = true;
		REP(i, nday) if (ans[i] != ansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("%d %d\n", n, nday);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", tregrow[i]); } puts("");
		FOR(i, 1, n) { if (i != 1) printf(" "); printf("%d", par[i] + 1); } puts("");
		REP(i, nday) printf("%d\n", visit[i] + 1);
		printf("have:"); REP(i, nday) printf(" (%d,%d)", ans[i].first, ans[i].second); puts("");
		printf("want:"); REP(i, nday) printf(" (%d,%d)", ansstupid[i].first, ansstupid[i].second); puts("");
		break;
	}
}

int main() {
	//stress();
	run();
	return 0;
}