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
int a, b, k, x[MX], y[MX], ca[MX], cb[MX];
ll res;

void solve () {
	cin >> a >> b >> k;
	
	for (int i = 1; i <= a; i++) ca[i] = 0;
	for (int i = 1; i <= b; i++) cb[i] = 0;
	
	forn (i, k) {
		cin >> x[i];
		ca[x[i]]++;
	}
	
	forn (i, k) {
		cin >> y[i];
		cb[y[i]]++;
	}
	
	res = 0;
	forn (i, k)
		res += k - ca[x[i]] - cb[y[i]] + 1;
	cout << res / 2 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}