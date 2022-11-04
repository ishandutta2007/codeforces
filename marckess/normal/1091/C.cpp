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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll tri (ll n) {
	return n * (n - 1) / 2;
}

ll n;
vector<ll> res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0) {
			res.pb((n / i) * tri(i) + i);
			if (i * i < n) res.pb(i * tri(n / i) + n / i);
		}

	sort(all(res));
	res.erase(unique(all(res)), res.end());

	for (ll x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}