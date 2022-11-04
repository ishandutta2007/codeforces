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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, d;
void solve () {
	cin >> n >> d;
	for (int x = max(0, int(sqrt(d) - 1e5)); x <= min(d, int(sqrt(d) + 1e5)); x++) {
		int r = x + (d + x) / (x + 1);
		if (r <= n) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}