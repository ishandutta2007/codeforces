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

	int64 n, m, m2, l = 0, r, i;
	cin >> n >> m;
	m--;
	r = n;
	vector<int64> res(n);
	for (m2 = (int64)(1) << (n - 2), i = 1; m2 > 0; m2 >>= 1, i++) {
		if (m2 & m)
			res[--r] = i;
		else
			res[l++] = i;
	}
	res[l] = i;
	for (i = 0; i < n; i++)
		cout << res[i] << ' ';

	return 0;
}