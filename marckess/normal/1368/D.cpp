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

const int MX = 200005;
int n, a[MX], b[MX];
ll res;

void solve () {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		forn (j, 20)
			if (a[i] & (1 << j))
				b[j]++;
	}

	forn (i, n) {
		ll p = 0;
		forn (j, 20)
			if (i < b[j])
				p += 1 << j;
		res += p * p;
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}