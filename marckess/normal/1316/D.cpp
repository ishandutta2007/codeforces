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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int MX = 1005;
int n, x[MX][MX], y[MX][MX];
char res[MX][MX];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};
char inv[] = {'U', 'D', 'L', 'R'};

bool valid (int i, int j) {
	return 1 <= i && i <= n && 1 <= j && j <= n;
}

void dfs (int i, int j, int ox, int oy) {
	for (int l = 0; l < 4; l++) {
		int ii = i + mx[l];
		int jj = j + my[l];

		if (valid(ii, jj) && !res[ii][jj] && x[ii][jj] == ox && y[ii][jj] == oy) {
			res[ii][jj] = inv[l];
			dfs(ii, jj, ox, oy);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> x[i][j] >> y[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (x[i][j] == i && y[i][j] == j) {
				res[i][j] = 'X';
				dfs(i, j, i, j);
			}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (x[i][j] == -1) {
				for (int l = 0; l < 4; l++) {
					int ii = i + mx[l];
					int jj = j + my[l];

					if (valid(ii, jj) && x[ii][jj] == -1)
						res[i][j] = dir[l];
				}
			}

			if (!res[i][j]) {
				cout << "INVALID" << endl;
				return 0;
			}
		}

	cout << "VALID" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			cout << res[i][j];
		cout << endl;
	}

	return 0;
}