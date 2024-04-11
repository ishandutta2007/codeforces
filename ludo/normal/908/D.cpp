#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct frac {
	ll p, q;
	frac() : p(0), q(1) {}
	frac(ll n) : p(n), q(1) {}
	frac(ll _p, ll _q) : p(_p), q(_q) {}
};

const int maxk = 1000;
ll mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	while (b) a %= b, swap(a, b);
	return a;
}

frac reduce(ll p, ll q) {
	p %= mod;
	q %= mod;
	if (p == 0 && q == 0) return frac();
	ll g = gcd(p, q);
	return frac(p / g, q / g);
}

frac operator+(frac a, frac b) { return reduce(a.p * b.q + a.q * b.p, a.q * b.q); }
frac operator-(frac a, frac b) { return reduce(a.p * b.q - a.q * b.p, a.q * b.q); }
frac operator*(frac a, frac b) { return reduce(a.p * b.p, a.q * b.q); }
frac operator/(frac a, frac b) { return reduce(a.p * b.q, a.q * b.p); }

ll powmod(ll base, ll exp) {
	ll ret = 1;
	while (exp) {
		if (exp & 1) ret = (ret * base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}
	return ret;
}

int K;
frac PA, PB, E[maxk][maxk] = {};

frac expected(int i, int j)
{ 
	if (j >= K) return frac(j);
	if (i + j >= K) return frac(i + j) + PA / PB;
	return E[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll na, nb;
	cin >> K >> na >> nb;
	PA = frac(na, na + nb);
	PB = frac(nb, na + nb);

	for (int i = K; --i >= 0; ) for (int j = K; --j >= 0; )
		E[i][j] = PA * expected(i + 1, j) + PB * expected(i, i + j);

	frac f = expected(1, 0);
	cout << (f.p * powmod(f.q, mod - 2) % mod) << endl;
	return 0;
}