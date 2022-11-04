#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 2005;
int n, m, acu[MX];
char a[MX][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '1')
				acu[j]++;
		}
	}

	for (int i = 0; i < n; i++) {
		bool f = 1;
		for (int j = 0; j < m; j++)
			if (a[i][j] == '1' && acu[j] == 1)
				f = 0;
		if (f) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}