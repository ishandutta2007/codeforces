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

int a, b, c, d, e, f, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> c >> d >> e >> f;

	for (int i = 0; i <= d; i++) {
		int x = min(a, i);
		int y = min({b, c, d - i});
		res = max(res, e * x + f * y);
	}

	cout << res << endl;

	return 0;
}