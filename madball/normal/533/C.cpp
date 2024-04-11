#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ofstream in("input.txt");
	ofstream out("output.txt");*/
	ll xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;
	if (((xp <= xv) && (yp <= yv)) || (xp + yp <= max(xv, yv)))
		cout << "Polycarp";
	else
		cout << "Vasiliy";
	return 0;
}