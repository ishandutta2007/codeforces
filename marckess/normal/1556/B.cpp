
// Problem : B. Take Your Places!
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/B
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

void solve () {
	vii a, b;
	int n;
	
	cin >> n;
	forn (i, n) {
		int x;
		cin >> x;
		if (x % 2 == 0) a.emplace_back(x, i);
		else b.emplace_back(x, i);
	}
	
	if (abs(int(a.size()) - int(b.size())) > 1) {
		cout << -1 << endl;
		return;
	}
	
	ll res = 1e18;
	if (a.size() >= b.size()) {
		ll p = 0;
		
		forn (i, n) {
			if (i % 2 == 0)
				p += abs(a[i / 2].se - i);
			else
				p += abs(b[i / 2].se - i);
		}
		
		res = min(res, p / 2);
	}
	
	if (b.size() >= a.size()) {
		ll p = 0;
		
		forn (i, n) {
			if (i % 2 == 0)
				p += abs(b[i / 2].se - i);
			else
				p += abs(a[i / 2].se - i);
		}
		
		res = min(res, p / 2);
	}
	
	if (res == 1e18) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}