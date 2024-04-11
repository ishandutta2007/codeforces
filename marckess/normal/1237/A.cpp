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

const int MX = 100000;
int n, a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0, f = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] /= 2;
		} else if (a[i] < 0) {
			a[i] = (a[i] - 1 + f) / 2;
			f = 1 - f;
		} else {
			a[i] = (a[i] + f) / 2;
			f = 1 - f;
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	return 0;
}