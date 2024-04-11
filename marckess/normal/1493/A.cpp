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

int n, k;
void solve () {
	cin >> n >> k;
	
	vi res;
	for (int i = k - 1; i > 0; i--) {
		if (res.size() && res.back() + i <= k)
			break;
		res.pb(i);
	}
		
	for (int i = k + 1; i <= n; i++)
		res.pb(i);
	
	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}