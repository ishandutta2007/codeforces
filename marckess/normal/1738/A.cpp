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
int n, a[MX], b[MX];
vi x, y;

void main_() {
	cin >> n;
	
	x.clear();
	y.clear();
	ll res = 0;
	
	forn (i, n) cin >> a[i];
	forn (i, n) {
		cin >> b[i];
		if (a[i]) x.pb(b[i]);
		else y.pb(b[i]);
		res += b[i];
	}
	
	sort(all(x), greater<int>());
	sort(all(y), greater<int>());
	
	forn (i, min(x.size(), y.size()))
		res += x[i] + y[i];
	
	if (x.size() == y.size())
		res -= min(x.back(), y.back());
	
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