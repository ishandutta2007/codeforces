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

const int MX = 200005;
int n, a[MX], izq[MX], der[MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = 2e9, a[n+1] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i-1]) {
			izq[i] = izq[i-1] + 1;
		} else {
			izq[i] = 1;
		}
		res = max(res, izq[i]);
	}

	for (int i = n; i; i--) {
		if (a[i] < a[i+1]) {
			der[i] = der[i+1] + 1;
		} else {
			der[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		if (a[i-1] < a[i+1])
			res = max(res, izq[i-1] + der[i+1]);
	cout << res << endl;

	return 0;
}