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

const int MAXN = 100000;
const int MAXQ = 100000;
struct B { vector<int> lst; };

int n, nq;
int pinit[MAXN];
int qkind[MAXQ], qx[MAXQ], qy[MAXQ], qk[MAXQ];
int qans[MAXQ];

int bsz, mxb;
queue<int> bpool;
vector<B> b;

int nxt[MAXN], prv[MAXN];
pair<int, int> pos[MAXN];

queue<int> todo;

void check(int start) {
	int at = nxt[start];
	while (pos[at] == MP(-1, -1)) {
		todo.push(at);
		pos[at] = MP(-2, -2);
		at = nxt[at];
	}
	at = start;
	while (pos[at] == MP(-1, -1)) {
		todo.push(at);
		pos[at] = MP(-2, -2);
		at = prv[at];
	}
}
void disassemble(int id) {
	for (int at : b[id].lst) pos[at] = MP(-1, -1);
	b[id].lst.clear();
	bpool.push(id);
}
void assemble() {
	while (!todo.empty()) {
		int start = todo.front();
		todo.pop();
		if (pos[start] != MP(-2, -2)) continue;
		deque<int> q;
		int at = nxt[start];
		while (pos[at] == MP(-2, -2)) {
			q.push_back(at);
			pos[at] = MP(-1, -1);
			at = nxt[at];
		}
		at = start;
		while (pos[at] == MP(-2, -2)) {
			q.push_front(at);
			pos[at] = MP(-1, -1);
			at = prv[at];
		}
		if (SZ(q) < bsz) {
			if (nxt[q.back()] == q.front()) continue;
			int to = nxt[q.back()];
			assert(pos[to].first >= 0 && pos[to].second == 0);
			int id = pos[to].first;
			for (int x : b[id].lst) q.push_back(x);
			disassemble(id);
			assert(SZ(q) >= bsz);
		}
		while (SZ(q) >0) {
			assert(!bpool.empty());
			int id = bpool.front(); bpool.pop();
			b[id].lst.clear();
			int cnt = SZ(q) >= 2 * bsz ? bsz : SZ(q);
			REP(i, cnt) { int at = q.front(); q.pop_front(); pos[at] = MP(id, i); b[id].lst.PB(at); }
		}
	}
}

void solve() {
	bsz = sqrt(1.0 * n);
	mxb = (n + bsz - 1) / bsz;
	b = vector<B>(mxb);
	bpool = queue<int>();
	REP(i, mxb) bpool.push(i);
	
	REP(i, n) nxt[i] = pinit[i], prv[nxt[i]] = i;
	REP(i, n) pos[i] = MP(-1, -1);
	todo = queue<int>();
	REP(i, n) check(i);
	assemble();

	REP(i, nq) {
		//printf("processing q%d\n", i);
		if (qkind[i] == 1) {
			int x = qx[i], y = qy[i];
			if (pos[x] != MP(-1, -1)) disassemble(pos[x].first);
			if (pos[y] != MP(-1, -1)) disassemble(pos[y].first);
			swap(nxt[x], nxt[y]);
			prv[nxt[x]] = x, prv[nxt[y]] = y;
			check(x);
			check(y);
			assemble();
		}
		if (qkind[i] == 2) {
			int x = qx[i], k = qk[i];
			if (pos[x] == MP(-1, -1)) {
				//printf("here\n");
				vector<int> lst;
				int at = x;
				while (true) { lst.PB(at); at = nxt[at]; if (at == lst[0]) break; }
				assert(SZ(lst) < bsz);
				qans[i] = lst[k % SZ(lst)];
			} else {
				//printf("or here\n");
				int at = x;
				while (k > 0) {
					assert(pos[at] != MP(-1, -1));
					int id = pos[at].first, offset = pos[at].second;
					//printf("at=%d k=%d -> id=%d offset=%d\n", at + 1, k, id, offset);
					if (offset == SZ(b[id].lst) - 1) {
						at = nxt[at], --k;
					} else {
						int cur = min(SZ(b[id].lst) - 1 - offset, k);
						at = b[id].lst[offset + cur], k -= cur;
					}
				}
				qans[i] = at;
			}
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &pinit[i]), --pinit[i];
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
		if (qkind[i] == 2) scanf("%d%d", &qx[i], &qk[i]), --qx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%d\n", qans[i] + 1);
}

int main() {
	run();
	return 0;
}