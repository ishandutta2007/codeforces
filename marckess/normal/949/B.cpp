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

ll n, x;
int q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	while (q--) {
		cin >> x;
		if (x & 1) cout << (x + 1) / 2 << endl;
		else {
			ll d = n - x / 2;
			x += d;
			while ((x & 1) == 0) {
				d /= 2;
				x += d;
			}
			cout << (x + 1) / 2 << endl;
		}
	}

	return 0;
}