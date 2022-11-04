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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
priority_queue<ii> pq;

void solve () {
	cin >> n;
	pq.emplace(n, 0);

	int i = 0;
	while (pq.size()) {
		int l = -pq.top().se;
		int sz = pq.top().fi;
		int r = l + sz - 1;
		pq.pop();

		if (!sz) continue;

		int m;
		if (sz % 2) m = (l + r) / 2;
		else m = (l + r - 1) / 2;

		a[m] = ++i;

		if (l < m) pq.emplace(m - l, -l);
		if (m < r) pq.emplace(r - m, -(m + 1));	
	}

	forn (i, n) cout << a[i] << " ";
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