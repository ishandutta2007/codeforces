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

int n;
vi a, b, res;

bool go (int f) {
	res.clear();
	b = a;

	for (int i = 0; i + 1 < n; i++)
		if (b[i] != f) {
			b[i] ^= 1;
			b[i+1] ^= 1;
			res.pb(i + 1);
		}

	return b.back() == f;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a.pb(c == 'W');
	}

	if (go(0)) {
		cout << res.size() << endl;
		for (int x : res)
			cout << x << " ";
		cout << endl;
		return 0;
	}

	if (go(1)) {
		cout << res.size() << endl;
		for (int x : res)
			cout << x << " ";
		cout << endl;
		return 0;
	}

	cout << -1 << endl;

	return 0;
}