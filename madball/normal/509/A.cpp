#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	long long n, res = 1;
	cin >> n;
	n--;
	for (int i = 1; i <= n; i++)
		res = res * (i + n) / i;
	cout << res;
	return 0;
}