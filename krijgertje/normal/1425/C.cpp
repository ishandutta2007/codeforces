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

const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }


int qx, qy, xdim, ydim;
int inv[6 + 1];

int calcformula(int x, int y) {
	int ret = max(max((x + 1) / 2, (y + 1) / 2), (x + y + 2) / 3);
	if (ret % 2 != (x + y) % 2) ++ret;
	return ret;
}

int calc(int x, int y) {
	if (x == 1 && y == 0 || x == 0 && y == 1) return 3;
	if (x == 1 && y == 1) return xdim > 3 || ydim > 3 ? 4 : 0;
	if (x == 2 && y == 2) return 4;
	if (x == 3 && y == 0 && xdim == 4 || x == 0 && y == 3 && ydim == 4) return 5;
	return calcformula(x, y);
}

int divup(int num, int den) { if (den < 0) num = -num, den = -den; return num >= 0 ? (num + den - 1) / den : num / den; }
int divdn(int num, int den) { if (den < 0) num = -num, den = -den; return num >= 0 ? num / den : (num - den + 1) / den; }
int makesamepar(int a, int b) { if ((a & 1) != (b & 1)) ++a; return a; }
int cnt(int lo, int hi) { return hi - lo + 1; }
int sum(int lo, int hi) { return (ll)(lo + hi) * (hi - lo + 1) / 2 % MOD; }
int sumsq(int n) { return (ll)n * (n + 1) % MOD * (2 * n + 1) % MOD * inv[6] % MOD; }
int sumsq(int lo, int hi) { int ret = 0; inc(ret, sumsq(hi)); if (lo != 0) dec(ret, sumsq(lo - 1)); return ret; }

int calcsumstupid(int xlim, int ylim) {
	int ret = 0; REPE(x, xlim) REPE(y, ylim) inc(ret, calc(x, y)); return ret;
}

int calcsum(int xlim, int ylim) {
	// sum(x=0..xlim,y=0..ylim,makesamepar(max(ceil(x/2),ceil(y/2),ceil((x+y)/3)),x+y))
	// sum(dx=0..kx-1,dy=0..ky-1,x=0..(xlim-dx)/kx,y=0..(ylim-dy)/kx,makesamepar(max(ceil((x*kx+dx)/2),ceil((y*ky+dy)/2),ceil((x*kx+dx+y*ky+dy)/3)),x*kx+dx+y*ky+dy))
	// sum(dx=0..6kx-1,dy=0..6ky-1,x=0..(xlim-dx)/(6kx),y=0..(ylim-dy)/(6ky),makesamepar(max(3kx*x+ceil(dx/2),3ky*y+ceil(dy/2),2kx*x+2ky*y+ceil((dx+dy)/3)),dx+dy))

	// sum(dx=0..12kx-1,dy=0..6ky-1,x=0..(xlim-dx)/(12kx),y=0..(ylim-dy)/(6ky),makesamepar(max(6kx*x+ceil(dx/2),3ky*y+ceil(dy/2),4kx*x+2ky*y+ceil((dx+dy)/3)),dx+dy))
	// y >= (2kx*x+ceil(dx/2)-ceil((dx+dy)/3))/(2ky)
	// y <= (4kx*x+ceil((dx+dy)/3)-ceil(dy/2))/(ky)

	// sum(dx=0..11,dy=0..5,x=0..(xlim-dx)/12,y=0..(ylim-dy)/6,makesamepar(max(6*x+ceil(dx/2),3*y+ceil(dy/2),4*x+2*y+ceil((dx+dy)/3)),dx+dy))
	// y >= x+ceil((ceil(dx/2)-ceil((dx+dy)/3))/2)
	// y <= 4*x+ceil((dx+dy)/3)-ceil(dy/2)

	// part1=sum(dx=0..11,dy=0..5,x=0..(xlim-dx)/12,y=0..(ylim-dy)/6,y<x+ceil((ceil(dx/2)-ceil((dx+dy)/3))/2),6*x+makesamepar(ceil(dx/2),dx+dy))
	// part2=sum(dx=0..11,dy=0..5,x=0..(xlim-dx)/12,y=0..(ylim-dy)/6,x+ceil((ceil(dx/2)-ceil((dx+dy)/3))/2)<=y<=4*x+ceil((dx+dy)/3)-ceil(dy/2),4*x+2*y+makesamepar(ceil((dx+dy)/3),dx+dy))
	// part3=sum(dx=0..5,dy=0..11,x=0..(xlim-dx)/6,y=0..(ylim-dy)/12,y>x+floor((ceil((dx+dy)/3)-ceil(dy/2))/2),6*y+makesamepar(ceil(dy/2),dx+dy))

	int ret = 0;
	//vector<vector<int>> cnt(xlim + 1, vector<int>(ylim + 1, 0));
	// part1
	REP(dx, 12) if (dx <= xlim) REP(dy, 6) if (dy <= ylim) {
		// sum(x=0..(xlim-dx)/12,y=0..(ylim-dy)/6,y<x+ceil((ceil(dx/2)-ceil((dx+dy)/3))/2),6*x+makesamepar(ceil(dx/2),dx+dy)) = sum(x=0..A,y=0..min(B,x+D),6*x+E)
		int A = (xlim - dx) / 12, B = (ylim - dy) / 6, D = divup(divup(dx, 2) - divup(dx + dy, 3), 2) - 1, E = makesamepar(divup(dx, 2), dx + dy);
		//REPE(x, A) FORE(y, 0, min(B, x + D)) { int xx = 12 * x + dx, yy = 6 * y + dy; assert(xx >= 0 && xx <= xlim); assert(yy >= 0 && yy <= ylim); ++cnt[xx][yy]; }
		int cur = 0;
		{ // sum(x=max(0,B-D)..A,y=0..B,6*x+E)
			int xlo = max(0, B - D), xhi = A, ylo = 0, yhi = B;
			if (xlo <= xhi && ylo <= yhi) {
				cur = (cur + (ll)cnt(xlo, xhi) * cnt(ylo, yhi) % MOD * E) % MOD;
				cur = (cur + (ll)cnt(ylo, yhi) * sum(xlo, xhi) % MOD * 6) % MOD;
			}
		}
		{ // sum(x=0..min(A,B-D-1),y=0..x+D,6*x+E)
			int xlo = max(0, -D), xhi = min(A, B - D - 1);
			if (xlo <= xhi) {
				// E*sum(x=xlo..xhi,x+D+1) -> E*(D+1)*sum(x=xlo..xhi,1) + E*sum(x=xlo..xhi,x)
				// 6*sum(x=xlo..xhi,y=0..x+D,x) -> 6*(D+1)*sum(x=xlo..xhi,x) + 6*sum(x=xlo..xhi,x*x)
				cur = (cur + (ll)cnt(xlo, xhi) * E % MOD * (D + 1)) % MOD;
				cur = (cur + (ll)sum(xlo, xhi) * E) % MOD;
				cur = (cur + (ll)sum(xlo, xhi) * 6 % MOD * (D + 1)) % MOD;
				cur = (cur + (ll)sumsq(xlo, xhi) * 6) % MOD;
			}
		}
		//int chk = 0; REPE(x, A) FORE(y, 0, min(B, x + D)) { int xx = 12 * x + dx, yy = 6 * y + dy; inc(chk, calcformula(xx, yy)); } assert(cur == chk);
		inc(ret, cur);
	}

	// part2
	REP(dx, 12) if (dx <= xlim) REP(dy, 6) if (dy <= ylim) {
		// sum(x=0..(xlim-dx)/12,y=0..(ylim-dy)/6,x+ceil((ceil(dx/2)-ceil((dx+dy)/3))/2)<=y<=4*x+ceil((dx+dy)/3)-ceil(dy/2),4*x+2*y+makesamepar(ceil((dx+dy)/3),dx+dy)) = sum(x=0..A,y=max(0,x+C)..min(B,4x+D),4*x+2*y+E)
		int A = (xlim - dx) / 12, B = (ylim - dy) / 6, C = divup(divup(dx, 2) - divup(dx + dy, 3), 2), D = divup(dx + dy, 3) - divup(dy, 2), E = makesamepar(divup(dx + dy, 3), dx + dy);
		//REPE(x, A) FORE(y, max(0, x + C), min(B, 4 * x + D)) { int xx = 12 * x + dx, yy = 6 * y + dy; assert(xx >= 0 && xx <= xlim); assert(yy >= 0 && yy <= ylim); ++cnt[xx][yy]; }
		int cur = 0;
		{ // +sum(x=max(0,ceil((B-D)/4))..A,y=0..B,4*x+2*y+E)
			int xlo = max(0, divup(B - D, 4)), xhi = A, ylo = 0, yhi = B;
			if (xlo <= xhi && ylo <= yhi) {
				cur = (cur + (ll)cnt(xlo, xhi) * cnt(ylo, yhi) % MOD * E) % MOD;
				cur = (cur + (ll)cnt(ylo, yhi) * sum(xlo, xhi) % MOD * 4) % MOD;
				cur = (cur + (ll)cnt(xlo, xhi) * sum(ylo, yhi) % MOD * 2) % MOD;
			}
		}
		{ // +sum(x=0..min(A,ceil((B-D)/4)-1),y=0..4x+D,4*x+2*y+E)
			int xlo = max(0, divup(-D, 4)), xhi = min(A, divup(B - D, 4) - 1);
			if (xlo <= xhi) {
				// sum(x=xlo..xhi,y=0..4x+D,4x+2y+E) -> E*sum(x=xlo..xhi,4x+D+1) + 4*sum(x=xlo..xhi,4xx+x*(D+1)) + sum(x=xlo..xhi,16xx+4x*(2D+1)+D*(D+1))
				cur = (cur + (ll)cnt(xlo, xhi) * E % MOD * (D + 1)) % MOD;
				cur = (cur + (ll)sum(xlo, xhi) * E % MOD * 4) % MOD;
				cur = (cur + (ll)sumsq(xlo, xhi) * 16) % MOD;
				cur = (cur + (ll)sum(xlo, xhi) * (D + 1) % MOD * 4) % MOD;
				cur = (cur + (ll)sumsq(xlo, xhi) * 16) % MOD;
				cur = (cur + (ll)sum(xlo, xhi) * (2 * D + 1) % MOD * 4) % MOD;
				cur = (cur + (ll)cnt(xlo, xhi) * D % MOD * (D + 1)) % MOD;
			}
		}
		{ // -sum(x=max(0,B-C+1,ceil((B-D)/4))..A,y=0..B,4*x+2*y+E)
			int xlo = max(0, max(B - C + 1, divup(B - D, 4))), xhi = A, ylo = 0, yhi = B;
			if (xlo <= xhi && ylo <= yhi) {
				// -sum(x=xlo..xhi,4*x+2*y+E)
				cur = (cur - (ll)cnt(xlo, xhi) * cnt(ylo, yhi) % MOD * E % MOD + MOD) % MOD;
				cur = (cur - (ll)cnt(ylo, yhi) * sum(xlo, xhi) % MOD * 4 % MOD + MOD) % MOD;
				cur = (cur - (ll)cnt(xlo, xhi) * sum(ylo, yhi) % MOD * 2 % MOD + MOD) % MOD;
			}
		}
		{ // -sum(x=max(0,ceil((C-D-1)/3)..min(A,B-C),y=0..x+C-1,4*x+2*y+E)
			int xlo = max(0, max(1 - C, divup(C - D - 1, 3))), xhi = min(A, B - C);
			if (xlo <= xhi) {
				// -sum(x=xlo..xhi,y=0..x+C-1,4*x+2*y+E) -> -E*sum(x=xlo..xhi,x+C) -sum(x=xlo..xhi,4xx+4C*x) -sum(x=xlo..xhi,xx+x*(2C-1)+(C-1)*C)
				cur = (cur - (ll)cnt(xlo, xhi) * E % MOD * C % MOD + MOD) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * E % MOD + MOD) % MOD;
				cur = (cur - (ll)sumsq(xlo, xhi) * 4 % MOD + MOD) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * C % MOD * 4 % MOD + MOD) % MOD;
				cur = (cur - (ll)sumsq(xlo, xhi) % MOD + MOD) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * (2 * C - 1) % MOD + MOD) % MOD;
				cur = (cur - (ll)cnt(xlo, xhi) * (C - 1) % MOD * C % MOD + MOD) % MOD;
			}
		}
		{ // -sum(x=0..min(A,ceil((B-D)/4)-1,ceil((C-D-1)/3)-1),y=0..4x+D,4*x+2*y+E)
			int xlo = max(0, divup(-D, 4)), xhi = min(A, min(divup(B - D, 4) - 1, divup(C - D - 1, 3) - 1));
			if (xlo <= xhi) {
				// -sum(x=xlo..xhi,y=0..4x+D,4*x+2*y+E)
				cur = (cur - (ll)cnt(xlo, xhi) * E % MOD * (D + 1) % MOD + MOD) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * E % MOD * 4 % MOD + MOD) % MOD;
				cur = (cur - (ll)sumsq(xlo, xhi) * 16 % MOD + MOD) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * (D + 1) % MOD * 4 % MOD + MOD) % MOD;
				cur = (cur - (ll)sumsq(xlo, xhi) * 16 % MOD + MOD) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * (2 * D + 1) % MOD * 4 % MOD + MOD) % MOD;
				cur = (cur - (ll)cnt(xlo, xhi) * D % MOD * (D + 1) % MOD + MOD) % MOD;
			}
		}
		//int chk = 0; REPE(x, A) FORE(y, max(0, x + C), min(B, 4 * x + D)) { int xx = 12 * x + dx, yy = 6 * y + dy; inc(chk, calcformula(xx, yy)); } assert(cur == chk);
		inc(ret, cur);
	}

	// part3
	REP(dx, 6) if (dx <= xlim) REP(dy, 12) if (dy <= ylim) {
		// sum(x=0..(xlim-dx)/3,y=0..(ylim-dy)/12,y>x+ceil((dx+dy)/3)-ceil(dy/2),6*y+makesamepar(ceil(dy/2),dx+dy)) = sum(x=0..A,y=max(0,x+C)..B,6*y+E)
		int A = (xlim - dx) / 6, B = (ylim - dy) / 12, C = divdn(divup(dx + dy, 3) - divup(dy, 2),2) + 1, E = makesamepar(divup(dy, 2), dx + dy);
		//REPE(x, A) FORE(y, max(0, x + C), B) { int xx = 6 * x + dx, yy = 12 * y + dy; assert(xx >= 0 && xx <= xlim); assert(yy >= 0 && yy <= ylim); ++cnt[xx][yy]; }
		int cur = 0;
		{ // sum(x=0..min(A,-C),y=0..B,6*y+E)
			int xlo = 0, xhi = min(A, -C), ylo = 0, yhi = B;
			if (xlo <= xhi && ylo <= yhi) {
				cur = (cur + (ll)cnt(xlo, xhi) * cnt(ylo, yhi) % MOD * E) % MOD;
				cur = (cur + (ll)cnt(xlo, xhi) * sum(ylo, yhi) % MOD * 6) % MOD;
			}
		}
		{ // sum(x=max(0,-C+1)..A,y=x+C..B,6*y+E)
			int xlo = max(0, -C + 1), xhi = min(A, B - C);
			if (xlo <= xhi) {
				// E*sum(x=xlo..xhi,B-C+1-x) -> E*sum(x=xlo..xhi,B-C+1) - E*sum(x=xlo..xhi,x)
				// sum(x=xlo..xhi,y=x+C..B,6*y) -> 3*sum(x=xlo..xhi,(C+B)*(B-C+1)-x*(2C-1)-x*x)
				cur = (cur + (ll)cnt(xlo, xhi) * E % MOD * (B - C + 1)) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * E % MOD + MOD) % MOD;
				cur = (cur + (ll)cnt(xlo, xhi) * (C + B) % MOD * (B - C + 1) % MOD * 3) % MOD;
				cur = (cur - (ll)sum(xlo, xhi) * (2 * C - 1) % MOD * 3 % MOD + MOD) % MOD;
				cur = (cur - (ll)sumsq(xlo, xhi) * 3 % MOD + MOD) % MOD;
			}
		}
		//int chk = 0; REPE(x, A) FORE(y, max(0, x + C), B) { int xx = 6 * x + dx, yy = 12 * y + dy; inc(chk, calcformula(xx, yy)); } assert(cur == chk);
		inc(ret, cur);
	}
	//REPE(x, xlim) { printf("%2d: ", x); REPE(y, ylim) printf("%d", cnt[x][y]); puts(""); }
	//REPE(x, xlim) REPE(y, ylim) if (cnt[x][y] != 1) { printf("(%d,%d)\n", x, y); exit(0); }
	vector<pair<int, int>> special; special.PB(MP(1, 0)); special.PB(MP(0, 1)); special.PB(MP(1, 1)); special.PB(MP(3, 0)); special.PB(MP(0, 3)); special.PB(MP(2, 2));
	REPSZ(i, special) {
		int x, y; tie(x, y) = special[i];
		if (x <= xlim && y <= ylim) {
			dec(ret, calcformula(x, y));
			inc(ret, calc(x, y));
		}
	}
	return ret;
}

void precalc() {
	inv[1] = 1; FORE(i, 2, 6) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
}

int solve() {
	int ret = 0;
	inc(ret, calcsum(xdim - 1, ydim - 1));
	dec(ret, calcsum(xdim - 1, qy - 1));
	dec(ret, calcsum(qx - 1, ydim - 1));
	inc(ret, calcsum(qx - 1, qy - 1));
	return ret;
}

void run() {
	scanf("%d%d%d%d", &qx, &qy, &xdim, &ydim); --qx, --qy;
	printf("%d\n", solve());
}

void verifycalc() {
	for (xdim = 3; xdim <= 20; ++xdim) for (ydim = 3; ydim <= 20; ++ydim) {
		vector<vector<int>> d(xdim, vector<int>(ydim, INT_MAX));
		queue<pair<int, int>> q;
		d[0][0] = 0, q.push(MP(0, 0));
		while (!q.empty()) {
			int x, y; tie(x, y) = q.front(); q.pop();
			FORE(dx, -2, +2) FORE(dy, -2, +2) if (dx * dx + dy * dy == 5) {
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= xdim || ny < 0 || ny >= ydim) continue;
				if (d[nx][ny] == INT_MAX) d[nx][ny] = d[x][y] + 1, q.push(MP(nx, ny));
			}
		}
		//REP(x, xdim) REP(y, ydim) printf("(%d,%d) -> %d vs %d\n", x, y, d[x][y], calc(x, y));
		REP(x, xdim) REP(y, ydim) if (d[x][y] == INT_MAX) { assert(xdim == 3 && ydim == 3 && x == 1 && y == 1); d[x][y] = 0; }
		REP(x, xdim) REP(y, ydim) assert(d[x][y] == calc(x, y));
		printf("done (%d,%d)\n", xdim, ydim);
	}
}

void verifysum() {
	for (xdim = 3; xdim <= 100; ++xdim) {
		for (ydim = 3; ydim <= 100; ++ydim) FORE(dx,1,min(xdim,3)) FORE(dy,1,min(ydim,3)) {
			int have = calcsum(xdim - dx, ydim - dy);
			int want = calcsumstupid(xdim - dx, ydim - dy);
			assert(have == want);
		}
		printf("done xdim=%d\n", xdim);
	}
}

int main() {
	precalc();
	//verifycalc();
	//verifysum();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}