#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, a[50][50], k = 1;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i][n/2] = k;
		k += 2;

		if (i != n / 2) {
			a[n/2][i] = k;
			k += 2;
		}
	}

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < n / 2; j++)
			if (k <= n * n) {
				a[i][j] = k;
				a[n-i-1][j] = k + 2;
				a[i][n-j-1] = k + 4;
				a[n-i-1][n-j-1] = k + 6;
				k += 8;
			}

	k = 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				a[i][j] = k;
				k += 2; 
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}