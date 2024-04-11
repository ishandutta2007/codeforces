#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
int n, k;

void res (bool fi) {
	if (fi) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

void solve () {
	cin >> n >> k;
	if (k % 3) {
		res(n % 3);
	} else {
		int x = n % (k + 1);
		res(x % 3 || x == k);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--) {
		solve();
	}

	return 0;
}