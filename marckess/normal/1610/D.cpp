
// Problem : D. Not Quite Lee
// Contest : Codeforces - Codeforces Global Round 17
// URL : https://codeforces.com/contest/1610/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int MX = 200005, mod = 1000000007;
int n, a[MX], p[MX];

ll pot (ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		
		ll x = a[i], f = 0;
		while (x % 2 == 0) {
			x /= 2;
			f++;
		}
		p[f]++;
	}
	
	ll res = 0, acu = 0;
	
	for (int i = 30; i > 0; i--) {
		if (p[i]) {
			(res += (pot(2, p[i] - 1) - 1) * pot(2, acu)) %= mod;
			acu += p[i];
		}
	}
	
	(res += (pot(2, p[0]) - 1) * pot(2, acu)) %= mod;
	
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}