#include <bits/stdc++.h>
using namespace std;

string l = "", r = "", ans = "";
int n, x, y;

int main() {
	cin >> n;
	x = y = 1;
	for (int i = 1; i <= n - 1; i++) {
		cout << "? " << x << " " << y + 1 << " " << n << " " << n << endl;
		cin >> ans; bool ok = 0; if(ans[0] == 'Y') ok = 1;
		if (y <= n - 1 && ok) {
			l = l + "R";
			y++;
		} else {
			l = l + "D";
			x++;
		}
	}
	x = y = n;
	for (int i = 1; i <= n - 1; i++) {
		cout << "? " << 1 << " " << 1 << " " << x - 1 << " " << y << endl;
		cin >> ans; bool ok = 0; if(ans[0] == 'Y') ok = 1;
		if (x >= 2 && ok) {
			r = "D" + r;
			x--;
		} else {
			r = "R" + r;
			y--;
		}
	}
	cout << "! " << l + r << endl;
	return 0;
}