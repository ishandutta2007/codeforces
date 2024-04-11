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
#include <array>
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

const int MAXN = 1000;
const int MAXLEN = 100000;
typedef array<array<int, 4>, 4> Mat;
typedef array<int, 4> Vec;

int n, slen;
int a[MAXN][MAXN];
char s[MAXLEN + 1];
int ans[MAXN][MAXN];

Mat operator*(const Mat& A, const Mat& B) {
	Mat C; REP(i, 4) REP(j, 4) { int cur = 0; REP(k, 4) cur = (cur + (ll)A[i][k] * B[k][j]) % n; C[i][j] = cur; } return C;
}
Vec operator*(const Mat& A, const Vec& x) {
	Vec y; REP(i, 4) { int cur = 0; REP(k, 4) cur = (cur + (ll)A[i][k] * x[k]) % n; y[i] = cur; } return y;
}

void solve() {
	if (n == 1) { ans[0][0] = a[0][0]; return; }
	Mat R = { { {1,0,0,0},{0,1,0,1},{0,0,1,0},{0,0,0,1} } };
	Mat L = { { {1,0,0,0},{0,1,0,n - 1},{0,0,1,0},{0,0,0,1} } };
	Mat D = { { {1,0,0,1},{0,1,0,0},{0,0,1,0},{0,0,0,1} } };
	Mat U = { { {1,0,0,n - 1},{0,1,0,0},{0,0,1,0},{0,0,0,1} } };
	Mat I = { { {1,0,0,0},{0,0,1,0},{0,1,0,0},{0,0,0,1} } };
	Mat C = { { {0,0,1,0},{0,1,0,0},{1,0,0,0},{0,0,0,1} } };
	Mat id = { { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} } };

	Mat A = id;
	REP(i, slen) if (s[i] == 'R') A = R * A; else if (s[i] == 'L') A = L * A; else if (s[i] == 'D') A = D * A; else if (s[i] == 'U') A = U * A; else if (s[i] == 'I') A = I * A; else if (s[i] == 'C') A = C * A; else assert(false);
	//printf("A:\n"); REP(i, 4) { REP(j, 4) { if (j != 0) printf(" "); printf("%d", A[i][j]); } puts(""); } puts("");

	REP(i, n) REP(j, n) ans[i][j] = -1;
	REP(i, n) REP(j, n) {
		Vec x = { i,j,a[i][j],1 };
		Vec y = A * x;
		assert(ans[y[0]][y[1]] == -1);
		ans[y[0]][y[1]] = y[2];
	}
}

void run() {
	scanf("%d%d", &n, &slen);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]), --a[i][j];
	scanf("%s", s); assert(strlen(s) == slen);
	solve();
	REP(x, n) { REP(y, n) { if (y != 0) printf(" "); printf("%d", ans[x][y] + 1); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}