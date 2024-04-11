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
const int MAXCENTRAL = MAXN;
const int MAXQ = 300000;
struct E { int to, len; E() {} E(int to, int len) :to(to), len(len) {} };
struct Conn { int a, b; ll cost; Conn() {} Conn(int a, int b, ll cost) :a(a), b(b), cost(cost) {} };
bool operator<(const Conn& p, const Conn& q) { return p.cost < q.cost; }
struct Q { int id, l, r, m; Q() {} Q(int id, int l, int r) :id(id), l(l), r(r) {} };
bool operator<(const Q& a, const Q& b) { return a.m < b.m; }

int n, m, ncentral, nq;
vector<E> adj[MAXN];
int qa[MAXQ], qb[MAXQ]; ll qans[MAXQ];

int ufpar[MAXCENTRAL], ufsz[MAXCENTRAL];
int uffind(int x) { if (ufpar[x] == x) return x; return ufpar[x] = uffind(ufpar[x]); }
void ufunite(int x, int y) { x = uffind(x), y = uffind(y); if (x == y) return; if (ufsz[x] < ufsz[y]) swap(x, y); ufpar[y] = x, ufsz[x] += ufsz[y]; }

priority_queue<pair<ll, pair<int, int>>> pq;
ll d[MAXN][2]; int src[MAXN][2];
int best[MAXCENTRAL];

void upd(int at, ll cost, int s) {
	if (cost < d[at][0]) {
		if (src[at][0] == -1 || uffind(src[at][0]) != uffind(s)) d[at][1] = d[at][0], src[at][1] = src[at][0];
		d[at][0] = cost, src[at][0] = s, pq.push(MP(-cost, MP(at, s)));
	} else if (uffind(s) != uffind(src[at][0]) && cost < d[at][1]) {
		d[at][1] = cost, src[at][1] = s, pq.push(MP(-cost, MP(at, s)));
	}
}

void solve() {
	REP(i, ncentral) ufpar[i] = i, ufsz[i] = 1;
	vector<Conn> all;
	while (true) {
		int cnt = 0; REP(i, ncentral) if (ufpar[i] == i) ++cnt; if (cnt <= 1) break;
		pq = priority_queue<pair<ll, pair<int, int>>>();
		REP(i, n) REP(j, 2) d[i][j] = LLONG_MAX, src[i][j] = -1;
		REP(i, ncentral) upd(i, 0, i);
		while (!pq.empty()) {
			ll cost = -pq.top().first; int at = pq.top().second.first, s = pq.top().second.second; pq.pop();
			int k = src[at][0] == s ? 0 : src[at][1] == s ? 1 : -1;
			if (k == -1 || cost != d[at][k]) continue;
			//printf("\tat=%d cost=%lld src=%d k=%d\n", at + 1, cost, s + 1, k);
			REPSZ(i, adj[at]) {
				int to = adj[at][i].to; ll ncost = cost + adj[at][i].len;
				upd(to, ncost, s);
			}
		}
		vector<Conn> cur;
		REP(i, ncentral) best[i] = -1;
		REP(i, ncentral) {
			assert(src[i][0] == i && d[i][0] == 0 && src[i][1] != -1 && uffind(src[i][1]) != uffind(i));
			int id = uffind(i);
			if (best[id] == -1 || d[i][1] < d[best[id]][1]) best[id] = i;
		}
		REP(id, ncentral) if(best[id]!=-1) {
			int i = best[id];
			//printf("closest to %d: %d with cost %lld\n", i + 1, src[i][1] + 1, d[i][1]);
			cur.PB(Conn(i, src[i][1], d[i][1]));
		}
		REPSZ(i, cur) ufunite(cur[i].a, cur[i].b);
		REPSZ(i, cur) all.PB(cur[i]);
	}
	sort(all.begin(), all.end());
	vector<Q> q; REP(i, nq) q.PB(Q(i, 0, SZ(all) + 1));
	while (SZ(q) > 0) {
		REPSZ(i, q) q[i].m = q[i].l + (q[i].r - q[i].l) / 2;
		sort(q.begin(), q.end());
		REP(i,ncentral) ufpar[i] = i, ufsz[i] = 1;
		int qat = 0;
		REPSZ(i, all) {
			ufunite(all[i].a, all[i].b);
			while (qat < SZ(q) && q[qat].m == i + 1) {
				int qid = q[qat].id;
				if (uffind(qa[qid]) == uffind(qb[qid])) {
					q[qat].r = q[qat].m;
				} else {
					q[qat].l = q[qat].m;
				}
				++qat;
			}
		}
		vector<Q> nq;
		REPSZ(i, q) {
			if (q[i].l + 1 < q[i].r) {
				nq.PB(q[i]);
			} else {
				assert(q[i].r <= SZ(all));
				qans[q[i].id] = all[q[i].r - 1].cost;
			}
		}
		q=nq;
	}
}

void run() {
	scanf("%d%d%d%d", &n, &m, &ncentral, &nq);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(E(b, c)); adj[b].PB(E(a, c)); }
	REP(i, nq) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ];

void solvestupid() {
	REP(i, nq) {
		int s = qa[i], t = qb[i];
		priority_queue<pair<ll, int>> pq;
		vector<ll> d(n, LLONG_MAX);
		d[s] = 0, pq.push(MP(-d[s], s));
		ll need = 0;
		while (!pq.empty()) {
			ll cd = -pq.top().first; int at = pq.top().second; pq.pop();
			if (cd != d[at]) continue;
			need = max(need, cd);
			if (at == t) break;
			REPSZ(j, adj[at]) {
				int to = adj[at][j].to, len = adj[at][j].len;
				ll nd = (at < ncentral ? 0 : cd) + len;
				//printf("i=%d at=%d to=%d cd=%lld nd=%lld\n", i, at, to, cd, nd);
				if (nd < d[to]) d[to] = nd, pq.push(MP(-d[to], to));
			}
		}
		assert(d[t] != LLONG_MAX);
		qansstupid[i] = need;
	}
}

void stress() {
	int mxn = 40, mxq = 10, mxc = 10;
	REP(rep, 1000000) {
		n = rand() % (mxn - 1) + 2, m = (n - 1) + rand() % n, ncentral = rand() % (n - 1) + 2, nq = rand() % mxq + 1;
		REP(i, n) adj[i].clear();
		vector<int> col(n); REP(i, n) col[i] = i;
		vector<int> ea, eb, ec;
		REP(i, n - 1) while (true) { int a = rand() % n, b = rand() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(i, n) if (col[i] == ocol) col[i] = col[a]; int c = rand() % mxc + 1; adj[a].PB(E(b, c)); adj[b].PB(E(a, c)); ea.PB(a), eb.PB(b), ec.PB(c); break; }
		REP(i, m - (n - 1)) while (true) { int a = rand() % n, b = rand() % n; if (a == b) continue; int c = rand() % mxc + 1; adj[a].PB(E(b, c)); adj[b].PB(E(a, c)); ea.PB(a), eb.PB(b), ec.PB(c); break; }
		REP(i, nq) while (true) { qa[i] = rand() % ncentral, qb[i] = rand() % ncentral; if (qa[i] == qb[i]) continue; break; }
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { if (rep % 1000 == 0) printf("."); continue; }
		printf("err rep=%d\n", rep);
		printf("%d %d %d %d\n", n, m, ncentral, nq);
		REP(i, m) printf("%d %d %d\n", ea[i] + 1, eb[i] + 1, ec[i]);
		REP(i, nq) printf("%d %d\n", qa[i] + 1, qb[i] + 1);
		REP(i, nq) printf("have=%lld want=%lld\n", qans[i], qansstupid[i]);
		break;
		
	}

}

int main() {
	run();
	//stress();
	return 0;
}