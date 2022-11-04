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

const int MX = 1000005;
int n, q, a[MX], k[MX];

bool esPos (int m) {
	int x = 0, y = 0;

	forn (i, n) {
		if (a[i] < m) x++;
		else y++;
	}

	forn (i, q) {
		if (k[i] > 0) {
			if (k[i] < m) x++;
			else y++;
		} else {
			if (-k[i] <= x) x--;
			else y--;
		}
	}

	return y;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	forn (i, n) cin >> a[i];
	forn (i, q) cin >> k[i];

	int i = 1, j = n, rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}
	
	if (esPos(i)) cout << i << endl;
	else cout << 0 << endl; 

	return 0;
}