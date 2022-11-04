#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, x, y, a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	forn (i, n) {
		cin >> a[i];
		if (a[i]) y++;
		else x++;
	}
	
	while (q--) {
		int t, k;
		cin >> t >> k;
		if (t == 1) {
			k--;
			if (a[k]) x++, y--;
			else x--, y++;
			a[k] = 1 - a[k];
		} else {
			if (k <= y) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	
	return 0;
}