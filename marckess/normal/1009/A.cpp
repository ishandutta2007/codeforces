#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m, c[1005], a[1005], res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < m; i++)
		cin >> a[i];

	for (int i = 0, j = 0; i < n && j < m; i++) {
		if (c[i] <= a[j]) {
			j++;
			res++;
		}
	}

	cout << res << endl;


	return 0;
}