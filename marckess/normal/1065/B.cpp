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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll n, m, x, y;

	cin >> n >> m;

	x = n;
	for (int i = 0; i < m; i++)
		x -= 2;

	cout << max(0ll, x) << " ";

	y = 0;
	while (y * (y - 1) / 2 < m) y++;

	cout << n - y << endl;

	return 0;
}