#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a[25];

	vvi x, y;

	for (int i = 1; i <= 24; i++)
		cin >> a[i];

	if (a[1] == a[2] && a[1] == a[3] && a[1] == a[4]
	 && a[9] == a[10] && a[9] == a[11] && a[9] == a[12]) {

		x = {
			{13, 14, 7, 8},
			{5, 6, 19, 20},
			{17, 18, 23, 24},
			{21, 22, 15, 16}
		};

		y = {
			{15, 16, 5, 6},
			{7, 8, 17, 18},
			{19, 20, 21, 22},
			{13, 14, 23, 24}
		};

	} else if (a[13] == a[14] && a[14] == a[15] && a[15] == a[16]
	        && a[17] == a[18] && a[18] == a[19] && a[19] == a[20]) {

		x = {
			{1, 3, 6, 8},
			{5, 7, 10, 12},
			{9, 11, 21, 23},
			{22, 24, 2, 4}
		};

		y = {
			{2, 4, 5, 7},
			{6, 8, 9, 11},
			{10, 12, 22, 24},
			{1, 3, 21, 23}
		};

	} else if (a[5] == a[6] && a[6] == a[7] && a[7] == a[8]
	        && a[21] == a[22] && a[22] == a[23] && a[23] == a[24]) {

		x = {
			{3, 4, 18, 20},
			{17, 19, 11, 12},
			{9, 10, 13, 15},
			{14, 16, 1, 2}
		};

		y = {
			{3, 4, 13, 15},
			{14, 16, 11, 12},
			{9, 10, 18, 20},
			{3, 4, 13, 15}
		};

	} else {
		cout << "NO" << endl;
		return 0;
	}

	bool _x = true, _y = true;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			_x &= a[x[i][j]] == a[x[i][j-1]];
			_y &= a[y[i][j]] == a[y[i][j-1]];
		}
	}

	if (_x || _y) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}