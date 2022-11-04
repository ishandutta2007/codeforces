#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

int n;
string s, t;

void main_() {
	cin >> n >> s >> t;
	
	vi a, b;
	
	int cn = 0;
	forn (i, n) {
		if (!i || s[i] == s[i - 1])
			cn++;
		else {
			a.pb(cn);
			cn = 1;
		}
	}
	a.pb(cn);
	
	cn = 0;
	forn (i, n) {
		if (!i || t[i] == t[i - 1])
			cn++;
		else {
			b.pb(cn);
			cn = 1;
		}
	}
	b.pb(cn);
	
	if (a.size() != b.size() || s[0] != t[0]) {
		cout << -1 << endl;
		return;
	}
	
	ll res = 0;
	forn (i, (int)a.size() - 1) {
		if (a[i] > b[i]) {
			res += a[i] - b[i];
			a[i + 1] += a[i] - b[i];
		} else {
			res += b[i] - a[i];
			b[i + 1] += b[i] - a[i];
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}