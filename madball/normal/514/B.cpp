#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long int64;

bool online(int64 x1, int64 y1, int64 x2, int64 y2, int64 x3, int64 y3) {
	return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	int64 n, x, y, i, j, res = 0;
	cin >> n >> x >> y;
	vector<bool> been(n, false);
	vector<int64> xs(n);
	vector<int64> ys(n);
	for (i = 0; i < n; i++)
		cin >> xs[i] >> ys[i];
	for (i = 0; i < n; i++)
		if (!been[i]) {
			been[i] = true;
			res++;
			for (j = 0; j < n; j++)
				if (online(x, y, xs[i], ys[i], xs[j], ys[j]))
					been[j] = true;
		}

	cout << res;
	return 0;
}