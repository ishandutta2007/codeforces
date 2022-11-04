// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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
int n;
ll a[MX], b[MX], c[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> b[i];
	
	forn (i, n)
		c[i] = b[(i - 1 + n) % n] - b[i];
	
	ll r = MOD(c[0], n);
	forn (i, n) {
		if (r != MOD(c[i], n)) {
			cout << "NO" << endl;
			return;
		}
		a[i] = (c[i] - r) / n;
	}
	
	ll x = 0, t = 1ll * n * (n + 1) / 2;
	forn (i, n)
		x += (n - i) * a[i];
	
	if ((b[n - 1] - x) % t) {
		cout << "NO" << endl;
		return;
	}
	
	forn (i, n)
		a[i] += (b[n - 1] - x) / t;
		
	forn (i, n)
		if (a[i] < 1 || 1000000000 < a[i]) {
			cout << "NO" << endl;
			return;
		}
	
	cout << "YES" << endl;
	forn (i, n)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}