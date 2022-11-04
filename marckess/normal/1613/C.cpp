
// Problem : C. Poisoned Dagger
// Contest : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1613/problem/C
// Memory Limit : 256 MB
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

const int MX = 105;
int n;
ll a[MX], h;

ll esPos (ll m) {
	ll x = h;
	
	forn (i, n) {
		if (i + 1 < n && a[i + 1] - a[i] < m)
			x -= a[i + 1] - a[i];
		else
			x -= m;
		x = max(x, 0ll);
	}
	
	return x <= 0;
}

void main_() {
	cin >> n >> h;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	ll l = 1, r = h, rep = 60;
	while (rep--) {
		ll m = (l + r) / 2;
		if (esPos(m)) r = m;
		else l = m;
	}
	
	cout << r << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}