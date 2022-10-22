#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long int64;

int64 geet(vector<int64> const &tree, int64 l, int64 r) {
	int64 n = tree.size() / 2, res = 0;
	l += n;
	r += n;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = max(res, tree[l++]);
		if (r & 1)
			res = max(res, tree[--r]);
	}
	return res;
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	int64 n, m, k, i, j, j2, resnum = 0, sum;
	cin >> n >> m >> k;
	vector<vector<int64> > army(m, vector<int64>(n * 2));
	vector<int64> res(m, 0);
	vector<int64> res2(m, 0);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> army[j][i + n];

	for (i = n - 1; i > 0; i--)
		for (j = 0; j < m; j++)
			army[j][i] = max(army[j][i * 2], army[j][i * 2 + 1]);

	for (i = 0, j = 0; i < n; i++) {
		while (j < n) {
			j++;
			sum = 0;
			if (j - i > resnum) {
				for (j2 = 0; j2 < m; j2++)
					sum += res2[j2] = geet(army[j2], i, j);
				if (sum <= k) {
					resnum = j - i;
					swap(res, res2);
				}
				else
					break;
			}
		}
	}

	for (i = 0; i < m; i++)
		cout << res[i] << ' ';

	return 0;
}