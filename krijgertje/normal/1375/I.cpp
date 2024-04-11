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

struct HurwitzQuat {
	ll s, x, y, z;
	HurwitzQuat(ll s = 0, ll x = 0, ll y = 0, ll z = 0) :s(s), x(x), y(y), z(z) { }
};
void printdiv2(ll v) { if (v < 0) printf("-"), v = -v; printf("%lld.%lld", v / 2, v % 2 * 5); }
void print(const HurwitzQuat &a) { printf("("); printdiv2(a.s); printf(","); printdiv2(a.x); printf(","); printdiv2(a.y); printf(","); printdiv2(a.z); printf(")"); }

ll norm(const HurwitzQuat &a) { ll ret = a.s*a.s + a.x*a.x + a.y*a.y + a.z*a.z; assert(ret % 4 == 0); return ret / 4; }
HurwitzQuat conj(const HurwitzQuat &a) { return HurwitzQuat(a.s, -a.x, -a.y, -a.z); }
HurwitzQuat operator-(const HurwitzQuat &a, const HurwitzQuat &b) { return HurwitzQuat(a.s - b.s, a.x - b.x, a.y - b.y, a.z - b.z); }
HurwitzQuat operator*(const HurwitzQuat &a, const HurwitzQuat &b) { 
	//(a+B)(c+D) = ac-(B,D)+aD+cB+[B,D]		[B,D]=[B.y*D.z-B.z*D.y,B.z*D.x-B.x*D.z,B.x*D.y-B.y*D.x]
	ll s = a.s*b.s - a.x*b.x - a.y*b.y - a.z*b.z;
	ll x = a.s*b.x + b.s*a.x + a.y*b.z - a.z*b.y;
	ll y = a.s*b.y + b.s*a.y + a.z*b.x - a.x*b.z;
	ll z = a.s*b.z + b.s*a.z + a.x*b.y - a.y*b.x;
	assert(s % 2 == 0 && x % 2 == 0 && y % 2 == 0 && z % 2 == 0);
	return HurwitzQuat(s / 2, x / 2, y / 2, z / 2);
}

//bool debug = false;
ll divclose(ll num, ll den) { if (den < 0) num = -num, den = -den; num = 2 * num + den, den = 2 * den; return num >= 0 ? num / den : (num - den + 1) / den; }
pair<HurwitzQuat, HurwitzQuat> div(const HurwitzQuat &a, const HurwitzQuat &b) {
	// a*inv(b) -> a*conj(b)/norm(b)
	HurwitzQuat num = conj(b)*a;
	ll den = norm(b);
	//if (debug) { printf("\t\t"); print(conj(b)); printf("*"); print(a); puts(""); }
	//if (debug) printf("\t\tnum=(%lld,%lld,%lld,%lld) den=%lld\n", num.s, num.x, num.y, num.z, den);
	HurwitzQuat q;
	if (num.s % (2 * den) == 0 || num.s%den != 0 || num.x % (2 * den) == 0 || num.x%den != 0 || num.y % (2 * den) == 0 || num.y%den != 0 || num.z % (2 * den) == 0 || num.z%den != 0) {
		q = HurwitzQuat(2 * divclose(num.s, 2 * den), 2 * divclose(num.x, 2 * den), 2 * divclose(num.y, 2 * den), 2 * divclose(num.z, 2 * den));
	} else {
		q = HurwitzQuat(2 * divclose(num.s - den, 2 * den) + 1, 2 * divclose(num.x - den, 2 * den) + 1, 2 * divclose(num.y - den, 2 * den) + 1, 2 * divclose(num.z - den, 2 * den) + 1);
	}
	return MP(q, a - b*q);
}

HurwitzQuat gcd(const HurwitzQuat &a, const HurwitzQuat &b) { return norm(b) == 0 ? a : gcd(b, div(a, b).second); }


const int MAXN = 10000;

int n;
ll x[MAXN], y[MAXN], z[MAXN];
ll ansnorm;
ll ansx[3], ansy[3], ansz[3];

HurwitzQuat a[MAXN];

void solve() {
	ll G = 0;
	HurwitzQuat g(0);
	REP(i, n) {
		a[i] = HurwitzQuat(0, 2 * x[i], 2 * y[i], 2 * z[i]);
		//printf("a[%d]=", i); print(a[i]); puts("");
		G = gcd(G, norm(a[i]));
		g = gcd(g, a[i]);
	}
	//g = HurwitzQuat(-1, -1, -1, 3);
	//printf("G=%lld\n", G);
	//printf("g="); print(g); puts("");
	/*REP(i, n) {
		debug = true;
		HurwitzQuat q, r; tie(q, r) = div(a[i], g);
		debug = false;
		printf("%d: ", i); print(q); printf(", "); print(r); puts("");
	}*/

	vector<ll> cand;
	for (ll x = 1; x*x*x <= G; ++x) {
		if (G % (x*x) == 0) cand.PB(x);
		if (G%x == 0) { ll y = sqrt(G / x); if (y*y == G / x) cand.PB(y); }
	}
	sort(cand.begin(), cand.end()); cand.erase(unique(cand.begin(), cand.end()), cand.end());
	//printf("cand:"); REPSZ(i, cand) printf(" %lld", cand[i]); puts("");
	for (int i = SZ(cand) - 1; i >= 0; --i) {
		HurwitzQuat q = gcd(g, HurwitzQuat(2 * cand[i]));
		if (norm(q) != cand[i]) continue;
		//printf("q="); print(q); puts("");
		// k*q*b[i]*conj(q)=a[i]
		// b[i]=1/k*conj(q)/norm(q)*a[i]*q/norm(q)
		bool ok = true;
		REP(j, n) {
			HurwitzQuat num = conj(q)*a[j] * q; ll den = norm(q)*norm(q);
			if (num.s % (2 * den) != 0 || num.x % (2 * den) != 0 || num.y % (2 * den) != 0 || num.z % (2 * den) != 0) { ok = false; break; }
			//printf("\tnum="); print(num); printf(" den=%lld\n", den);
			//printf("\t\t"); print(conj(q)); printf("*"); print(a[j]); printf("*"); print(q); puts("");
		}
		if (ok) {
			ansnorm = norm(q)*norm(q);
			REP(i, 3) { HurwitzQuat e = q*HurwitzQuat(0, i == 0 ? 2 : 0, i == 1 ? 2 : 0, i == 2 ? 2 : 0)*conj(q); assert(e.s == 0 && e.x % 2 == 0 && e.y % 2 == 0 && e.z % 2 == 0); ansx[i] = e.x / 2, ansy[i] = e.y / 2, ansz[i] = e.z / 2; }
			return;
		}
	}
	assert(false);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
	solve();
	printf("%lld\n", ansnorm);
	REP(i, 3) printf("%lld %lld %lld\n", ansx[i], ansy[i], ansz[i]);
}

int main() {
	run();
	return 0;
}