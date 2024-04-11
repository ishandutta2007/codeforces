
// Problem : C. Jury Meeting
// Contest : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1569/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 200005, mod = 998244353;
int n;
vi a, b;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll fac (int n) {
	ll res = 1;
	for (int i = 2; i <= n; i++)
		(res *= i) %= mod;
	return res;
}

ll comb (int n, int k) {
	if (n < k || n < 0 || k < 0) return 0;
	return fac(n) * pot(fac(k), mod - 2) % mod * pot(fac(n - k), mod - 2) % mod;
}

void main_() {
	cin >> n;
	
	a.resize(n);
	forn (i, n)
		cin >> a[i];
	sort(all(a));
	
	b = a;
	b.erase(unique(all(b)), b.end());
	
	if (b.size() == 1) {
		cout << fac(n) << endl;
		return;
	}
	
	int x = count(all(a), *(b.end() - 2));
	int y = count(all(a), *(b.end() - 1));
	
	if (y > 1) {
		cout << fac(n) << endl;
		return;
	}
	
	if (*(b.end() - 2) + 1 < *(b.end() - 1)) {
		cout << 0 << endl;
		return;
	}
	
	cout << comb(n, x + y) * fac(n - (x + y)) % mod * fac(x) % mod * x % mod << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}