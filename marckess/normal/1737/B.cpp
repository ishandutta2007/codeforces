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

ll prec_sqrt (ll n) {
	ll s = sqrt(n);
	forr (i, max(0ll, s - 10), s + 10)
		if (s * s > n)
			return s - 1;
	return s;
}

ll f (ll n) {
	if (!n) return 0;
	
	ll res = 0;
	ll k = prec_sqrt(n);
	
	res = 3 * (k - 1);
	res += n / k - (k * k - 1) / k;
	
	return res;
}

void main_() {
	ll l, r;
	cin >> l >> r;
	cout << f(r) - f(l - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}