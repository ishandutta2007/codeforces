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

const int MX = 100000;
int n, mat[10][10], bs[MX], cn[10][MX];
string p;

int val (int i) {
	return 10000 * mat[i][0] + 1000 * mat[i][1] + 100 * mat[i][2] + 10 * mat[i][3] + 1 * mat[i][4];
}

void impr () {
	forn (i, 5) {
		forn (j, 5) cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

ll go (int i, int j) {
	if (i == 5) {
		int res = 1;
		for (int k = 6 - n; k < 5; k++)
			res *= cn[k][val(k)];
		return res;
	}
	if (j == 5) return go(i + 1, i + 2);

	int res = 0;

	forn (k, 10) {
		mat[i][j] = mat[j][i] = k;
		res += go(i, j + 1);
	}

	return res;
}

void solve () {
	cin >> p;

	n = p.size();

	memset(mat, 0, sizeof(mat));
	forn (i, n) mat[5 - n][i + 5 - n] = mat[i +  5 - n][5 - n] = p[i] - '0';

	cout << go(6 - n, 7 - n) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	forn (i, MX) bs[i] = 1;
	bs[0] = bs[1] = 0;

	forn (i, MX) if (bs[i]) {
		for (int j = 2 * i; j < MX; j += i) bs[j] = 0;

		string p = to_string(i);
		while (p.size() < 5) p = "0" + p;

		forn (j, 5) {
			string t = p;
			t[j] = '0';
			cn[j][stoi(t)]++;
		}
	}

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}