#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

ll n, p, w, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p >> w >> d;

	if (p / n > w) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i <= w; i++)
		if ((p - i * d) % w == 0) {
			ll j = (p - i * d) / w;
			if (j >= 0 && i + j <= n) {
				cout << j << " " << i << " " << n - i - j << endl;
				return 0;
			}
		}

	cout << -1 << endl;

	return 0;
}