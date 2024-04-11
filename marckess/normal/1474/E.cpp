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

const int MX = 100005;
int n, p[MX];
vii res;
ll s;

ll sq (ll n) {
	return n * n;
}

void solve () {
	cin >> n;
	res.clear();
	s = 0;
	
	p[1] = n / 2 + 1, p[n] = n / 2;
	for (int i = n / 2; i > 1; i--) {
		p[i] = i - 1;
		res.emplace_back(i, n);
		s += sq(n - i);
	}
	
	for (int i = n / 2 + 1; i < n; i++) {
		p[i] = i + 1;
		res.emplace_back(i, 1);
		s += sq(i - 1);
	}
	
	res.emplace_back(1, n);
	s += sq(n - 1);
	
	cout << s << endl;
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
	cout << res.size() << endl;
	for (ii &p : res)
		cout << p.fi << " " << p.se << endl;
		
	for (ii &x : res) {
		s -= sq(x.fi - x.se);
		assert(p[x.se] = x.fi);
		swap(p[x.fi], p[x.se]);
	}
	
	assert(!s);
	for (int i = 1; i <= n; i++)
		assert(p[i] == i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}