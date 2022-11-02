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

vi primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

bool bf(ll x)
{
	for (ll y = 2; y * y <= x; y++) {
		ll z = y * y;
		while (z < x) z *= y;
		if (x == z)
			return true;
	}
	return false;
}


ll runBF(ll x)
{
	ll ret = 0;
	for (ll y = 2; y <= x; y++) {
		if (bf(y)) {
			ret++;
			cout << y << " ";
		}
	}
	cout << endl;
	return ret;
}

ll powi(ll b, int e)
{
	ll r = 1;
	while (e) {
		if (e & 1) r *= b;
		e >>= 1;
		if (e == 0) return r;
		b = b * b;
	}
	return r;
}

// returns b^e <= x
bool goodRatio(ll x, ll b, int e)
{
	double y = x;
	REP(i, e) {
		y /= b;
		if (y < 0.99) return false;
	}

	// x / b^e >= 0.99 <=> 0.99 * b^e <= x
	return powi(b, e) <= x;
}

void subsets(ll &ret, int prod, ll x, int logx, int idx, int n, bool oddsize)
{
	if (idx == n) {
		// assert(prod <= x);
		// cerr << "Taking " << x << "^" << (1.0 / prod) << endl;
		ll inc = x;
		if (prod > 1) {
			if (prod == 2) {
				inc = sqrt(x + 0.5);
			} else {
				inc = (ll) pow(x, 1.0 / prod - 1e-15);
				while (goodRatio(x, inc + 1, prod)) inc++;
			}
		}


//		while (inc < 0 || powi(inc + 1, prod) <= x) inc++;

//		cerr << prod << " -> " << inc << ", \t";
//		cerr << "Try set " << prod << "(" << x << ") = " << inc << endl;
//		cerr << inc << "^" << prod << ": " << powi(inc, prod)  << " VS " <<  x << endl;

		assert(powi(inc, prod) <= x);
//		assert(powi(inc + 1, prod) > x);

		inc--;

		if (oddsize) ret -= inc;
		else ret += inc;

		return;
	}
	subsets(ret, prod, x, logx, idx + 1, n, oddsize);

	if (prod * primes[idx] > logx)
		return;

	subsets(ret, prod * primes[idx], x, logx, idx + 1, n, !oddsize);
}

ll run(ll x)
{
	ll ret = 0;

	int log2i = 0;
	while (1LL << (log2i + 1) <= x) log2i++;

	int nrp = 0;
	while (nrp < (int) primes.size() && primes[nrp] <= log2i)
		nrp++;
	
	// cout << "Checking: " << nrp << endl;

	subsets(ret, 1LL, x, log2i, 0, nrp, false);
//	cout << endl;
	return ret;
}

int main()
{
/*
	for (int i = 2; i <= 100; i++) {
		bool isp = true;
		for (int j = 2; j * j <= i; j++)
			isp &= i % j != 0;
		if (isp) cout << i << ", ";
	}
	cout << endl;
	return 0;
	*/

/*
#ifdef DEBUG
	while (true) {
		int x;
		cin >> x;
		ll a1 = run(x), a2 = x - 1 - runBF(x);
		cout << "Fast way: " << a1 << endl;
		cout << "Slow way: " << a2 << endl;
	}
#endif
*/

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		ll X;
		cin >> X;
		ll Y = run(X);
		// cout << (X - Y - 1) << endl;
		cout << Y << endl;
	}

	return 0;
}