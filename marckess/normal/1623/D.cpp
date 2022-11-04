// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1000000007;
int n, m;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void main_() {
	int x1, y1, x2, y2;
	ll p;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> p;
	
	int dx = 1, dy = 1;
	set<vi> st;
	
	ll x = 0, fac = 1, c = 0;
	p = p * pot(100, mod - 2) % mod;
	
	forn (i, 1e9) {
		if (x1 + dx < 1 || n < x1 + dx) dx = -dx;
		if (y1 + dy < 1 || m < y1 + dy) dy = -dy;
		
		if (st.count({x1, y1, dx, dy}))
			break;
		st.insert({x1, y1, dx, dy});
		
		if (x1 == x2 || y1 == y2) {
			(x += i * p % mod * fac) %= mod;
			(c += p * fac) %= mod;
			(fac *= 1 - p) %= mod;
		}
		
		x1 += dx;
		y1 += dy;
	}
	
	(c *= (ll)st.size()) %= mod;
	
	ll a = c * fac % mod * pot(pot(1 - fac, 2), mod - 2) % mod;
	ll b = x * pot(1 - fac, mod - 2) % mod;
	
	cout << MOD(a + b, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}