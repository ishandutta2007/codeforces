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

const int MAXN = 58;
const int MAXQ = 5000;

int n;
int bto[MAXN - 1], rto[MAXN - 1];
int nq;
int qat[MAXQ]; char qlast[MAXQ][MAXN - 1 + 1]; ll qans[MAXQ];

// x[i] = #times that from i the edge to bto[i] was followed
int dr[MAXN - 1]; // x[i]+dr[i] = #times that from i the edge to rto[i] was followed


void mlt64(ull x, ull y, ull& hi, ull& lo) {
	ull xhi = x >> 32, xlo = x & ((1ULL << 32) - 1), yhi = y >> 32, ylo = y & ((1ULL << 32) - 1);
	ull zlo = xlo * ylo, tmp = xhi * ylo + (zlo >> 32), zmi = tmp & ((1ULL << 32) - 1), zhi = tmp >> 32;
	zmi += xlo * yhi, zhi += xhi * yhi;
	lo = (zlo & (1ULL << 32) - 1) + ((zmi & (1ULL << 32) - 1) << 32), hi = zhi + (zmi >> 32);
}

template <int k> struct MersenneMod64bit {
	constexpr static ull mod() { return (1ULL << k) - 1; }
	ull val;
	MersenneMod64bit() { val = 0; }
	MersenneMod64bit(ull _val) { val = (_val & mod()) + (_val >> k); if (val >= mod()) val -= mod(); }
	const ull operator()() const { return val; }
	MersenneMod64bit& operator+=(const MersenneMod64bit& other) { val += other.val; if (val >= mod()) val -= mod(); return *this; }
	MersenneMod64bit& operator-=(const MersenneMod64bit& other) { if (val >= other.val) val -= other.val; else val += mod() - other.val; return *this; }
	MersenneMod64bit& operator*=(const MersenneMod64bit& other) { ull hi, lo; mlt64(val, other.val, hi, lo); val = (lo & mod()) + (lo >> k) + (hi << (64 - k)); if (val >= mod()) val -= mod(); return *this; }
	MersenneMod64bit& operator/=(const MersenneMod64bit& other) { return *this *= other.inverse(); }
	MersenneMod64bit operator*(const MersenneMod64bit& other) const { return MersenneMod64bit(*this) *= other; }
	bool operator==(const MersenneMod64bit& other) { return val == other.val; }
	bool operator!=(const MersenneMod64bit& other) { return val != other.val; }
	MersenneMod64bit pw(ull n) const { MersenneMod64bit ret = 1, x = *this; while (true) { if (n & 1) ret *= x; if ((n >>= 1) == 0) return ret; x *= x; } }
	MersenneMod64bit inverse() const { return pw(mod() - 2); }
};
template <int k> ostream& operator<<(ostream& stream, const MersenneMod64bit<k>& number) { return stream << number(); }

template <typename T> struct Matrix {
	int n, m;
	vector<vector<T>> A;
	Matrix(int n) :n(n), m(n) { A = vector<vector<T>>(n, vector<T>(m, 0)); }
	Matrix(int n, int m) :n(n), m(m) { A = vector<vector<T>>(n, vector<T>(m, 0)); }
	vector<T>& operator [](int i) { return A[i]; }
	void gaussjord() {
		int R = n, C = m, r = 0, c = 0;
		while (r < R && c < C) {
			{ int rr = r; while (rr < R && A[rr][c] == 0) ++r; if (rr >= R) { ++c; continue; } if (rr != r) FOR(cc, c, C) swap(A[r][cc], A[rr][cc]); }
			if (A[r][c] != 1) { T x = 1; x /= A[r][c]; FOR(cc, c + 1, C) A[r][cc] *= x; A[r][c] = 1; }
			REP(rr, R) if (rr != r && A[rr][c] != 0) { FOR(cc, c + 1, C) A[rr][cc] -= A[rr][c] * A[r][cc]; A[rr][c] = 0; }
			++r, ++c;
		}
	}
	Matrix inverse() {
		assert(n == m);
		Matrix B(n, 2 * n);
		REP(i, n) REP(j, n) B[i][j] = A[i][j], B[i][n + j] = i == j ? 1 : 0;
		B.gaussjord();
		REP(i, n) assert(B[i][i] == 1);
		Matrix ret(n);
		REP(i, n) REP(j, n) ret[i][j] = B[i][n + j];
		return ret;
	}
	Matrix operator*(const Matrix& other) const { assert(m == other.n); Matrix ret(n, other.m); REP(i, n) REP(j, other.m) REP(k, m) ret[i][j] += A[i][k] * other.A[k][j]; return ret; }
	vector<T> operator*(const vector<T>& vec) const { assert(m == SZ(vec)); vector<T> ret(n, 0); REP(i, n) REP(k, m) ret[i] += A[i][k] * vec[k]; return ret; }
	void print() { REP(i, n) { REP(j, m) { if (j != 0) cout << " "; cout << A[i][j]; } cout << "\n"; } }
};

using M61 = MersenneMod64bit<61>;
using Mat = Matrix<M61>;
using Vec = vector<M61>;

bool dec(ull& a, ull b) { if (a < b) return false; a -= b; return true; }
bool solveslinearequation(int q, const Vec& x) {
	REP(i, n - 1) dr[i] = qlast[q][i] == 'B' ? 0 : 1;
	bool ok = true;
	vector<ull> bal(n, 0);
	REP(i, n - 1) bal[i] += 2 * x[i]() + dr[i];
	++bal[qat[q]];
	REP(i, n - 1) {
		ok = ok && dec(bal[bto[i]], x[i]());
		ok = ok && dec(bal[rto[i]], x[i]() + dr[i]);
	}
	ok = ok && dec(bal[0], 1);
	REP(i, n) ok = ok && bal[i] == 0;
	return ok;
}
bool visitedstatesgotodestination(int q, const Vec& x) {
	REP(i, n - 1) dr[i] = qlast[q][i] == 'B' ? 0 : 1;
	vector<bool> visited(n - 1); REP(i, n - 1) visited[i] = x[i]() > 0 || dr[i] > 0;
	vector<vector<int>> radj(n);
	REP(i, n) if (qlast[q][i] == 'B') radj[bto[i]].PB(i); else radj[rto[i]].PB(i);
	queue<int> queue; vector<bool> todest(n, false);
	todest[qat[q]] = true, queue.push(qat[q]);
	while (!queue.empty()) { int at = queue.front(); queue.pop(); REPSZ(i, radj[at]) { int to = radj[at][i]; if (!todest[to]) todest[to] = true, queue.push(to); } }
	REP(i, n) if (visited[i] && !todest[i]) return false;
	return true;
}

void solve() {
	Mat A(n - 1);
	REP(i, n - 1) {
		A[i][i] -= 2;
		if (bto[i] != n - 1) A[bto[i]][i] += 1;
		if (rto[i] != n - 1) A[rto[i]][i] += 1;
	}
	Mat Ainv = A.inverse();
	//printf("A:\n"); A.print();
	//printf("Ainv:\n"); Ainv.print();
	//Mat<M61> prod1 = A * Ainv; printf("prod1:\n"); prod1.print();
	//Mat<M61> prod2 = Ainv * A; printf("prod2:\n"); prod2.print();

	REP(q, nq) {
		REP(i, n - 1) dr[i] = qlast[q][i] == 'B' ? 0 : 1;
		Vec y(n - 1);
		y[0] -= 1;
		y[qat[q]] += 1;
		REP(i, n - 1) {
			y[i] += dr[i];
			if (rto[i] != n - 1) y[rto[i]] -= dr[i];
		}
		Vec x = Ainv * y;
		bool ok = solveslinearequation(q, x) && visitedstatesgotodestination(q, x);
		//printf("q%d:", q); REPSZ(i, x) cout << " " << x[i]; printf(" -> %s\n", ok ? "ok" : "err");
		if (!ok) qans[q] = -1; else { qans[q] = 0; REP(i, n - 1) qans[q] += 2 * x[i]() + dr[i]; }
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) scanf("%d%d", &bto[i], &rto[i]), --bto[i], --rto[i];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%s", &qat[i], qlast[i]), --qat[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}