#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

bool look4(vector<int> const &v, int value, int &resx, int &resy, int write, bool sum) {
	int a = 0, b = 1;
	while (a < v.size() - 1) {
		if (v[b] - v[a] == value) {
			resx = a;
			resy = b;
			if (write) {
				if (sum) {
					cout << 1 << '\n' << (v[a] + write);
					return true;
				}
				else {
					if (v[a] - write >= 0) {
						cout << 1 << '\n' << (v[a] - write);
						return true;
					}
					if (v[b] + write <= v[v.size() - 1]) {
						cout << 1 << '\n' << (v[b] + write);
						return true;
					}
				}
			}
			else
				return true;
		}
		if (((v[b] - v[a] < value) || (a == b - 1)) && (b < v.size() - 1))
			b++;
		else
			a++;
	}
	return false;
}

int main() {
	int n, l, x, y;
	cin >> n >> l >> x >> y;
	vector<int> ruler(n);
	for (int i = 0; i < n; i++)
		cin >> ruler[i];

	int lx = 0, rx = 0;
	bool hasx = look4(ruler, x, lx, rx, 0, false);
	int ly = 0, ry = 0;
	bool hasy = look4(ruler, y, ly, ry, 0, false);

	if (hasx && hasy)
		cout << 0;
	if (hasx && !hasy)
		cout << 1 << '\n' << y;
	if (!hasx && hasy)
		cout << 1 << '\n' << x;
	if (!hasx && !hasy) {
		if (!look4(ruler, y - x, lx, rx, x, false))
			if (!look4(ruler, y + x, lx, rx, x, true))
				cout << 2 << '\n' << x << ' ' << y;
	}

	return 0;
}