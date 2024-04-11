#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef complex<double> cd;
typedef vector<cd> vc;
const double pi = acos(-1.0l);

int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}

void fft (vc & x, int inv) {
	inv *= -1;
	int n = x.size();

	for (int i = 1, j = 0; i < n - 1; i++) {
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		if (i < j) swap(x[i], x[j]);
	}
	
	vc wp(n >> 1);
	for (int k = 1; k < n; k <<= 1) {
		for (int j = 0; j < k; j++)
			wp[j] = polar(1.0, pi * j / k * inv);

		for (int i = 0; i < n; i += k << 1) {
			for(int j = 0; j < k; ++j) {
				cd t = x[i + j + k] * wp[j];
				x[i + j + k] = x[i + j] - t;
				x[i + j] += t;
			}
		}
	}

	if (inv == 1)
		for (int i = 0; i < n; ++i)
			x[i] /= n;
}

const int base = 10000;

void mul (vc &a, vc b){
	int sz = a.size() + b.size() - 1;
	int size = nearestPowerOfTwo(sz);
	a.resize(size), b.resize(size);

	fft(a, 1), fft(b, 1);
	for(int i = 0; i < size; i++)
		a[i] *= b[i];
	
	fft(a, -1);
	
	sz = 0;
	for (ll i = 0, c = 0; i < a.size() || c; i++) {
		if (i == a.size()) a.pb(0);
		ll x = a[i].real() + 0.5;

		x += c;
		c = x / base;
		x %= base;
		if (x) sz = max(sz, (int)i + 1);

		a[i] = x;
	}
	sz = max(sz, 1);

	a.resize(sz);
}

void sq (vc &a) {
	int sz = 2 * a.size() - 1;
	int size = nearestPowerOfTwo(sz);
	
	a.resize(size);
	
	fft(a, 1);
	for(int i = 0; i < size; i++)
		a[i] *= a[i];
	fft(a, -1);
	
	sz = 0;
	for (ll i = 0, c = 0; i < a.size() || c; i++) {
		if (i == a.size()) a.pb(0);
		ll x = a[i].real() + 0.5;

		x += c;
		c = x / base;
		x %= base;
		if (x) sz = max(sz, (int)i + 1);

		a[i] = x;
	}
	sz = max(sz, 1);

	a.resize(sz);
}

void mul (vi &a, int k) {
	for (int i = 0, c = 0; i < a.size() || c; i++) {
		if (i == a.size()) a.pb(0);
		a[i] = a[i] * k + c;
		c = a[i] / base;
		a[i] %= base;
	}
}

string in;
vi n, p;
int res;

bool leq (const vi &a, const vi &b) {
	if (a.size() < b.size()) return 1;
	if (a.size() > b.size()) return 0;

	for (int i = int(a.size()) - 1; i >= 0; i--) {
		if (a[i] < b[i]) return 1;
		if (a[i] > b[i]) return 0;
	}

	return 1;
}

vi pot (int p) {
	vc b = {3}, res = {1};
	for (int i = 0; p; i++, p /= 2, sq(b)) if (p & 1) mul(res, b);

	vi ret;
	for (cd &x : res)
		ret.pb(x.real());
	return ret;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> in;
	int sz = in.size();

	if (in == "1" || in == "2" || in == "3") {
		cout << in << endl;
		return 0;
	}

	reverse(all(in));
	while (in.size() % 4) in.pb('0');
	for (int i = 0; i < in.size(); i += 4)
		n.pb(1000 * (in[i + 3] - '0') + 100 * (in[i + 2] - '0') + 10 * (in[i + 1] - '0') + (in[i] - '0'));
	
	int res = sz * (log2(10) / log2(3)) - 4;
	res = max(res, 0);
	vi ant = pot(res);

	res++;
	p = ant;
	mul(p, 3);
	
	vi nex = p;
	mul(nex, 3);

	while (leq(nex, n)) {
		ant = p;
		p = nex;
		mul(nex, 3);
		res++;
	}

	if (leq(n, p)) {
		cout << 3 * res << endl;
		return 0;
	}

	mul(ant, 4);
	if (leq(n, ant)) {
		cout << 3 * res + 1 << endl;
		return 0;
	}

	mul(p, 2);
	if (leq(n, p)) {
		cout << 3 * res + 2 << endl;
		return 0;
	}

	cout << 3 * res + 3 << endl;

	return 0;
}