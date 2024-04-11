#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define esBis(y) (y % 400 == 0 || (y % 4 == 0 && y % 100))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int y, x = 0;
	bool b, f;

	cin >> y;

	b = esBis(y);

	do {
		y++;

		x += 365 + esBis(y);
		x %= 7;
		f = x == 0 && esBis(y) == b;
	} while (!f);

	cout << y << endl;

	return 0;
}