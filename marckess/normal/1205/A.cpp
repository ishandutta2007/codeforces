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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, a[200005];
	cin >> n;
	if (n % 2 == 0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (i % 2) a[i] = 2 * i + 1, a[i+n] = 2 * i + 2;
			else a[i] = 2 * i + 2, a[i+n] = 2 * i + 1;
		}
		forn(i, 2 * n)
			cout << a[i] << " ";
		cout << endl;
	}

	return 0;
}