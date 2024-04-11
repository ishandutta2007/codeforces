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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, k;
string s;

void solve () {
	cin >> n >> k >> s;
	
	int l = n, r = 0;
	forn (i, n)
		if (s[i] == '*') {
			l = min(l, i);
			r = max(r, i);
		}
	
	int res = 1 + (l != r);
	
	while (r - l > k) {
		l += k;
		while (s[l] == '.')
			l--;
		res++;
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}