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

const int MAXN = 50;
const double eps = 1e-9;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
double len(const P& a) { return sqrt(1.0 * a.x * a.x + 1.0 * a.y * a.y); }
double dist(const P& a, const P& b) { return len(b - a); }
ll dot(const P& a, const P& b) { return (ll)a.x * b.x + (ll)a.y * b.y; }
ll cross(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
ll len2(const P& a) { return (ll)a.x * a.x + (ll)a.y * a.y; }
ll dist2(const P& a, const P& b) { return len2(b - a); }

int n;
P p[MAXN + 1];

double offset[MAXN + 1];

vector<pair<double, double>> calc(double a, double b, double c) { // a*s^2+b*s+c
	//printf("\t%lfs^2 + %lfs + %lf > 0\n", a, b, c);
	vector<pair<double, double>> ret;
	if (fabs(a) > eps) {
		double d = b * b - 4 * a * c; 
		if (d < eps) {
			if (a > 0) {
				ret.PB(MP(0.0, 1.0));
			} else {
			}
		} else {
			d = sqrt(d);
			double s1 = (-d - b) / (2 * a), s2 = (+d - b) / (2 * a); if (s1 > s2) swap(s1, s2);
			//printf("\t\ts1=%lf s2=%lf [%lf %lf]\n", s1, s2, a * s1 * s1 + b * s1 + c, a * s2 * s2 + b * s2 + c);
			if (a > 0) {
				if (s1 > eps) ret.PB(MP(0.0, min(s1, 1.0)));
				if (s2 < 1 - eps) ret.PB(MP(max(0.0, s2), 1.0));
			} else {
				if (s1<1 - eps && s2>eps) ret.PB(MP(max(s1, 0.0), min(s2, 1.0)));
			}
		}
	} else if (fabs(b) > eps) {
		double s = -c / b;
		//printf("\t\ts=%lf\n", s);
		if (b > 0) {
			if (s < 1 - eps) ret.PB(MP(max(0.0, s), 1.0));
		} else {
			if (s > eps) ret.PB(MP(0.0, min(1.0, s)));
		}
	} else {
		if (c > eps) ret.PB(MP(0.0, 1.0));
	}
	return ret;
}

vector<pair<double, double>> calc(double v, const P& A, const P& B, const P& C, const P& D, double costBC) {
	//printf("%lf: calc (%d,%d)-(%d,%d) to (%d,%d)-(%d,%d) with cost %lf\n", v, A.x, A.y, B.x, B.y, C.x, C.y, D.x, D.y, costBC);
	double w = 1 / v;
	// |P-Q| < w * (|B-P| + costBC + |Q-C|)
	// P=B+s*(A-B), Q=C+t*(D-C), 0<=s<=1 and 0<=t<=1
	// we want to find the values of s, for which there is at least one value of t that satisfies the equation
	// |B+s*(A-B)-C-t*(D-C)| < w * (s*|A-B| + costBC + t*|D-C|)
	// ((Bx-Cx)+s*(Ax-Bx)-t*(Dx-Cx))^2+((By-Cy)+s*(Ay-By)-t*(Dy-Cy))^2 < w^2 * (s^2*|A-B|^2 + costBC^2 + t^2*|D-C|^2 + 2*s*|A-B|*costBC + 2*s*|A-B|*t*|D-C| +2*costBC*t*|D-C|)
	// |B-C|^2 + s^2*|A-B|^2 + t^2*|D-C|^2 + 2*s*dot(B-C,A-B) - 2*t*dot(B-C,D-C) - 2*s*t*dot(A-B,D-C) < w^2 * (s^2*|A-B|^2 + costBC^2 + t^2*|D-C|^2 + 2*s*|A-B|*costBC + 2*s*|A-B|*t*|D-C| +2*costBC*t*|D-C|)
	// a*s^2+b*t^2+c*s*t+d*s+e*t+f>0
	double a = (w * w - 1) * dist2(A, B);
	double b = (w * w - 1) * dist2(C, D);
	double c = 2 * w * w * dist(A, B) * dist(C, D) + 2 * dot(A - B, D - C);
	double d = 2 * w * w * dist(A, B) * costBC + 2 * dot(B - C, B - A);
	double e = 2 * w * w * dist(C, D) * costBC + 2 * dot(B - C, D - C);
	double f = w * w * costBC * costBC - dist2(B, C);
	//printf("\t%lfs^2 + %lft^2 + %lfst + %lfs + %lft + %lf > 0\n", a, b, c, d, e, f);
	// t is one of 0 or 1 or -(c*s+e)/(2*b)=g*s+h, but g*s+h in [0..1]
	double g = -c / (2 * b), h = -e / (2 * b);
	double slo = 0.0, shi = 1.0; if (fabs(g) > eps) { double s1 = -h / g; if (g < 0) shi = min(shi, s1); else slo = max(slo, s1); double s2 = (1 - h) / g; if (g < 0) slo = max(slo, s2);  else shi = min(shi, s2); }
	//printf("\tt is one of 0 / 1 / %lfs + %lf (with s in %lf..%lf)\n", g, h, slo, shi);
	auto res1 = calc(a, d, f); // t==0
	auto res2 = calc(a, c + d, b + e + f); // t==1
	auto res3 = calc(a + b * g * g + c * g, 2 * b * g * h + c * h + d + e * g, b * h * h + e * h + f); // t=g*s+h
	vector<pair<double, double>> ret;
	REPSZ(i, res1) ret.PB(res1[i]);
	REPSZ(i, res2) ret.PB(res2[i]);
	REPSZ(i, res3) { double lo = max(res3[i].first, slo), hi = min(res3[i].second, shi); if (hi - lo > eps) ret.PB(MP(lo, hi)); }
	// if s=0.1
	/*for (double s : { 0.03, 1 - 0.03 }) {
		double t = g * s + h, px = B.x + s * (A - B).x, py = B.y + s * (A - B).y, qx = C.x + t * (D - C).x, qy = C.y + t * (D - C).y;
		double lhs = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy)), rhs = w * (sqrt((B.x - px) * (B.x - px) + (B.y - py) * (B.y - py)) + costBC + sqrt((qx - C.x) * (qx - C.x) + (qy - C.y) * (qy - C.y)));
		//printf("!!! s=%lf t=%lf eq=%lf (%lf,%lf)->(%lf,%lf) -> %lf vs %lf\n", s, t, a * s * s + b * t * t + c * s * t + d * s + e * t + f, px, py, qx, qy, lhs, rhs);
	}*/
	return ret;

	// a+b*gg+cg>0 -> a+1/4*c^2/b-1/2*c^2/b>0 -> c^2>4*a*b

	// c^2=(2 * w * w * dist(A, B) * dist(C, D) + 2 * dot(A - B, D - C))*(2 * w * w * dist(A, B) * dist(C, D) + 2 * dot(A - B, D - C))
	// c^2=4*w*w*w*w*dist2(A, B) * dist2(C, D)+8*w * w * dist(A, B) * dist(C, D)*dot(A - B, D - C)+4*dot(A - B, D - C)*dot(A - B, D - C)
	// 4a*b=4*(w * w - 1) * dist2(A, B)*(w * w - 1) * dist2(C, D)
	// 4a*b=4*w*w*w*w* dist2(A, B)* dist2(C, D) - 4*w*w*(dist2(A,B)+dist2(C,D))+  4*dist2(A, B)* dist2(C, D)

	// ((ax-bx)^2+(ay-by)^2)((cx-dx)^2+(cy-dy)^2)=(ax-bx)(ax-bx)(cx-dx)(cx-dx)+(ax-bx)(ax-bx)(cy-dy)(cy-dy)+(ay-by)(ay-by)(cx-dx)(cx-dx)+(ay-by)(ay-by)(cy-dy)(cy-dy)
	// dot(A - B, D - C)^2 = ((ax-bx)*(dx-cx)+(ay-by)(dy-cy))^2 = (ax-bx)*(dx-cx)*(ax-bx)*(dx-cx)+2*(ax-bx)*(dx-cx)*(ay-by)(dy-cy)+(ay-by)(dy-cy)*(ay-by)(dy-cy))

	//      (ax-bx)(ax-bx)(cy-dy)(cy-dy)+(ay-by)(ay-by)(cx-dx)(cx-dx)=UX^2*VY^2+UY^2VX^2
	// vs 2*(ax-bx)*(dx-cx)*(ay-by)(dy-cy) = 2*UX VX UY VY
	// 8*w^2*... vs UX^2*VY^2+UY^2VX^2-2*UX*VX*UY*VY=(UXVY-UYVX)^2=dot(A-B,D-C)^2



}

vector<pair<double, double>> simplify(vector<pair<double, double>> r) {
	vector<pair<double, double>> ret;
	sort(r.begin(), r.end());
	REPSZ(i, r) if (SZ(ret) == 0 || r[i].first > ret.back().second) ret.PB(r[i]); else ret.back().second = max(ret.back().second, r[i].second);
	return ret;
}

bool intersect(vector<pair<double, double>> a, vector<pair<double, double>> b) {
	int bi = 0;
	REPSZ(ai, a) {
		while (bi < SZ(b) && b[bi].second < a[ai].first) ++bi;
		if (bi < SZ(b) && b[bi].first <= a[ai].second) return true;
	}
	return false;
}


bool can(double v) {
	offset[0] = 0; REP(i, n) offset[i + 1] = offset[i] + dist(p[i], p[i + 1]);

	REP(i, n) {
		vector<pair<double, double>> before;
		REP(j, i) { auto res = calc(v, p[i + 1], p[i], p[j + 1], p[j], offset[i] - offset[j + 1]); REPSZ(k, res) before.PB(res[k]); }
		before = simplify(before);
		vector<pair<double, double>> after;
		FOR(j, i + 1, n) { auto res = calc(v, p[i], p[i + 1], p[j], p[j + 1], offset[j] - offset[i + 1]); REPSZ(k, res) after.PB(MP(1 - res[k].second, 1 - res[k].first)); }
		after = simplify(after);
		//printf("before %d:", i); REPSZ(j, before) printf(" [%lf..%lf]", before[j].first, before[j].second); puts("");
		//printf("after %d:", i); REPSZ(j, after) printf(" [%lf..%lf]", after[j].first, after[j].second); puts("");
		if (intersect(before, after)) return true;
	}
	return false;
}

double solve() {
	//printf("%s\n", can(1.132) ? "YES" : "NO"); return -1;

	double lo = 1, hi = 2;
	while (can(hi)) lo = hi, hi *= 2;
	REP(rep, 100) {
		double mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	return lo + (hi - lo) / 2;
}

void run() {
	scanf("%d", &n);
	REPE(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%.15lf\n", solve());
}

int main() {
	run();
	return 0;
}