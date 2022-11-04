
// Problem : C. Chat Ban
// Contest : Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1612/problem/C
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll tr (ll n) {
	return n * (n + 1) / 2;
}

void main_() {
	ll k, x;
	cin >> k >> x;
	
	if (k * (k + 1) / 2 >= x) {
		ll i = 0, j = k, rep = 30;
		
		while (rep--) {
			ll m = (i + j) / 2;
			if (tr(m) >= x) j = m;
			else i = m;
		}
		
		cout << j << endl;
	} else {
		x -= k * (k + 1) / 2;
		
		ll i = 0, j = k - 1, rep = 30;
		while (rep--) {
			ll m = (i + j) / 2;
			if (tr(k - 1) - tr(k - 1 - m) >= x) j = m;
			else i = m;
		}
		
		cout << k + j << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}