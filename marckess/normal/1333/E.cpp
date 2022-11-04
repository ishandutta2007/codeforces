#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, a[MX][MX];
vvi v = {
	{1, 2, 4},
	{5, 3, 8},
	{9, 6, 7}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	if (n < 3) {
		cout << -1 << endl;
		return 0;
	}

	int k = n - 1, x = 1;
	while (k >= 3) {
		if (k % 2 == 0) {
			for (int i = 0; i <= k; i++)
				a[k][i] = x++;
			for (int i = k - 1; i >= 0; i--)
				a[i][k] = x++;
		} else {
			for (int i = 0; i <= k; i++)
				a[i][k] = x++;
			for (int i = k - 1; i >= 0; i--)
				a[k][i] = x++;
		}
		k--;
	}

	forn (i, 3) forn (j, 3) 
		a[i][j] = v[i][j] + x - 1;

	forn (i, n) {
		forn (j, n) cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}