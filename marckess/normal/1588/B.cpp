
// Problem : B. Guess the Permutation
// Contest : Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL : https://codeforces.com/contest/1588/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

// #define endl '\n'
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

ll query (ll l, ll r) {
	cout << "? " << l << " " << r << endl;
	ll res;
	cin >> res;
	if (res == -1) exit(0);
	return res;
}

ll f (ll n) {
	ll i = 0, j = 1e9+5, rep = 30;
	
	while (rep--) {
		ll m = (i + j) / 2;
		
		if (m * (m + 1) / 2 >= n) j = m;
		else i = m;
	}
	
	if (j * (j + 1) / 2 == n) return j;
	return -1;
}

void main_() {
	ll n;
	cin >> n;
	
	ll l = 1, r = n, tot = query(1, n);
	
	while (l < r) {
		ll m = (l + r) / 2;
		ll d = query(1, m);
		
		if (d == tot) r = m;
		else l = m + 1;
	}
	
	ll k = r;
	ll j = k - (query(1, k) - query(1, k - 1));
	ll i = (j - 1) - f(tot - query(j, k));
	
	cout << "! " << i << " " << j << " " << k << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}