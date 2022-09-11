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

const int MAXN = 500000;
const int MAXQ = 500000;
struct Block { int lo, hi, cnt, nunknown; bool any; };
struct Q { int idx, val, id; };

int n, nq;
int a[MAXN];
int qidx[MAXQ], qval[MAXQ], qans[MAXQ];

void fixunused(vector<int> &cur, vector<int> &blockid, vector<Block> &block, vector<Q> &q) {
	vector<int> nchange(SZ(cur), 0); REPSZ(i, q) nchange[q[i].idx]++;
	REPSZ(i, cur) if (nchange[i] == 0) {
		int c = blockid[i]; --block[c].nunknown;
		if (!block[c].any) { block[c].any = true; block[c].lo = block[c].hi = cur[i]; } else { block[c].lo = min(block[c].lo, cur[i]); block[c].hi = max(block[c].hi, cur[i]); }
	}
	vector<int> mp(SZ(cur), -1); int nmp = 0; REPSZ(i, cur) if (nchange[i] != 0) mp[i] = nmp++;
	vector<int> ncur(nmp), nblockid(nmp); REPSZ(i, cur) if (mp[i] != -1) ncur[mp[i]] = cur[i], nblockid[mp[i]] = blockid[i];
	cur = ncur, blockid = nblockid;
	REPSZ(i, q) q[i].idx = mp[q[i].idx];
}
void makedisjoint(vector<int> &cur, vector<int> &blockid, vector<Block> &block, vector<Q> &q) {
	vector<Block> nblock;
	vector<int> nprefmn; nprefmn.PB(INT_MAX);
	vector<int> nfst;
	REPSZ(i, block) {
		Block cur = block[i];
		int fst = i;
		while (cur.any && cur.hi > nprefmn.back()) {
			Block prv = nblock.back(); nblock.pop_back();
			fst = nfst.back(); nfst.pop_back();
			nprefmn.pop_back();
			if (prv.any) { cur.lo = min(cur.lo, prv.lo); cur.hi = max(cur.hi, prv.hi); }
			cur.nunknown += prv.nunknown;
			cur.cnt = 1;
		}
		int prefmn = nprefmn.back(); if (cur.any) prefmn = min(prefmn, cur.lo);
		nblock.PB(cur); nprefmn.PB(prefmn); nfst.PB(fst);
	}
	nfst.PB(SZ(block));
	vector<int> mp(SZ(block)); FORSZ(i, 1, nfst) FOR(j, nfst[i - 1], nfst[i]) mp[j] = i - 1;
	vector<int> nblockid(SZ(blockid)); REPSZ(i, cur) nblockid[i] = mp[blockid[i]];
	blockid = nblockid, block = nblock;
}
void reducevals(vector<int> &cur, vector<int> &blockid, vector<Block> &block, vector<Q> &q) {
	int mxval = -1; REPSZ(i, cur) mxval = max(mxval, cur[i]); REPSZ(i, block) if (block[i].any) mxval = max(mxval, block[i].hi); REPSZ(i, q) mxval = max(mxval, q[i].val);
	vector<int> valcnt(mxval + 1, 0); REPSZ(i, cur) ++valcnt[cur[i]]; REPSZ(i, block) if (block[i].any) ++valcnt[block[i].lo], ++valcnt[block[i].hi]; REPSZ(i, q) ++valcnt[q[i].val];
	int nval = 0; vector<int> mp(mxval + 1, -1); REPSZ(i, valcnt) if (valcnt[i] > 0) mp[i] = nval++;
	REPSZ(i, cur) cur[i] = mp[cur[i]]; REPSZ(i, block) if (block[i].any) block[i].lo = mp[block[i].lo], block[i].hi = mp[block[i].hi]; REPSZ(i, q) q[i].val = mp[q[i].val];
}
void compressfinished(vector<int> &cur, vector<int> &blockid, vector<Block> &block, vector<Q> &q) {
	int mxval = -1; REPSZ(i, cur) mxval = max(mxval, cur[i]); REPSZ(i, block) if (block[i].any) mxval = max(mxval, block[i].hi); REPSZ(i, q) mxval = max(mxval, q[i].val);
	vector<int> valcnt(mxval + 1, 0); REPSZ(i, cur) ++valcnt[cur[i]]; REPSZ(i, q) ++valcnt[q[i].val];
	vector<int> valsum(SZ(valcnt) + 1, 0); REPSZ(i, valcnt) valsum[i + 1] = valsum[i] + valcnt[i];
	vector<Block> nblock;
	vector<int> nfst;
	REPSZ(i, block) {
		Block cur = block[i];
		int fst = i;
		while (cur.any && cur.nunknown == 0 && SZ(nblock) > 0) {
			Block prv = nblock.back();
			if (!prv.any) break;
			assert(prv.lo >= cur.hi);
			if (prv.nunknown != 0) break;
			if (valsum[prv.hi + 1] != valsum[cur.lo]) break;
			nblock.pop_back();
			fst = nfst.back(); nfst.pop_back();
			cur.hi = prv.hi;
			cur.cnt += prv.cnt;
		}
		nblock.PB(cur); nfst.PB(fst);
	}
	nfst.PB(SZ(block));
	vector<int> mp(SZ(block)); FORSZ(i, 1, nfst) FOR(j, nfst[i - 1], nfst[i]) mp[j] = i - 1;
	vector<int> nblockid(SZ(blockid)); REPSZ(i, cur) nblockid[i] = mp[blockid[i]];
	blockid = nblockid, block = nblock;
}

void reduce(vector<int> &cur, vector<int> &blockid, vector<Block> &block, vector<Q> &q) {
	fixunused(cur, blockid, block, q);
	makedisjoint(cur, blockid, block, q);
	reducevals(cur, blockid, block, q);
	compressfinished(cur, blockid, block, q);
}

void rec(vector<int> cur, vector<int> blockid, vector<Block> block, vector<Q> q) {
	//printf("rec\n");
	if (SZ(q) == 1) {
		cur[q[0].idx] = q[0].val;
		vector<Q> empty;
		reduce(cur, blockid, block, empty);
		assert(SZ(block) == 1 && block[0].nunknown == 0);
		qans[q[0].id] = block[0].cnt;
	} else {
		reduce(cur, blockid, block, q);
		vector<Q> lq, rq; REPSZ(i, q) if (2 * i < SZ(q)) lq.PB(q[i]); else rq.PB(q[i]);
		rec(cur, blockid, block, lq);
		REPSZ(i, lq) cur[lq[i].idx] = lq[i].val;
		rec(cur, blockid, block, rq);
	}
}

void solve() {
	vector<int> cur(n); REP(i, n) cur[i] = a[i];
	vector<int> blockid(n); REP(i, n) blockid[i] = i;
	vector<Block> block(n); REP(i, n) block[i].any = false, block[i].nunknown = 1, block[i].cnt = 1;
	vector<Q> q(nq); REP(i, nq) q[i].idx = qidx[i], q[i].val = qval[i], q[i].id = i;
	rec(cur, blockid, block, q);
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}