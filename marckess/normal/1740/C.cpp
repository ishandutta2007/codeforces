#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	ll res = 0, x = -1e9, y = -1e9;
	
	for (int i = n - 2; i >= 0; i--) {
		res = max({res, x - a[i], y + a[i + 1] - 2 * a[i]});
		x = max(x, 2 * a[i + 1] - a[i]);
		y = max(y, a[i + 1]);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}