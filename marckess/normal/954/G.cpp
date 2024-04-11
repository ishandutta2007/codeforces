#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, r;
ll k, a[MX], b[MX];

bool esPos (ll m) {
	for (int i = 0; i < n; i++) b[i] = a[i];

	ll x = 0, i = 0, au = 0;
	for (int j = 0; j < n && j < i + r; j++) x += b[j];

	while (i < n) {
		if (i + r < n) x += b[i + r];
		if (x < m) {
			b[min(n-1, (int)i+r)] += m - x;
			au += m - x;
			x = m;
		}
		if (au > k) return 0;
		if (i - r >= 0) x -= b[i - r];
		i++;
	}

	//cout << m << " " << au << endl;
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> r >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	ll i = 0, j = 2e18, rep = 65;
	while (rep--) {
		ll m = (i+j)/2;
		if (esPos(m)) i = m;
		else j = m;
	}

	if (esPos(j)) cout << j << endl;
	else cout << i << endl;

	return 0;
}