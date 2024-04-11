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

int n, m, a[555], b[555];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 1 || m == 1) {
		for (int i = 1, k = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << k << " ";
				k++;
			}
			cout << endl;
		}
		return 0;
	}

	a[1] = 1, a[2] = 2;
	b[1] = 3, b[2] = 4;
	int k = 5;
	for (int i = 3; i <= n; i++) {
		a[i] = k++;
	}
	for (int i = 3; i <= m; i++) {
		b[i] = k++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i] * b[j] << " ";
		}
		cout << endl;
	}

	return 0;
}