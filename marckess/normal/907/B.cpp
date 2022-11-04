#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int x, y;
	char c[9][9];

	for (int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			cin >> c[i][j];
	cin >> x >> y;

	x = (x - 1) % 3; 
	y = (y - 1) % 3;

	bool f = 0;
	for (int i = x * 3; i < (x + 1) * 3; i++)
		for (int j = y * 3; j < (y + 1) * 3; j++)
			f |= c[i][j] == '.';

	if (f) {
		for (int i = x * 3; i < (x + 1) * 3; i++)
			for (int j = y * 3; j < (y + 1) * 3; j++)
				if (c[i][j] == '.')
					c[i][j] = '!';
	} else {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (c[i][j] == '.')
					c[i][j] = '!';
	}

	for (int i = 0; i < 9; i++) {
		if (i && i % 3 == 0)
			cout << endl;

		for (int j = 0; j < 9; j++) {
			if (j && j % 3 == 0)
				cout << " ";
			cout << c[i][j];
		}

		cout << endl;
	}

	return 0;
}