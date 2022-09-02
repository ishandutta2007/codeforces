#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool ask(int x, int y, int tx, int ty) {
	cout << "? " << y << ' ' << x << ' ' << ty << ' ' << tx << endl;
	string ans;
	cin >> ans;
	return (ans.size() == 3);
}

int main() {
	int n;
	cin >> n;
	
	// Idea: Find route that goes as low-left as possible from target to center, then find route
	// that goes as low-left as possible from
	int x, y;
	x = 1;
	y = 1;
	vector<pair<int, int>> coords(2*n + 1);
	while(x + y < n+1) {
		coords[x + y] = {x, y};
		if (ask(x, y+1, n, n)) {
			++y;
		} else {
			++x;
		}
	}
	coords[x + y] = {x, y};

	x = n;
	y = n;
	while(x + y > n+1) {
		coords[x + y] = {x, y};
		if (ask(1, 1, x-1, y)) {
			--x;
		} else {
			--y;
		}
	}
	cout << "! ";
	for (int i = 2; i+1 <= 2*n; ++i) {
		if (coords[i+1].first != coords[i].first) {
			cout << "R";
		} else {
			cout << "D";
		}
	}
	cout << endl;
}