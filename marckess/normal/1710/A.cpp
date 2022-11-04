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

const int MX = 100005;
int n, m, k;
ll a[MX];

bool f (int n, int m) {
	vi v;
	forn (i, k) {
		int y = a[i] / n;
		if (y >= 2)
			v.pb(y);
	}
	
	ll acu = 0;
	sort(all(v), greater<int>());
	
	forn (i, v.size()) {
		acu += v[i] - 2;
		if (m - 2 * (i + 1) < 0) break;
		if (acu >= m - 2 * (i + 1))
			return 1;
	}
	
	return 0;
}

void main_() {
	cin >> n >> m >> k;
	forn (i, k)
		cin >> a[i];
	
	if (f(n, m) || f(m, n)) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}