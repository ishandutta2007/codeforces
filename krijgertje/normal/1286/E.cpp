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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

struct KMP {
	int n, at;
	string s;
	vector<int> nxt; // nxt[i] = longest proper prefix of s[0..i) that is also a suffix
	vector<int> nxtdiff; // nxtdiff[i] = longest proper prefix of s[0..i) that is is also a suffix and not followed by s[i]


	void init(int _n) { n = _n, at = 0, s = string(n, '?'), nxt = nxtdiff = vector<int>(n + 1, 0); }
	void add(char c) {
		s[at++] = c;
		int x = nxt[at - 1]; while (x != 0 && s[x] != c) x = nxt[x]; if (at >= 2 && s[x] == c) ++x; nxt[at] = x; 
		nxtdiff[at - 1] = s[nxt[at - 1]] != c ? nxt[at - 1] : nxtdiff[nxt[at - 1]];
	}
};

struct RMQ {
	int n;
	vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(4 * n, 0); }
	void _set(int x, int l, int r, int IDX, int VAL) {
		if (l == r) {
			val[x] = VAL;
		} else {
			int m = l + (r - l) / 2;
			if (IDX <= m) _set(2 * x + 1, l, m, IDX, VAL); else _set(2 * x + 2, m + 1, r, IDX, VAL);
			val[x] = min(val[2 * x + 1], val[2 * x + 2]);
		}
	}
	void set(int idx, int v) { _set(0, 0, n - 1, idx, v); }
	int _get(int x, int l, int r, int L, int R) {
		if (L <= l&&r <= R) {
			return val[x];
		} else {
			int m = l + (r - l) / 2, ret = INT_MAX;
			if (L <= m) ret = min(ret, _get(2 * x + 1, l, m, L, R));
			if (m + 1 <= R) ret = min(ret, _get(2 * x + 2, m + 1, r, L, R));
			return ret;
		}
	}
	int get(int l, int r) { return _get(0, 0, n - 1, l, r); }
};

const int BASE = 1000000000;
const int BASEDIGITS = 9;
struct BigInt {
	vector<int> val;
	BigInt() {}
};
void print(const BigInt &a) {
	if (SZ(a.val) == 0) { printf("0"); return; }
	for (int i = SZ(a.val) - 1; i >= 0; --i) { if (i == SZ(a.val) - 1) printf("%d", a.val[i]); else printf("%0*d", BASEDIGITS, a.val[i]); }
}
BigInt operator+(const BigInt &a, ull b) {
	BigInt c = a;
	for (int i = 0; b > 0; ++i) {
		if (i >= SZ(c.val)) c.val.PB(0);
		b += c.val[i];
		c.val[i] = b%BASE; b /= BASE;
	}
	return c;
}
BigInt operator+(const BigInt &a, const BigInt &b) {
	BigInt c; int carry = 0;
	for (int i = 0; i < SZ(a.val) || i < SZ(b.val) || carry>0; ++i) {
		if (i < SZ(a.val)) carry += a.val[i]; if (i < SZ(b.val)) carry += b.val[i];
		c.val.PB(carry%BASE); carry /= BASE;
	}
	return c;
}
BigInt operator-(const BigInt &a, ull b) {
	BigInt c = a;
	for (int i = 0; b > 0; ++i) {
		assert(i < SZ(c.val));
		int cur = b%BASE; b /= BASE; if (cur <= c.val[i]) c.val[i] -= cur; else c.val[i] += BASE - cur, ++b;
	}
	while (SZ(c.val) > 0 && c.val.back() == 0) c.val.pop_back();
	return c;
}
int operator%(const BigInt &a, int b) {
	int ret = 0; for (int i = SZ(a.val) - 1; i >= 0; --i) ret = ((ull)ret*BASE + a.val[i]) % b; return ret;
}
int operator&(const BigInt &a, int b) {
	return (a % (1 << 30))&b;
}

struct RelaxableSet {
	BigInt sum;
	map<int, int> cnt;
	void init() { sum = BigInt(); cnt = map<int, int>(); }
	void relax(int lim) { /*printf("reduce %d\n", lim);*/ int rem = 0; while (SZ(cnt) > 0) { auto it = prev(cnt.end()); if (it->first <= lim) break; sum = sum - (ull)it->first*it->second, rem += it->second, cnt.erase(it); } if (rem > 0) cnt[lim] += rem, sum = sum + (ull)lim*rem; }
	void remove(int val) { /*printf("remove %d\n", val);*/ auto it = cnt.find(val); assert(it != cnt.end()); if (it->second == 1) cnt.erase(it); else --it->second; sum = sum - val; }
	void add(int val) { /*printf("add %d\n", val);*/ ++cnt[val]; sum = sum + val; }
	void print() { for (auto it = cnt.begin(); it != cnt.end(); ++it) printf(" %d=%d", it->first, it->second); puts(""); }
};

const int MAXN = 600000;
const int MASK = (1 << 30) - 1;

int n;
char c[MAXN]; int w[MAXN]; BigInt ans[MAXN];

KMP kmp;
RMQ rmq;
RelaxableSet have;

void solve() {
	kmp.init(n);
	rmq.init(n);
	have.init();
	BigInt prv;
	REP(i, n) {
		char cc = (prv + (ull)(c[i] - 'a')) % 26 + 'a';
		int ww = w[i] ^ (prv&MASK);
		//printf("%c %d\n", cc, ww);
		kmp.add(cc);
		int len = i;
		while (len >= 1) {
			if (kmp.s[len] != cc) {
				int val = rmq.get(i - len, i - 1);
				//printf("%d..%d=%d\n", i - len, i - 1, val);
				have.remove(val);
				len = kmp.nxt[len];
			} else {
				len = kmp.nxtdiff[len];
			}
		}
		rmq.set(i, ww);
		have.relax(ww);
		if (cc == kmp.s[0]) have.add(ww);
		//have.print();
		//printf("have.sum="); print(have.sum); puts("");
		ans[i] = prv + have.sum;
		prv = ans[i];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf(" %c%d", &c[i], &w[i]);
	solve();
	REP(i, n) print(ans[i]), puts("");
}

int main() {
	run();
	return 0;
}