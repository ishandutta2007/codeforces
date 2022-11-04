#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
ll n, m;

ll s (ll n) {
	return n * (n + 1) / 2;
}

void solve () {
	cin >> n >> m;

	ll x = (n - m) / (m + 1);
	ll a = (n - m) % (m + 1);
	ll b = (m + 1) - a;

	cout << s(n) - (s(x + 1) * a + s(x) * b) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}