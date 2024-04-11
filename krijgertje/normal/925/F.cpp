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

const int MAXN = 1000;
const int MAXM = 2000;
struct E { int from, to, al, bl, ar, br; double l, r; };

const int GMAXN = MAXN + 2;
const int GMAXM = 2 * MAXN + MAXM;
const double eps = 1e-12;
struct G {
	int n, m;
	int ghead[GMAXN], gnxt[2 * GMAXM], gto[2 * GMAXM]; double gcap[2 * GMAXM];
	
	int level[GMAXN];
	int q[GMAXN], qhead, qtail;
	int gcur[GMAXN];
	int path[GMAXN], npath;
	
	bool incut[2 * GMAXM];

	void init(int _n) { n = _n, m = 0; REP(i, n) ghead[i] = -1; }
	int addedge(int a, int b, double cap) {
		int ret = m;
		//printf("addedge(%d,%d,%lf)\n", a, b, cap);
		gnxt[m] = ghead[a], ghead[a] = m, gto[m] = b, gcap[m] = cap; ++m;
		gnxt[m] = ghead[b], ghead[b] = m, gto[m] = a, gcap[m] = 0; ++m;
		return ret;
	}
	bool calclevel(int s,int t) {
		REP(i, n) level[i] = -1; qhead = qtail = 0;
		level[s] = 0, q[qhead++] = s;
		while (qtail < qhead) {
			int at = q[qtail++];
			for (int x = ghead[at]; x != -1; x = gnxt[x]) if (gcap[x] >= eps) {
				int to = gto[x]; if (level[to] == -1) level[to] = level[at] + 1, q[qhead++] = to;
			}
		}
		//printf("level:"); REP(i, n) printf(" %d", level[i]); puts("");
		return level[t] != -1;
	}
	bool augment(int at, int t, double lim, double &flow) {
		if (at == t) { flow = lim; path[npath++] = at; return true; }
		for (; gcur[at] != -1; gcur[at] = gnxt[gcur[at]]) {
			int x = gcur[at], to = gto[x];
			if (gcap[x] < eps || level[to] != level[at] + 1) continue;
			if (augment(to, t, min(lim, gcap[x]), flow)) { gcap[x] -= flow; gcap[x ^ 1] += flow; path[npath++] = at; return true; }
		}
		return false;
	}
	double maxflow(int s, int t) {
		double ret = 0;
		while (calclevel(s, t)) {
			REP(i, n) gcur[i] = ghead[i];
			while (true) {
				double cur; npath = 0;
				if (!augment(s, t, 1e200, cur)) break;
				ret += cur;
				//reverse(path, path + npath); printf("found path"); REP(i, npath) printf(" %d", path[i]); printf(" of value %lf\n", cur);
			}
		}
		return ret;
	}
	void calccut(int s,int t) {
		assert(!calclevel(s, t));
		REP(i, m) incut[i] = false;
		REP(at, n) if (level[at] >= 0) for (int x = ghead[at]; x != -1; x = gnxt[x]) if (level[gto[x]] == -1) incut[x] = true;
		//printf("cut:"); REP(x, m) if (incut[x]) printf(" %d->%d", gto[x ^ 1], gto[x]); puts("");
	}
};


int n, m;
E e[MAXM];

G g;
double insum[MAXN], outsum[MAXN];
int inid[MAXN], outid[MAXN], eid[MAXM];

void findcut(double t, int &acut, int &bcut) {
	REP(i, m) e[i].l = e[i].al*t + e[i].bl, e[i].r = e[i].ar*t + e[i].br;
	REP(i, n) insum[i] = outsum[i] = 0; REP(i, m) outsum[e[i].from] += e[i].l, insum[e[i].to] += e[i].l;
	
	g.init(n + 2); int src = n, dst = n + 1;
	REP(i, n) inid[i] = insum[i] != 0 ? g.addedge(src, i, insum[i]) : -1;
	REP(i, n) outid[i] = outsum[i] != 0 ? g.addedge(i, dst, outsum[i]) : -1;
	REP(i, m) eid[i] = e[i].l < e[i].r ? g.addedge(e[i].from, e[i].to, e[i].r - e[i].l) : -1;
	g.maxflow(src, dst);
	g.calccut(src, dst);

	acut = bcut = 0;
	REP(i, m) acut -= e[i].al, bcut -= e[i].bl;
	REP(i, m) {
		if (eid[i] != -1 && g.incut[eid[i]]) acut += e[i].ar - e[i].al, bcut += e[i].br - e[i].bl;
		if (outid[e[i].from] != -1 && g.incut[outid[e[i].from]]) acut += e[i].al, bcut += e[i].bl;
		if (inid[e[i].to] != -1 && g.incut[inid[e[i].to]]) acut += e[i].al, bcut += e[i].bl;
	}
}

bool findnonneg(double &tres) {
	double l = 0, r = 1;
	REP(rep, 100) {
		if (l > r) return false;
		double m = l + (r - l) / 2;
		int a, b; findcut(m, a, b);
		//printf("%lf: %lf (%d*t+%d)\n", m, a*m + b, a, b);
		if (a > 0) {
			if (a*m + b >= 0) { tres = m; return true; }
			double nl = -1.0 * b / a; assert(nl > l); l = nl;
		} else if (a < 0) {
			if (a*m + b >= 0) { tres = m; return true; }
			double nr = -1.0 * b / a; assert(nr < r); r = nr;
		} else {
			if (b >= 0) { tres = m; return true; }
			return false;
		}
	}
	printf("err: %.15lf..%15lf\n", l, r);
	return false;
}

double findtmn(double tok) {
	double l = 0, r = tok;
	REP(rep, 100) {
		if (r - l < 1e-7) break;
		double m = l + (r - l) / 2;
		int a, b; findcut(m, a, b);
		//printf("%lf: %lf (%d*t+%d)\n", m, a*m + b, a, b);
		if (a*m + b >= 0) {
			r = m;
		} else {
			assert(a > 0);
			double nl = -1.0 * b / a; assert(nl > l); l = nl;
		}
	}
	return r;
}

double findtmx(double tok) {
	double l = tok, r = 1;
	REP(rep, 100) {
		if (r - l < 1e-7) break;
		double m = l + (r - l) / 2;
		int a, b; findcut(m, a, b);
		//printf("%lf: %lf (%d*t+%d)\n", m, a*m + b, a, b);
		if (a*m + b >= 0) {
			l = m;
		} else {
			assert(a < 0);
			double nr = -1.0 * b / a; assert(nr < r); r = nr;
		}
	}
	return l;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d%d%d%d", &e[i].from, &e[i].to, &e[i].al, &e[i].bl, &e[i].ar, &e[i].br), --e[i].from, --e[i].to;

	/*REPE(rep, 100) {
		double t = 0.01*rep;
		//if (rep != 25) continue;
		int a, b; findcut(t, a, b);
		printf("%lf: %lf (%d*t+%d)\n", t, a*t + b, a, b);
	}*/

	double tnonneg;
	if (!findnonneg(tnonneg)) { printf("0\n"); return; }
	//printf("tnonneg=%.15lf\n", tnonneg);

	double tmn = findtmn(tnonneg);
	//printf("tmn=%.15lf\n", tmn);
	double tmx = findtmx(tnonneg);
	//printf("tmx=%.15lf\n", tmx);

	printf("%.15lf\n", tmx - tmn);
}

int main() {
	run();
	return 0;
}