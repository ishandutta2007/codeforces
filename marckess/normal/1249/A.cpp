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

int q, n, a[105];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> q;
	while (q--) {
		cin >> n;
		forn (i, n)
			cin >> a[i];
		sort(a, a+n);

		int res = 1;
		forn (i, n - 1)
			if (a[i] + 1 == a[i + 1])
				res = 2;
		cout << res << endl;
	}

	return 0;
}