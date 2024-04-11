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


const int MAXSONG = 100;
const int MAXFRIEND = 100;
const int MOD = 998244353;

int nsong, nfriend;
vector<int> like[MAXFRIEND];


const int PERM = 0;
const int ORDERED = 1;
const int LEAF = 2;
struct Node {
	int kind;
	vector<Node*> childs;
	vector<int> leafs;
};

Node* concat(vector<Node*> lst, int kind = PERM) {
	vector<Node*> nlst;
	for (Node* ch : lst) if (ch != NULL) nlst.PB(ch);
	lst = nlst;
	if (SZ(lst) == 0) return NULL;
	if (SZ(lst) == 1) return lst[0];
	auto ret = new Node();
	ret->kind = kind;
	for (Node* ch : lst) {
		ret->childs.PB(ch);
		for (int x : ch->leafs) ret->leafs.PB(x);
	}
	return ret;
}

void print(Node* at) {
	if (at->kind == LEAF) { printf("%d", at->leafs[0] + 1); return; }
	printf("%c", at->kind == PERM ? '(' : '[');
	REPSZ(i, at->childs) { if (i != 0) printf(","); print(at->childs[i]); }
	printf("%c", at->kind == PERM ? ')' : ']');
}

Node* process(Node* at, set<int> like, bool mustprefix) {
	//printf("\tprocessing %s: ", mustprefix ? "prefix" : "interval"); print(at); printf(" {"); for (int x : like) { if (x != *like.begin()) printf(","); printf("%d", x + 1); } printf("}\n");
	if (at->kind == LEAF) {
		assert(SZ(at->leafs) == 1 && SZ(like) == 1 && like.count(at->leafs[0]) == 1);
		return at;
	}

	vector<Node*> none;
	vector<Node*> all;
	vector<int> partial;
	vector<set<int>> to(SZ(at->childs));
	int fst = INT_MAX, lst = INT_MIN;
	REPSZ(i, at->childs) {
		for (int x : at->childs[i]->leafs) if (like.count(x)) to[i].insert(x);
		if (SZ(to[i]) != 0) fst = min(fst, i), lst = max(lst, i);
		if (SZ(to[i]) == 0) none.PB(at->childs[i]); else if (SZ(to[i]) == SZ(at->childs[i]->leafs)) all.PB(at->childs[i]); else partial.PB(i);
	}
	if (SZ(all) == SZ(at->childs)) return at;
	assert(SZ(all) + SZ(partial) >= 1);
	if (SZ(partial) >= 3) return NULL;
	if (mustprefix && SZ(partial) >= 2) return NULL;
	bool partialprefix = mustprefix || SZ(partial) >= 2 || SZ(all) >= 1;
	vector<Node*> partialnodes;
	for (int idx : partial) {
		Node* cur = process(at->childs[idx], to[idx], partialprefix);
		if (cur == NULL) return NULL;
		partialnodes.PB(cur);
	}
	Node* ret;
	if (at->kind == PERM) {
		Node* allnode = concat(all);
		if (mustprefix) {
			Node* nonenode = concat(none);
			vector<Node*> lst;
			lst.PB(allnode); if (SZ(partial) == 1) for (auto x : partialnodes[0]->childs) lst.PB(x); lst.PB(nonenode);
			ret = concat(lst, ORDERED);
		} else {
			if (SZ(partial) >= 2) reverse(partialnodes[0]->childs.begin(), partialnodes[0]->childs.end());
			vector<Node*> withlst;
			Node* with;
			if (partialprefix) {
				if (SZ(partial) >= 2) for (auto x : partialnodes[0]->childs) withlst.PB(x); withlst.PB(allnode); if (SZ(partial) >= 1) for (auto x : partialnodes[SZ(partial) >= 2 ? 1 : 0]->childs) withlst.PB(x);
				with = concat(withlst, ORDERED);
			} else {
				assert(SZ(partial) == 1 && SZ(all) == 0);
				with = partialnodes[0];
			}
			vector<Node*> lst; lst.PB(with); for (auto x : none) lst.PB(x);
			ret = concat(lst);
		}
	} else {
		//printf("\t\there (%d,%d) [%d..%d]\n", SZ(all), SZ(partial), fst, lst);
		assert(at->kind == ORDERED);
		if (SZ(all) + SZ(partial) != lst - fst + 1) return NULL;
		REPSZ(i, partial) if (partial[i] != fst && partial[i] != lst) return NULL;
		if (mustprefix) {
			assert(SZ(partial) <= 1);
			if (fst != 0 || SZ(partial) == 1 && SZ(all) >= 1 && partial[0] == 0) {
				fst = SZ(at->childs) - 1 - fst, lst = SZ(at->childs) - 1 - lst, swap(fst, lst);
				reverse(none.begin(), none.end());
				reverse(all.begin(), all.end());
				reverse(partial.begin(), partial.end());
				REPSZ(i, partial) partial[i] = SZ(at->childs) - 1 - partial[i];
				reverse(to.begin(), to.end());
				reverse(at->childs.begin(), at->childs.end());
			}
			if (fst != 0 || SZ(partial) == 1 && SZ(all) >= 1 && partial[0] == 0) return NULL;
		}
		if (SZ(partial) == 0) {
			ret = at;
		} else {
			REPSZ(i, partial) if (partial[i] != lst && partial[i] == fst) reverse(partialnodes[i]->childs.begin(), partialnodes[i]->childs.end());
			vector<Node*> lst;
			REPSZ(i, at->childs) {
				bool done = false;
				REPSZ(j, partial) if (!done && i == partial[j]) { done = true; if (!partialprefix) lst.PB(partialnodes[j]); else for (auto x : partialnodes[j]->childs) lst.PB(x); }
				if (!done) lst.PB(at->childs[i]);
			}
			ret = concat(lst, ORDERED);
		}
	}
	//printf("\t->"); print(ret); puts("");
	return ret;
}

int fac[MAXSONG + 1];

int calc(Node* at) {
	int ret = 1;
	for (Node* ch : at->childs) ret = (ll)ret * calc(ch) % MOD;
	if (at->kind == ORDERED) ret = (ll)ret * 2 % MOD;
	if (at->kind == PERM) ret = (ll)ret * fac[SZ(at->childs)] % MOD;
	return ret;
}

int solve() {
	fac[0] = 1; FORE(i, 1, nsong) fac[i] = (ll)fac[i - 1] * i % MOD;
	Node* root = new Node();
	root->kind = PERM;
	REP(i, nsong) {
		Node* leaf = new Node();
		leaf->kind = LEAF;
		leaf->leafs.PB(i);
		root->childs.PB(leaf);
		root->leafs.PB(i);
	}
	REP(i, nfriend) {
		//print(root); puts("");
		set<int> likeset(like[i].begin(), like[i].end());
		root = process(root, likeset, false);
		if (root == NULL) return 0;
	}
	//printf("final: "); print(root); puts("");
	return calc(root);
}

void run() {
	scanf("%d%d", &nsong, &nfriend);
	REP(i, nfriend) { int cnt; scanf("%d", &cnt); like[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &like[i][j]), --like[i][j]; }
	printf("%d\n", solve());
}

int solvestupid() {
	vector<int> p; REP(i, nsong) p.PB(i);
	int ret = 0;
	do {
		bool ok = true;
		REP(i, nfriend) {
			bool any = false;
			bool last = false;
			set<int> likeset(like[i].begin(), like[i].end());
			REP(j, nsong) {
				if (likeset.count(p[j])) {
					if (!any) any = true; else if (!last) ok = false;
					last = true;
				} else {
					last = false;
				}
			}
		}
		if (ok) ++ret;
	} while (next_permutation(p.begin(), p.end()));
	return ret;
}

void stress() {
	int mxsong = 8, mxfriend = 4;
	REP(rep, 100000) {
		nsong = rnd() % mxsong + 1;
		nfriend = rnd() % (mxfriend + 1);
		REP(i, nfriend) {
			like[i].clear();
			int cnt = rnd() % nsong + 1;
			ll mask = 0;
			REP(j, cnt) while (true) { int idx = rnd() % nsong; if (mask & (1LL << idx)) continue; mask |= 1LL << idx; like[i].PB(idx); break; }
		}
		int have = solve();
		int want = solvestupid();
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("have=%d want=%d\n", have, want);
		printf("%d %d\n", nsong, nfriend); REP(i, nfriend) { printf("%d", SZ(like[i])); for (int x : like[i]) printf(" %d", x + 1); puts(""); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}