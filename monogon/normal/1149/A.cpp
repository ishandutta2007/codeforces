
#include <iostream>

using namespace std;

int n, a, x, y;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a == 1) x++;
		else y++;
	}
	if(x == 1 || x == 2) {
		if(y > 0) {
			cout << "2 ";
			y--;
		}
		cout << "1 ";
		x--;
	}else if(x >= 3) {
		cout << "1 1 1 ";
		x -= 3;
	}
	while(y > 0) {
		cout << "2 ";
		y--;
	}
	while(x > 0) {
		cout << "1 ";
		x--;
	}
}