#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005;
int n, x[MX], y[MX], q[MX], mn, res[MX];

void solve () {
	cin >> n;
	forn (i, n) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i])
			swap(x[i], y[i]);
	}
	
	iota(q, q + n, 0);
	sort(q, q + n, [&] (int i, int j) {
		if (x[i] == x[j]) return y[i] > y[j];
		return x[i] < x[j];
	});
	fill(res, res + n, -1);
	
	mn = -1;
	forn (_, n) {
		int i = q[_];
		
		if (mn != -1 && y[mn] < y[i])
			res[i] = mn + 1;
		
		if (mn == -1 || y[i] < y[mn])
			mn = i;
	}
	
	forn (i, n) cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}