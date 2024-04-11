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


const int MAXN = 300;
const int MAXQ = 200000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }

const ll MODUNDOOVERFLOW = (1ULL << 63) / MOD * MOD;
vector<vector<int>> mmult(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	int nrow = SZ(a), nmid = SZ(a[0]), ncol = SZ(b[0]); vector<vector<int>> ret(nrow, vector<int>(ncol));
	REP(i, nrow) REP(j, ncol) { ll sum = 0; REP(k, nmid) { sum += (ll)a[i][k] * b[k][j]; if (sum < 0) sum -= MODUNDOOVERFLOW; } ret[i][j] = sum % MOD; } return ret;
}
vector<vector<int>> mexp(vector<vector<int>> x, ll n) {
	int dim = SZ(x); vector<vector<int>> ret(dim, vector<int>(dim, 0)); REP(i, dim) ret[i][i] = 1;
	while (true) { if (n & 1) ret = mmult(ret, x); if ((n >>= 1) == 0) return ret; x = mmult(x, x); }
}

int n;
int startval[MAXN]; // abs(sval[i])<=(i+1)
vector<int> copyfrom[MAXN]; // copyfrom[i][j]>i
int nq;
int qkind[MAXQ], qt[MAXQ], ql[MAXQ], qr[MAXQ], qidx[MAXQ], qdelta[MAXQ];
int qans[MAXQ];

vector<int> copiedby[MAXN];
vector<vector<int>> A;
int eigenval[MAXN]; vector<int> eigenvec[MAXN];
vector<int> c[MAXN];
vector<int> eigenvecsum[MAXN];
int inveigenpw[MAXN][MAXN];

int curval[MAXN];
int tpos[MAXN]; // tpos[i] = time when value of chef i becomes positive

vector<int> alltpos;
int tposidx[MAXN];
int w[MAXN][MAXN];

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void init(vector<int> v) { 
		n = SZ(v); val = vector<int>(n + 1, 0); 
		REP(k, n) { val[k + 1] = v[k]; int to = (k + 1) - ((k + 1) & -(k + 1)) - 1; if (to >= 0) inc(val[k + 1], MOD - v[to]); }
	}
	void mod(int idx, int by) { ++idx; while (idx <= n) { inc(val[idx], by); idx += idx & -idx; } }
	int get(int idx) { int ret = 0; ++idx; while (idx > 0) { inc(ret, val[idx]); idx -= idx & -idx; } return ret; }
};
BIT bit[MAXN];

void calctpos() {
	queue<int> q;
	REP(i, n) tpos[i] = INT_MAX;
	REP(i, n) if (curval[i] > 0) tpos[i] = 0, q.push(i);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : copiedby[at]) if (tpos[to] == INT_MAX) tpos[to] = tpos[at] + 1, q.push(to);
	}
	//printf("tpos:"); REP(i, n) if (tpos[i] == INT_MAX) printf(" oo"); else printf(" %d", tpos[i]); puts("");
	
	alltpos.clear();
	REP(i, n) if (tpos[i] != INT_MAX) alltpos.PB(tpos[i]);
	sort(alltpos.begin(), alltpos.end());
	alltpos.erase(unique(alltpos.begin(), alltpos.end()), alltpos.end());
	REP(i, n) tposidx[i] = tpos[i] == INT_MAX ? -1 : lower_bound(alltpos.begin(), alltpos.end(), tpos[i]) - alltpos.begin();

	REP(i, n) REP(j, n) w[i][j] = (ll)inveigenpw[j][tpos[i]] * c[i][j] % MOD;
	REP(j, n) {
		vector<int> want(SZ(alltpos), 0);
		REP(i, n) if (tposidx[i] != -1) want[tposidx[i]] = (want[tposidx[i]] + (ll)(curval[i] + MOD) * w[i][j]) % MOD;
		FORSZ(k, 1, want) inc(want[k], want[k - 1]);
		bit[j].init(want);
	}
}

vector<int> calceigenvec(vector<vector<int>>& A, int lambda) {
	// A*v=lambda*v -> (A-I*lambda)*v=0
	// this method only works when A is upper triangular and eigenvalue has multiplicity 1
	vector<int> ret(n, 0);
	int row = -1;
	for (int i = n - 1; i >= 0; --i) {
		int cur = A[i][i] - lambda; if (cur < 0) cur += MOD;
		if (cur == 0) {
			assert(row == -1);
			row = i;
			ret[row] = 1;
		} else {
			int sum = 0;
			REP(j, n) if (j != i && A[i][j] != 0) {
				assert(j > i);
				sum = (sum + (ll)A[i][j] * ret[j]) % MOD;
			}
			ret[i] = (ll)(MOD - sum) * calcinv(cur) % MOD;
		}
	}
	assert(row != -1);
	return ret;
}

vector<int> decompose(vector<int> v) {
	// decompose v into eigenvectors
	// this method only works if eigenvalues are distinct and eigenvectors form an upper triangular matrix with only ones on the diagonal
	vector<int> ret = v;
	for (int i = n - 1; i >= 0; --i) {
		REP(j, i) inc(ret[j], MOD - (ll)eigenvec[i][j] * ret[i] % MOD);
	}
	return ret;
}

struct FastPw {
	int step;
	vector<vector<int>> pw;

	void init(int x, int mxn, int _step) {
		step = _step;
		while (mxn > 0) {
			vector<int> v(min(mxn, step) + 1); v[0] = 1, v[1] = x; FORSZ(i, 2, v) v[i] = (ll)v[i - 1] * x % MOD; pw.PB(v);
			x = v.back(), mxn /= step;
		}
	}
	int calc(int n) {
		int ret = 1;
		for (int k = 0; n > 0; n /= step, ++k) ret = (ll)ret * pw[k][n % step] % MOD;
		return ret;
	}
};

FastPw eigenpw[MAXN];

int calcrange(int t,int l,int r) {
	int ret = 0;
	int idx = upper_bound(alltpos.begin(), alltpos.end(), t) - alltpos.begin() - 1;
	REP(j, n) {
		int cur = idx >= 0 ? bit[j].get(idx) : 0;
		/*REP(i, n) {
			int v = curval[i];
			if (v < 0) v += MOD;
			if (tpos[i] <= t) {
				//auto B = mexp(A, t - tpos[i]);
				//REP(j, n) ret[j] = (ret[j] + (ll)B[j][i] * v) % MOD;
				cur = (cur + (ll)v * w[i][j]) % MOD;
			}
		}*/
		//printf("%d^%d = %d vs %d\n", eigenval[j], t, pw(eigenval[j], t), eigenpw[j].calc(t));
		cur = (ll)cur * eigenpw[j].calc(t) % MOD;
		ret = (ret + (ll)(eigenvecsum[j][r + 1] + MOD - eigenvecsum[j][l]) * cur) % MOD;
	}
	FORE(i, l, r) if (tpos[i] > t) inc(ret, MOD + curval[i]);
	return ret;
}


void solve() {
	REP(i, n) copiedby[i].clear();
	REP(i, n) for (int j : copyfrom[i]) copiedby[j].PB(i);
		

	A = vector<vector<int>>(n, vector<int>(n, 0));
	REP(i, n) inc(A[i][i], i + 1);
	REP(i, n) for (int j : copyfrom[i]) inc(A[i][j], j + 1);
	//REP(i, n) { printf("A%d:", i); REP(j, n) printf(" %d", A[i][j]); puts(""); }

	REP(i, n) eigenval[i] = i + 1;
	REP(i, n) eigenvec[i] = calceigenvec(A, eigenval[i]);
	REP(i, n) { eigenvecsum[i] = eigenvec[i]; eigenvecsum[i].insert(eigenvecsum[i].begin(), 0); FORSZ(j, 1, eigenvecsum[i]) inc(eigenvecsum[i][j], eigenvecsum[i][j - 1]); }
	REP(i, n) { inveigenpw[i][0] = 1; if (1 < n) inveigenpw[i][1] = calcinv(eigenval[i]); FOR(j, 2, n) inveigenpw[i][j] = (ll)inveigenpw[i][j - 1] * inveigenpw[i][1] % MOD; }
	//REP(i, n) { printf("eigenval %d -> eigenvec:", eigenval[i]); REP(j, n) printf(" %d", eigenvec[i][j]); puts(""); }
	REP(i, n) eigenpw[i].init(eigenval[i], 1000, 1000);

	REP(i, n) { vector<int> e(n, 0); e[i] = 1; c[i] = decompose(e); }
	//REP(i, n) { printf("c%d:", i); REP(j, n) printf(" %d", c[i][j]); puts(""); }

	REP(i, n) curval[i] = startval[i];
	calctpos();

	REP(i, nq) {
		//printf("q%d:\n", i);
		if (qkind[i] == 1) {
			qans[i] = calcrange(qt[i], ql[i], qr[i]);
		}
		if (qkind[i] == 2) {
			bool waspos = curval[qidx[i]] > 0;
			curval[qidx[i]] += qdelta[i];
			bool ispos = curval[qidx[i]] > 0;
			if (ispos != waspos) {
				calctpos();
			} else if (tposidx[qidx[i]] != -1) {
				REP(j, n) bit[j].mod(tposidx[qidx[i]], (ll)qdelta[i] * w[qidx[i]][j] % MOD);
			}
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &startval[i]);
	REP(i, n) { int cnt; scanf("%d", &cnt); copyfrom[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &copyfrom[i][j]), --copyfrom[i][j]; }
	scanf("%d", &nq);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d%d", &qt[i], &ql[i], &qr[i]), --ql[i], --qr[i];
		if (qkind[i] == 2) scanf("%d%d", &qidx[i], &qdelta[i]), --qidx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 1) printf("%d\n", qans[i]);
}

void stress() {
	REP(rep, 10) {
		n = MAXN;
		REP(i, n) startval[i] = i == n - 1 ? 1 : -1;
		REP(i, n) { copyfrom[i].clear(); if (i + 1 < n) copyfrom[i].PB(i + 1); }
		nq = MAXQ;
		REP(i, nq) {
			if (nq - i - 1 < n - 1) {
				qkind[i] = 2;
				qidx[i] = nq - i - 1;
				qdelta[i] = 2;
				continue;
			}
			qkind[i] = rnd() % 2 + 1;
			if (qkind[i] == 1) {
				qt[i] = 1000;
				ql[i] = 1;
				qr[i] = n - 2;
			}
			if (qkind[i] == 2) {
				qidx[i] = rnd() % n;
				qdelta[i] = 0;
			}
		}
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}