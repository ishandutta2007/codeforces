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

const int MX = 200005;
int n, a[MX];
ll s, p;

void solve () {
	s = 0;
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}
	
	if (s % n) {
		cout << -1 << endl;
		return;
	}
	
	int res = 0;
	p = s / n;
	forn (i, n)
		if (a[i] > p)
			res++;
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}