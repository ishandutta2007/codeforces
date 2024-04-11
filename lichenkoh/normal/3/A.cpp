#include <iostream>
#include <assert.h>
using namespace std;
void calc(int deltax, int deltay) {
	while (deltax != 0 || deltay != 0) {
		if (deltax == 0 && deltay > 0) {cout << "U" << endl; deltay--;}
		if (deltax == 0 && deltay < 0) {cout << "D" << endl; deltay++;}
		if (deltax > 0 && deltay == 0) {cout << "R" << endl; deltax--;}
		if (deltax < 0 && deltay == 0) {cout << "L" << endl; deltax++;}
		if (deltax > 0 && deltay > 0) {cout << "RU" << endl; deltax--; deltay--;}
		if (deltax > 0 && deltay < 0) {cout << "RD" << endl; deltax--; deltay++;}
		if (deltax < 0 && deltay > 0) {cout << "LU" << endl; deltax++; deltay--;}
		if (deltax < 0 && deltay < 0) {cout << "LD" << endl; deltax++; deltay++;}
	}
}
int abs(int x) {
	if (x < 0) return -x;
	return x;
}
int main() {
	string s;
	string t;
	cin >> s;
	cin >> t;
	int sx = s[0] - 'a';
	int sy = s[1] - '1';
	int tx = t[0] - 'a';
	int ty = t[1] - '1';
	int deltax = tx-sx;
	int deltay = ty-sy;
	int moves = (abs(deltax) > abs(deltay))? abs(deltax) : abs(deltay);
	cout << moves << endl;
	calc(deltax, deltay);
	return 0;
}