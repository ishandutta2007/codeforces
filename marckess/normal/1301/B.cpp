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

const int MX = 100005;
int n, a[MX], mn, mx;

void solve () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	mn = mx = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != -1) continue;

		if (i && a[i-1] != -1) {
			if (mx == -1) {
				mx = a[i-1];
				mn = a[i-1];
			} else {
				mx = max(mx, a[i-1]);
				mn = min(mn, a[i-1]);
			}
		}

		if (i + 1 < n && a[i+1] != -1) {
			if (mx == -1) {
				mx = a[i+1];
				mn = a[i+1];
			} else {
				mx = max(mx, a[i+1]);
				mn = min(mn, a[i+1]);
			}	
		}
	}

	if (mx == -1) {
		cout << 0 << " " << 0 << endl;
		return;
	}

	int k = (mx + mn) / 2, m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1)
			a[i] = k;
		if (i)
			m = max(m, abs(a[i] - a[i-1]));
	}
	cout << m << " " << k << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}