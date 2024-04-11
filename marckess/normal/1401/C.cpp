#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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


const int MX = 100005;
int n, a[MX], mn, bs[MX];
vi res, b;

void solve () {
	cin >> n;
	mn = 1e9 + 5;
	forn (i, n) {
		cin >> a[i];
		mn = min(mn, a[i]);
		bs[i] = 0;
	}

	b.clear();
	res.resize(n);
	forn (i, n) if (a[i] % mn == 0) {
		bs[i] = 1;
		b.pb(a[i]);
	} else {
		bs[i] = 0;
		res[i] = a[i];
	}

	sort(all(b));
	for (int i = 0, j = 0; i < n; i++) if (bs[i]) {
		res[i] = b[j++];
	}

	forn (i, n - 1) if (res[i] > res[i + 1]) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}