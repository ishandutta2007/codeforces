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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, a[MX];
ll s[MX];
set<ll> st;

void solve (int i, int j) {
	if (i > j) return;
	
	st.insert(s[j] - s[i - 1]);
	
	int m = (a[i] + a[j]) / 2;
	int k = upper_bound(a + i, a + j + 1, m) - a;
	k--;
	
	if (i <= k && k < j) {
		solve(i, k);
		solve(k + 1, j);
	}
}

void solve () {
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
		s[i] = a[i] + s[i - 1];
	
	st.clear();
	solve(1, n);
	
	while (q--) {
		int x;
		cin >> x;
		if (st.count(x)) cout << "Yes" << endl;
		else cout << "No" << endl;	
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}