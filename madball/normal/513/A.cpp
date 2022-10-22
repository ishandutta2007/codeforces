#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int64;

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	int64 n1, k1, n2, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	if (n2 >= n1)
		cout << "Second";
	else
		cout << "First";

	return 0;
}