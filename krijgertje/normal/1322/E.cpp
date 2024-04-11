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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 500000;
const int MAXS = 4 * MAXN;
struct Block { int sval, len; bool alternating; Block() {} Block(int sval, int len, bool alternating) :sval(sval), len(len), alternating(alternating) {} };

int n;
int a[MAXN];
int tans;
int ans[MAXN];

int v[MAXN], nv;
vector<int> pos[MAXN];

map<int, Block> blocks;

vector<Block> normalize(vector<Block> seq, bool hasfst, bool haslst) {
	vector<Block> ret;
	REPSZ(i, seq) {
		Block cur = seq[i];
		if (cur.len == 0) continue;
		if (SZ(ret) == 0) {
			if (hasfst) {
				if (cur.alternating) {
					ret.PB(Block(cur.sval, 1, false));
					cur.sval = 1 - cur.sval, --cur.len;
					if (cur.len == 0) continue;
					ret.PB(cur);
				} else {
					ret.PB(cur);
				}
			} else {
				ret.PB(cur);
			}
		} else {
			Block prv = ret.back(); ret.pop_back();
			if (!prv.alternating) {
				if (!cur.alternating) {
					if (cur.sval == prv.sval) {
						prv.len += cur.len;
						ret.PB(prv);
					} else {
						if (cur.len == 1) cur.alternating = true;
						ret.PB(prv);
						ret.PB(cur);
					}
				} else {
					if (cur.sval == prv.sval) {
						++prv.len, --cur.len, cur.sval = 1 - cur.sval;
						ret.PB(prv);
						if (cur.len >= 1) ret.PB(cur);
					} else {
						ret.PB(prv);
						ret.PB(cur);
					}
				}
			} else {
				int prvtval = prv.len % 2 == 0 ? 1 - prv.sval : prv.sval;
				if (!cur.alternating) {
					if (cur.sval == prvtval) {
						--prv.len, ++cur.len;
						if (prv.len >= 1) ret.PB(prv);
						ret.PB(cur);
					} else {
						if (cur.len == 1) {
							++prv.len;
							ret.PB(prv);
						} else {
							ret.PB(prv);
							ret.PB(cur);
						}
					}
				} else {
					if (cur.sval == prvtval) {
						--prv.len, --cur.len; cur.sval = 1 - cur.sval;
						if (prv.len >= 1) ret.PB(prv);
						ret.PB(Block(prvtval, 2, false));
						if (cur.len >= 1) ret.PB(cur);
					} else {
						prv.len += cur.len;
						ret.PB(prv);
					}
				}
			}
		}
	}
	if (SZ(ret) >= 1) {
		Block prv = ret.back(); ret.pop_back();
		int prvtval = prv.len % 2 == 0 ? 1 - prv.sval : prv.sval;
		if (haslst) {
			if (prv.alternating) {
				--prv.len;
				if (prv.len >= 1) ret.PB(prv);
				ret.PB(Block(prvtval, 1, false));
			} else {
				ret.PB(prv);
			}
		} else {
			ret.PB(prv);
		}
	}
	//printf("normalize from:"); REPSZ(i, seq) printf(" [%d,%s]", seq[i].len, seq[i].alternating ? seq[i].sval == 0 ? "01" : "10" : seq[i].sval == 0 ? "0" : "1"); puts("");
	//printf("normalize to  :"); REPSZ(i, ret) printf(" [%d,%s]", ret[i].len, ret[i].alternating ? ret[i].sval == 0 ? "01" : "10" : ret[i].sval == 0 ? "0" : "1"); puts("");
	return ret;
}

int sval[MAXS];
void sapply(int x, int val) { sval[x] = max(sval[x], val); }
void sinit(int x, int l, int r) {
	sval[x] = INT_MIN;
	if(l != r) {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
	}
}
void supd(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		sapply(x, VAL);
	} else {
		int m = l + (r - l) / 2;
		if (L <= m) supd(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) supd(2 * x + 2, m + 1, r, L, R, VAL);
	}
}
int sget(int x, int l, int r, int IDX) {
	int ret = sval[x];
	if (l != r) {
		int m = l + (r - l) / 2;
		if (IDX <= m) ret = max(ret, sget(2 * x + 1, l, m, IDX)); else ret = max(ret, sget(2 * x + 2, m + 1, r, IDX));
	}
	return ret;
}

void updateans(int idx, Block block, int val) {
	if (block.alternating) tans = max(tans, (block.len + 1) / 2);
	if (!block.alternating) {
		if (block.sval == 1) supd(0, 0, n - 1, idx, idx + block.len - 1, val);
	} else if (block.len % 2 == 1) {
		if (block.sval == 0) supd(0, 0, n - 1, idx, idx + block.len - 1, val);
	} else {
		if (block.sval == 0) supd(0, 0, n - 1, idx, idx + block.len / 2 - 1, val);
		if (block.sval == 1) supd(0, 0, n - 1, idx + block.len / 2, idx + block.len - 1, val);
	}
}

void solve() {
	nv = 0; REP(i, n) v[nv++] = a[i]; sort(v, v + nv); nv = unique(v, v + nv) - v; REP(i, n) a[i] = lower_bound(v, v + nv, a[i]) - v;
	REP(i, nv) pos[i].clear(); REP(i, n) pos[a[i]].PB(i);

	blocks.clear();
	blocks[0] = Block(0, n, false);
	tans = 0; sinit(0, 0, n - 1);
	for (int x = nv - 1; x >= 0; --x) {
		set<int> changed;
		REPSZ(i, pos[x]) {
			int at = pos[x][i];
			auto it = blocks.upper_bound(at); if (it != blocks.end()) assert(it != blocks.begin()); it = prev(it);
			Block cur = it->second; int curidx = it->first; assert(curidx <= at && at < curidx + cur.len);
			Block prv; bool haveprv;
			Block nxt; bool havenxt;
			if (it == blocks.begin()) haveprv = false; else { haveprv = true; prv = prev(it)->second; blocks.erase(prev(it)); }
			if (next(it) == blocks.end()) havenxt = false; else { havenxt = true; nxt = next(it)->second; blocks.erase(next(it)); }
			blocks.erase(it);
			vector<Block> seq;
			if (haveprv) seq.PB(prv);
			int offset = at - curidx;
			if (!cur.alternating) {
				assert(cur.sval == 0);
				seq.PB(Block(0, offset, false));
				seq.PB(Block(1, 1, false));
				seq.PB(Block(0, cur.len - offset - 1, false));
			} else {
				assert((offset % 2 == 0) == (cur.sval == 0));
				seq.PB(Block(cur.sval, offset, true));
				seq.PB(Block(1, 1, false));
				seq.PB(Block(1, cur.len - offset - 1, true));
			}
			if (havenxt) seq.PB(nxt);
			int seqstart = curidx - (haveprv ? prv.len : 0);
			int seqend = curidx + cur.len + (havenxt ? nxt.len : 0);
			seq = normalize(seq, seqstart == 0, seqend == n);
			int atidx = seqstart;
			REPSZ(j, seq) { 
				changed.insert(atidx);
				blocks[atidx] = seq[j]; 
				atidx += seq[j].len; 
			}
			//printf("blocks after %d:", at); for (auto it = blocks.begin(); it != blocks.end(); ++it) printf(" %d:[len=%d,sval=%d,%s]", it->first, it->second.len, it->second.sval, it->second.alternating ? "ALT" : "CONST"); puts("");
		}
		for (auto it = changed.begin(); it != changed.end(); ++it) {
			int idx = *it;
			auto blocksit = blocks.find(idx);
			if (blocksit != blocks.end()) updateans(idx, blocksit->second, v[x]);
		}
	}
	REP(i, n) ans[i] = sget(0, 0, n - 1, i);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", tans);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());

void stress() {
	REP(rep, 1000) {
		n = rnd() % 100 + 2;
		REP(i, n) a[i] = rnd() % 10 + 1;
		printf("%d\n", n);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}