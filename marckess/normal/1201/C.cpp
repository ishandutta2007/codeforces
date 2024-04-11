#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 200005;
int n, k, a[MX];

bool esPos (int m) {
	ll s = 0;

	for (int k = n / 2; k < n; k++)
		if (a[k] < m)
			s += m - a[k];

	return s <= k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	forn (i, n) cin >> a[i];
	sort(a, a+n);

	int i = 0, j = 2e9 + 5, rep = 35;
	while (rep--) {
		int m = (i + ll(j)) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}

	if (esPos(j)) cout << j << endl;
	else cout << i << endl;
 
	return 0;
}