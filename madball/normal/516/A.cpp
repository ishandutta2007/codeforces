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
	int64 n, i;
	char c;
	cin >> n;
	vector<int> amo(10, 0);
	for (i = 0; i < n; i++) {
		cin >> c;
		switch (c) {
			case '2': amo[2]++; break;
			case '3': amo[3]++; break;
			case '4': amo[2] += 2; amo[3]++; break;
			case '5': amo[5]++; break;
			case '6': amo[5]++; amo[3]++; break;
			case '7': amo[7]++; break;
			case '8': amo[7]++; amo[2] += 3; break;
			case '9': amo[7]++; amo[3] += 2; amo[2]++;
		}
	}

	for (i = 9; i > 0; i--)
		while (amo[i]--)
			cout << i;
	return 0;
}