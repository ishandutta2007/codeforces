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

const int MX = 2000005;
int n, m, q, t[MX], x[MX], off[2], res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	forn (i, q) {
		cin >> t[i];
		if (t[i] == 1) cin >> x[i];
	}

	forn (i, q) {
		if (t[i] == 1) {
			off[0] += x[i];
		} else {
			if (off[0] & 1) off[0]--;
			else off[0]++;
		}

		if (off[0] >= n) off[0] -= n;
		if (off[0] < 0) off[0] += n; 
	}

	forn (i, q) {
		if (t[i] == 1) {
			off[1] += x[i];
		} else {
			if (off[1] & 1) off[1]++;
			else off[1]--;
		}

		if (off[1] >= n) off[1] -= n;
		if (off[1] < 0) off[1] += n;
	}

	forn (i, n) {
		res[(i + off[i & 1]) % n] = i + 1;
	}

	forn (i, n) cout << res[i] << " ";
	cout << endl;

	return 0;
}