#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) emplace_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
ll n, p, k, a[MX], res = 0;
map<int, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		ll y = a[i] * a[i] % p;
		ll z = y * y % p;
		res += mp[MOD(z - k * a[i], p)]++;
	}

	cout << res << endl;

	return 0;
}