#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
int n, a[MX], cn[MX], res;

void solve () {
	cin >> n;
	
	forn (i, n) cn[i + 1] = 0;
	
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
		if (cn[i] > (n + 1) / 2) {
			cout << -1 << endl;
			return;
		}
	
	forn (i, n) cn[i + 1] = 0;
	
	cn[a[0]]++;
	cn[a[n - 1]]++;
	
	res = 0;
	
	forn (i, n - 1)
		if (a[i] == a[i + 1]) {
			cn[a[i]] += 2;
			res++;
		}
	
	for (int i = 1; i <= n; i++)
		if (cn[i] > res + 2) {
			cout << cn[i] - 2 << endl;
			return;
		}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
		
	return 0;
}