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

const int MX = 3005;
int n, k, a[MX];

int go (int x) {
	int mx = 0;
	forn (i, n) {
		int p = a[i] / x;
		if (!p) return 1e9;
		p = min(p, k);
		mx = max(mx, a[i] / p);
	}
	return mx - x;
}

void main_() {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	
	int res = 1e9;
	forr (x, 1, MX)
		res = min(res, go(x));
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