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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n;
ll a[MX];

ll f (int i, int j, int off) {
	ll x = 0, y = 0, mn = 1e9;

	for (int k = i; k <= j; k++) {
		x++;
		mn = min(mn, a[k]);
	}

	int ant = -1;
	
	for (int k = i; k <= j; k++) {
		if (a[k] == mn) {
			if (ant != -1)
				y += f(ant, k - 1, mn);
			ant = -1;
		} else if (ant == -1) {
			ant = k;
		}
	}

	if (ant != -1) y += f(ant, j, mn); 
	y += mn - off;

	return min(x, y);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	cout << f(0, n - 1, 0) << endl;	
	
	return 0;
}