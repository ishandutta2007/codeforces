// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 55;
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	if (n % 2) {
		cout << "Mike" << endl;
		return;
	}
	
	ll x = 1e18, y = 1e18;
	forn (i, n) {
		if (i % 2 == 0) {
			x = min(x, 1ll * n * a[i] + i);
		} else {
			y = min(y, 1ll * n * a[i] + i);
		}
	}
	
	if (x < y) cout << "Joe" << endl;
	else cout << "Mike" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}