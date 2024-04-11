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

const int MX = 505;

int n, m, f, o;
char c[MX][MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

bool valid (int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && c[i][j] == '*';
}

void no () {
	cout << "no" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int cn = 0;
			
			if (!valid(i, j)) continue;
			for (int k = 0; k < 4; k++)
				cn += valid(i + mx[k], j + my[k]);

			if (cn == 1) o++;
			else if (cn == 4) f++;
			else if (cn == 2) {
				if (valid(i, j + 1) != valid(i, j - 1))
					no();
			} else {
				no();
			}
		}

	if (f != 1 || o != 4)
		no();

	cout << "YES" << endl;

	return 0;
}