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

typedef tuple<int,int,int> iii;
typedef vector<iii> viii;

int n, k;
int a[5][55];
viii res;

void verif (int i, int j) {
	if (i == 2 && a[2][j] == a[1][j]) {
		res.emplace_back(a[2][j], 1, j);
		a[2][j] = 0;
		k--;
	}

	if (i == 3 && a[3][j] == a[4][j]) {
		res.emplace_back(a[3][j], 4, j);
		a[3][j] = 0;
		k--;
	}
}

void obtRes (int i, int j) {
	while (k) {
		if (i == 2 && j == 1) { 
			if (a[3][j]) {
				res.emplace_back(a[3][j], i, j);
				swap(a[3][j], a[2][j]);
				verif(i, j);
			}
			i = 3;
		} else if (i == 3 && j == n) {
			if (a[2][j]) {
				res.emplace_back(a[2][j], i, j);
				swap(a[3][j], a[2][j]);
				verif(i, j);
			}
			i = 2;
		} else if (i == 2) {
			if (a[2][j-1]) {
				res.emplace_back(a[2][j-1], i, j);
				swap(a[2][j], a[2][j-1]);
				verif(i, j);
			}
			j--;
		} else {
			if (a[3][j+1]) {
				res.emplace_back(a[3][j+1], i, j);
				swap(a[3][j], a[3][j+1]);
				verif(i, j);
			}
			j++;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++) {
		if (a[1][i] && a[1][i] == a[2][i]) {
			res.emplace_back(a[2][i], 1, i);
			a[2][i] = 0;
			k--;
		}

		if (a[3][i] && a[3][i] == a[4][i]) {
			res.emplace_back(a[3][i], 4, i);
			a[3][i] = 0;
			k--;
		}
	}

	if (2 * n == k) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 2; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			if (k && a[i][j] == 0)
				obtRes(i, j);

	int a, b, c;
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		tie(a, b, c) = res[i];
		cout << a << " " << b << " " << c << endl;
	}

	return 0;
}