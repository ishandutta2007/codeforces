#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long int64;

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	char c;
	bool wait = true;
	while (true) {
		c = '\n';
		cin >> c;
		if (!((c >= '0') && (c <= '9')))
			break;
		if ((c > '4') && (!wait || (c != '9')))
			cout << (char)('0' + (9 - (c - '0')));
		else
			cout << c;
		wait = false;
	}

	return 0;
}