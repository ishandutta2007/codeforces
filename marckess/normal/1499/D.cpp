#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 40000005;
int bs[MX];
ll c, d, x, res;

int fac (int n) {
	int res = 0;
	
	while (n > 1) {
		int p = bs[n];
		res++;
		
		while (n % p == 0)
			n /= p;
	}
	
	return res;
}

ll f (int g) {
	if ((x + d * g) % (g * c) == 0)
		return 1ll << fac((x + d * g) / (g * c));
	return 0;
}

void go (int i, ll acu, vi &p, vi &pw) {
	if (i == (int)p.size()) {
		res += f(acu);
		return;
	}
	
	forn (kk, pw[i] + 1) {
		go(i + 1, acu, p, pw);
		acu *= p[i];
	}
}

void solve () {
	cin >> c >> d >> x;
	
	vi p, pw;
	
	int _x = x;
	while (x > 1) {
		int y = bs[x], pot = 0;
		
		while (x % y == 0) {
			pot++;
			x /= y;
		}
		
		p.pb(y);
		pw.pb(pot);
	}
	x = _x;
	
	res = 0;
	go(0, 1, p, pw);
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}