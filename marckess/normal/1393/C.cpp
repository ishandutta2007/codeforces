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

const int MX = 100005;
int n, a[MX], cn[MX], mx, tot;

void solve () {
	memset(cn, 0, sizeof(cn));
	cin >> n;
	mx = 0, tot = 0;

	forn (i, n) {
		cin >> a[i];
		int k = ++cn[a[i]];

		if (k > mx) {
			mx = k;
			tot = 1;
		} else if (k == mx) {
			tot++;
		}
	}

	int i = 1, j = n, rep = 20;

	while (rep--) {
		int m = (i + j + 1) / 2;

		if (n / m >= mx || (n / m + 1 == mx && n % m >= tot)) i = m;
		else j = m;
	}

	cout << i - 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}