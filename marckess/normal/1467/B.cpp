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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], pre[MX], suf[MX];

int f (int i) {
	if (i <= 1 || i >= n) return 0;
	if (a[i] > a[i - 1] && a[i] > a[i + 1]) return 1;
	if (a[i] < a[i - 1] && a[i] < a[i + 1]) return 1;
	return 0;
}

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		pre[i] += f(i - 1);
	}
	
	suf[n + 1] = 0;
	for (int i = n; i; i--) {
		suf[i] = suf[i + 1];
		suf[i] += f(i + 1);
	}
	
	int res = n;
	for (int i = 1; i <= n; i++) {
		int p = pre[i - 1] + suf[i + 1], x = 1e9, y = 1e9, z;
		int aux = a[i];
		
		if (i > 1) {
			a[i] = a[i - 1];
			x = f(i - 1) + f(i) + f(i + 1);
		}
		
		if (i < n) {
			a[i] = a[i + 1];
			y = f(i - 1) + f(i) + f(i + 1);
		}
		
		a[i] = aux;
		z = f(i - 1) + f(i) + f(i + 1);
		
		res = min(res, p + min({x, y, z}));
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