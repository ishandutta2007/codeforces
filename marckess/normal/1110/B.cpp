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
int n, m, k, a[MX], b[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	forn (i, n) cin >> a[i];

	forn (i, n - 1) b[i] = a[i + 1] - a[i] - 1;
	sort(b, b + n - 1, greater<int>());

	int res = a[n - 1] - a[0] + 1;

	forn (i, k - 1)
		res -= b[i];
	cout << res << endl;

	return 0;
}