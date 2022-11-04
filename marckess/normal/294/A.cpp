#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], m;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;

		a[x - 1] += y - 1;
		a[x + 1] += a[x] - y;
		a[x] = 0; 
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << endl;

	return 0;
}