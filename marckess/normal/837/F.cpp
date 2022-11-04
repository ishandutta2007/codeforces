#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll a[MX], k;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

bool des (ld f, ld a, ld b, ld k) {
	ld x = (2 * k / a) * b;
	return f > x;
}

ll mul (ll f, ll a, ll b) {
	ll d = gcd(a, b);
	a /= d;
	f /= b / d;
	return a * f;
}

bool esPos (ll i) {
	ll f = 1, x = i + n - 1, sum = 0;

	for (int j = n; j > 0; j--) {
		if (a[j] && f == -1) return -1;

		if (a[j] && des(a[j], f, 1, k)) return 1;
		sum += a[j] * f;
		if (sum >= k) return 1;

		if (f != -1 && des(f, x-j+1, x-j-i+2, k)) f = -1;
		if (f != -1) f = mul(f, x-j+1, x-j-i+2);
	}
	
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] >= k) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll i = 1, j = k, rep = 64;

	while (rep--) {
		ll m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;

	return 0;
}