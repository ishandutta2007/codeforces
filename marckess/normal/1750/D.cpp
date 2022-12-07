#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 200005, mod = 998244353;
int n, m, a[MX];

ll cc (int x, int m) {
	vi p;
	
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			p.pb(i);
			while (x % i == 0)
				x /= i;
		}
	
	if (x > 1)
		p.pb(x);
	
	int cn = 0;
	
	forn (mk, (1 << p.size())) {
		int k = 1;
		
		forn (j, p.size())
			if (mk & (1 << j))
				k *= p[j];
		
		if (__builtin_popcount(mk) % 2)
			cn -= m / k;
		else
			cn += m / k;
	}
	
	return cn;
}

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
	
	forr (i, 1, n - 1) {
		if (a[i - 1] % a[i]) {
			cout << 0 << endl;
			return;
		}
	}
	
	ll res = 1;
	forr (i, 1, n - 1)
		(res *= cc(a[i - 1] / a[i], m / a[i])) %= mod;
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}