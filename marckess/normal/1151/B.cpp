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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, m, a[MX][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int s = 0;
	for (int i = 0; i < n; i++)
		s ^= a[i][0];

	if (s) {
		cout << "TAK" << endl;
		for (int i = 0; i < n; i++)
			cout << 1 << " ";
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s ^ a[i][0] ^ a[i][j]) {
				cout << "TAK" << endl;
				for (int k = 0; k < n; k++)
					cout << (k == i ? j + 1 : 1) << " ";
				cout << endl;
				return 0;
			}

	cout << "NIE" << endl;
	
	return 0;
}