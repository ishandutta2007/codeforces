#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < 0)
		return gcd(-a, b);
	if (b < 0)
		return gcd(a, -b);
	if (b == 0)
		return a;
	if (b > a)
		return gcd(b, a);
	return gcd(b, a % b);
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	long long n, m, i, j, res = 0;
	cin >> n >> m;
	vector<vector<long long> > matrix(n, vector<long long>(m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if ((i > 0) && (j > 0))
				res = gcd(matrix[i][j] - matrix[i - 1][j] - matrix[i][j - 1] + matrix[i - 1][j - 1], res);
		}
	bool succ = true;
	if (res == 0)
		res = 1000000000000;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (matrix[i][j] >= res)
				succ = false;
	if (succ) {
		cout << "YES\n" << res << '\n';
		for (i = 0; i < n; i++)
			cout << matrix[i][0] << ' ';
		cout << '\n';
		for (i = 0; i < m; i++)
			cout << matrix[0][i] - matrix[0][0] + res << ' ';
	}
	else
		cout << "NO";
	return 0;
}