#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in;
	in.open("input.txt");
	ifstream out;
	out.open("output.txt");*/
	int w = 0, b = 0, i;
	char c;
	for (i = 0; i < 64; i++) {
		cin >> c;
		switch(c) {
		case 'Q': w += 9; break;
		case 'R': w += 5; break;
		case 'B': w += 3; break;
		case 'N': w += 3; break;
		case 'P': w += 1; break;
		case 'q': b += 9; break;
		case 'r': b += 5; break;
		case 'b': b += 3; break;
		case 'n': b += 3; break;
		case 'p': b += 1; break;
		}
	}
	if (w == b)
		cout << "Draw";
	else
		cout << (w < b ? "Black" : "White");
	return 0;
}


//'q', 'r', 'b', 'n', 'p', 'k'
// 9    5    3    3    1    0