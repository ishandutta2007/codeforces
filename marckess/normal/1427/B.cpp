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

int n, k, res, x;
string s;
vi pos, a;

void solve () {
	cin >> n >> k >> s;
	
	res = x = 0;
	pos.clear();
	a.clear();
	
	forn (i, n) {
		if (s[i] == 'W') {
			res++;
			if (i && s[i - 1] == 'W') res++;
			
			if (pos.size() && pos.back() < i - 1) {
				a.pb(i - pos.back() - 1);
			}
			pos.pb(i);
		} else {
			x++;
		}
	}
	
	res += 2 * min(k, x);
	if (x == n && min(k, x)) res--;
	
	sort(all(a));
	
	for (int r : a) {
		if (k >= r) {
			k -= r;
			res++;
		}
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