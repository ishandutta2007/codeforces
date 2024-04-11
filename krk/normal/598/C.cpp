#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <ld, int> ldi;

const int Maxn = 100005;
const ll w = 1000000000;

struct Mult {
	ll p1, p2, p3;
	Mult(ll n1 = 0, ll n2 = 0) {
		ll a = n1 / w, b = n1 % w;
		ll c = n2 / w, d = n2 % w;
		p3 = b * d;
		p2 = a * d + c * b;
		p1 = a * c;
		ll car = 0;
		car += p3; p3 = car % w; car /= w;
		car += p2; p2 = car % w; car /= w;
		car += p1; p1 = car;
	}
	bool operator <(const Mult &b) const {
		if (p1 != b.p1) return p1 < b.p1;
		if (p2 != b.p2) return p2 < b.p2;
		return p3 < b.p3;
	}
};

struct frac {
 	ll a, b;
 	ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }
 	frac(ll ga = 0ll, ll gb = 1ll) {
 		a = ga; b = gb;
 		ll g = gcd(abs(a), b);
 		a /= g; b /= g;
 	}
 	bool operator <(const frac &u) const {
 		if (a < 0 && u.a < 0) return Mult(abs(u.a), b) < Mult(abs(a), u.b);
 		else if (a < 0 && u.a >= 0) return true;
 		else if (a >= 0 && u.a < 0) return false;
 		else return Mult(a, u.b) < Mult(u.a, b);
 	}
};

int n;
int X[Maxn], Y[Maxn];
ldi srt[Maxn];
frac best = frac(-10, 1);
int bi, bj;

ll Len(int a) { return ll(X[a]) * X[a] + ll(Y[a]) * Y[a]; }

frac Get(int a, int b)
{
	ll dt = ll(X[a]) * X[b] + ll(Y[a]) * Y[b];
	dt *= abs(dt);
	return frac(dt, Len(a) * Len(b));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		srt[i] = ldi(atan2(ld(Y[i]), ld(X[i])), i);
	}
	sort(srt, srt + n);
	for (int i = 0; i < n; i++) {
		int ci = srt[i].second;
		int cj = srt[(i + 1) % n].second;
		frac cand = Get(ci, cj);
		if (best < cand) { best = cand; bi = ci; bj = cj; }
	}
	printf("%d %d\n", bi + 1, bj + 1);
	return 0;
}