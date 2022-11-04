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

const int MX = 400005;
int n, a[MX];
ll res;

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = a[n + 1] = 0;
	
	res = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			int x = max(a[i - 1], a[i + 1]);
			res += a[i] - x;
			a[i] = x;
		}
	
	for (int i = 1; i <= n + 1; i++)
		res += abs(a[i] - a[i - 1]);
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}