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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2000005;
ll n, k;
ll ft[MX];

void update (int i, int k) {
	i++;
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i) {
	ll s = 0;
	i++;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ll query (int a, int b) {
	if (a > b) swap(a, b);
	return query(b) - query(a-1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll x = 1;

	cin >> n >> k;
	k = min(k, n - k);
	for (int i = 0, j = 0; i < n; i++, (j += k) %= n) {
		x++;
		x += query(j, j + k);
		x += query(j + n, j + n - k + 1);
		if (i + 1 == n) x--;
		cout << x << " ";
		update(j, 1);
		update(j+n, 1);
	}
	cout << endl;

	return 0;
}