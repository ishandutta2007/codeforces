#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 1e+9;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, k, m, cur, prev, right, i, j;
	cin >> n >> k;
	right = -1;
	bool fail;
	for (i = 0; i < k; i++) {
		cin >> m;
		prev = 0;
		fail = false;
		for (j = 0; j < m; j++) {
			cin >> cur;
			if ((cur == prev + 1) && !fail)
				right++;
			else
				fail = true;
			prev = cur;
		}
	}

	cout << 2 * n - 2 * right - k - 1;

	return 0;
}