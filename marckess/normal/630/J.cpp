#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll x = 1, n;

	for (ll i = 2; i <= 10; i++)
		x = x * i / gcd(x, i);
		
	cin >> n;
	cout << n / x << endl;

	return 0;
}