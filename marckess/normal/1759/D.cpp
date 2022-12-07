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

ll n, m;
ll f (ll n) {
	int res = 0;
	while (n % 10 == 0) {
		n /= 10;
		res++;
	}
	return res;
}

void main_() {
	cin >> n >> m;
	
	ll res = n * m;
	int a = f(n * m);
	for (ll x = 1; x <= m; x *= 2)
	for (ll y = 1; x * y <= m; y *= 5) {
		ll k = (x * y) * (m / (x * y));
		int b = f(n * k);
		if (b > a) {
			a = b;
			res = n * k;
		} else if (b == a && n * k > res) {
			res = n * k;
		}
	}
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