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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	vi f(256);
	string s;

	cin >> n >> k >> s;
	while (k--) {
		char c;
		cin >> c;
		f[c] = 1;
	}

	ll res = 0, x = 0;
	for (char c : s) {
		if (f[c]) {
			x++;
		} else {
			x = 0;
		}
		res += x;
	}
	cout << res << endl;

	return 0;
}