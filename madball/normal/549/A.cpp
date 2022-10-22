#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	ll n, m, i, j, k;
	cin >> n >> m;
	vector<string> image(n);
	for (i = 0; i < n; i++)
		cin >> image[i];

	ll f, a, c, e, res = 0;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < m - 1; j++) {
			f = 0; a = 0; c = 0; e = 0;
			for (k = 0; k < 4; k++) {
				switch (image[i + (k & 1)][j + (k >> 1)]) {
					case 'f': f++; break;
					case 'a': a++; break;
					case 'c': c++; break;
					case 'e': e++; break;
				}
			}
			if ((f == 1) && (a == 1) && (c == 1) && (e == 1))
				res++;
		}

	cout << res;
	return 0;
}