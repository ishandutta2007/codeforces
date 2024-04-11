#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;

int n;
int x[MAXN], y[MAXN];
int ox[MAXN], oy[MAXN];

queue<int> q;
vector<pair<int, int> > op;
int ans[MAXN];

void process(int a, int b, int c) {
	int d[3] = { a,b,c };
	ll mx = max((ll)x[a] * x[a] + (ll)y[a] * y[a], max((ll)x[b] * x[b] + (ll)y[b] * y[b], (ll)x[c] * x[c] + (ll)y[c] * y[c]));

	REP(i, 3) FOR(j, i + 1, 3) REP(dir, 2) {
		int nx = x[d[i]] + (dir == 0 ? -1 : +1)*x[d[j]];
		int ny = y[d[i]] + (dir == 0 ? -1 : +1)*y[d[j]];
		if ((ll)nx*nx + (ll)ny*ny <= mx) {
			op.PB(MP(d[j], 2 * d[i] + dir));
			//printf("combining (%d,%d) with (%d,%d) -> (%d,%d)\n", x[d[i]], y[d[i]], x[d[j]], y[d[j]], nx, ny);
			x[d[i]] = nx, y[d[i]] = ny;
			q.push(d[i]); q.push(d[3 - i - j]);
			return;
		}
	}
	assert(false);
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d%d", &x[i], &y[i]);

	REP(i, n) ox[i] = x[i], oy[i] = y[i];
	REP(i, n) q.push(i);
	while (SZ(q) >= 3) {
		int a = q.front(); q.pop(); int b = q.front(); q.pop(); int c = q.front(); q.pop();
		process(a, b, c);
	}
	if (SZ(q) == 1) {
		int a = q.front(); q.pop();
		ans[a] = +1;
	} else {
		assert(SZ(q) == 2);
		int a = q.front(); q.pop(); int b = q.front(); q.pop();
		ll mx = max((ll)x[a] * x[a] + (ll)y[a] * y[a], (ll)x[b] * x[b] + (ll)y[b] * y[b]);
		//printf("final: (%d,%d) (%lf) and (%d,%d) (%lf)\n", x[a], y[a], sqrt(1.0*x[a] * x[a] + 1.0*y[a] * y[a]), x[b], y[b], sqrt(1.0*x[b] * x[b] + 1.0*y[b] * y[b]));
		bool found = false;
		REP(dir, 2) {
			int nx = x[a] + (dir == 0 ? -1 : +1)*x[b];
			int ny = y[a] + (dir == 0 ? -1 : +1)*y[b];
			//printf("(%d,%d) (%lf) mx=%lld cur=%lld (%lf)\n", nx, ny, sqrt(1.0*nx*nx + 1.0*ny*ny), mx, (ll)nx*nx + (ll)ny*ny, 1.0*((ll)nx*nx + (ll)ny*ny) / mx);
			if (10 * 10 * ((ll)nx*nx + (ll)ny*ny) <= 15 * 15 * mx) {
				found = true;
				ans[a] = +1; ans[b] = dir == 0 ? -1 : +1;
				break;
			}
		}
		assert(found);
	}
	for (int i = SZ(op) - 1; i >= 0; --i) {
		int b = op[i].first, a = op[i].second / 2, dir = op[i].second % 2;
		ans[b] = dir == 0 ? -ans[a] : +ans[a];
	}
	ll resx = 0, resy = 0; REP(i, n) resx += ans[i] * ox[i], resy += ans[i] * oy[i];
	fprintf(stderr, "(%lld,%lld) = %lf\n", resx, resy, sqrt(1.0*resx*resx + 1.0*resy*resy));
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}