
// Problem : D. X-Magic Pair
// Contest : Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1612/problem/D
// Memory Limit : 512 MB
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll a, b, x;

int f;
void gcd (ll a, ll b) {
	if (a > b) swap(a, b);
	
	if (a == x || b == x) {
		f = 1;
		return;
	}
	
	if (!a) return;
	
	ll r = b % a;
	
	if (r <= x && x <= b) {
		if ((x - r) % a == 0) {
			f = 1;
			return;
		}
	}
	
	gcd(r, a);
}

void main_() {
	cin >> a >> b >> x;
	
	f = 0;
	gcd(a, b);
	
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}