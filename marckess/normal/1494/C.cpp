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

int n, m;

int solve (vi a, vi x) {
	sort(all(a));
	sort(all(x));
	vi ex(a.size());
	
	int res = 0, off = 0, i = 0, l = 0, r = 0;
	
	while (i < a.size()) {
		while (l < x.size() && x[l] < a[i]) l++;
		if (l < x.size() && x[l] == a[i]) ex[i] = 1, off++;
		i++;
	}
	i = l = 0;
	
	while (l < x.size()) {
		while (i < a.size() && a[i] - i <= x[l] - 1) {
			off -= ex[i];
			i++;
		}
		
		while (r < x.size() && x[r] - x[l] < i) {
			r++;
		}
		
		res = max(res, r - l + off);
		l++;
		r = max(r, l);
	}
	
	return res;
}

void solve () {
	cin >> n >> m;
	
	vi a, b, x, y;
	
	forn (i, n) {
		int in;
		cin >> in;
		if (in < 0) a.pb(abs(in));
		else b.pb(abs(in)); 
	}
	
	forn (i, m) {
		int in;
		cin >> in;
		if (in < 0) x.pb(abs(in));
		else y.pb(abs(in));
	}
	
	cout << solve(a, x) + solve(b, y) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}