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

const int MX = 1005;
int n, m;
vi a, b, c, d;
bitset<MX * MX> bs[MX];

pair<vi, vi> read (int &n) {
	cin >> n;
	
	vi a(n + 1);
	int s = 0;
	bs[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		bs[i] = bs[i - 1] | (bs[i - 1] << a[i]);
	}
	
	if (s % 2 || !bs[n][s / 2]) return {};
	
	vi ra, rb;
	s /= 2;
	for (int i = n; i; i--) {
		if (bs[i - 1][s]) rb.pb(-a[i]);
		else {
			ra.pb(a[i]);
			s -= a[i];
		}
	}
	
	return {ra, rb};
}

void go (int f, vi a, vi b) {
	vii res = {{0, 0}};
	
	for (int i = 0, j = 0; i + j < n + m; i += f, j += 1 - f, f ^= 1) {
		res.pb(res.back());
		if (f) res.back().fi += a[i];
		else res.back().se += b[j];
	}
	
	res.pop_back();
	cout << "Yes" << endl;
	for (ii &r : res) 
		cout << r.fi << " " << r.se << endl;
}

void solve () {
	tie(a, b) = read(n);
	tie(c, d) = read(m);
	
	if (a.size() + b.size() != m || c.size() + d.size() != n) {
		cout << "No" << endl;
		return;
	}
	
	if (a.size() <= c.size()) {
		sort(all(a), greater<int>()); sort(all(b));
		sort(all(c)); sort(all(d), greater<int>());
		
		a.insert(a.end(), all(b));
		c.insert(c.end(), all(d));	
		
		go(1, a, c);
	} else {
		sort(all(a)); sort(all(b), greater<int>());
		sort(all(c), greater<int>()); sort(all(d));
		
		a.insert(a.end(), all(b));
		c.insert(c.end(), all(d));
		
		go(0, a, c);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}