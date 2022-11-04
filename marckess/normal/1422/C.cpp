#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 100005, mod = 1000000007;
string s;
ll res;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void solve () {
	cin >> s;
	int n = s.size();
	
	for (ll i = 0, acu = 0, j = n - 1; i < n - 1; i++, j--) {
		acu = ((acu * 10) + (s[i] - '0')) % mod;
		(res += acu * (pot(10, j) - 1) % mod * (pot(10 - 1, mod - 2))) %= mod; 
	}
	
	reverse(all(s));
	
	for (ll i = 0, acu = 0, pw = 1, j = n - 1; i < n - 1; i++, j--, (pw *= 10) %= mod) {
		(acu += (s[i] - '0') * pw) %= mod;
		(res += acu * j) %= mod;
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}