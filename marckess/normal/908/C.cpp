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

const int MX = 1005;
int n, r, x[MX];
ld res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> r;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	for (int a = 0; a < n; a++) {
		ld i = r, j = 1e7, rep = 60;
		while (rep--) {
			ld m = (i + j) / 2;
			int f = 1;
			for (int b = 0; b < a; b++) {
				ld t = min(m, res[b]);
				f &= hypot(x[a] - x[b], t - m) > 2 * r;
			}
			if (f) j = m;
			else i = m;
		}
		res[a] = i;
	}

	cout << fixed << setprecision(8);
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}