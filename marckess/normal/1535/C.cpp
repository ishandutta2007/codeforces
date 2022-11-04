#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s;
int a, b, c, d;

void solve () {
	cin >> s;
	a = b = c = d = -1;
	
	ll res = 0;
	forn (i, s.size()) {
		if (s[i] == '1') {
			if (i % 2) a = i;
			else b = i;
		}
		
		if (s[i] == '0') {
			if (i % 2) c = i;
			else d = i;
		}
		
		if (max(a, b) > max(c, d)) {
			if (a > b)
				res += i - max(b, c);
			else
				res += i - max(a, d);
		} else {
			if (c > d)
				res += i - max(d, a);
			else
				res += i - max(c, b);
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}