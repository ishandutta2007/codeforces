#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, i, j, cur, cnt;
	cin >> n;
	vector<bool> good(n, true);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			cin >> cur;
			if ((cur == 1) || (cur == 3))
				good[i] = false;
			if (cur >= 2)
				good[j] = false;
		}
	for (i = 0, cnt = 0; i < n; i++)
		cnt += good[i];
	cout << cnt << '\n';
	for (i = 0; i < n; i++)
		if (good[i])
			cout << i + 1 << ' ';

	return 0;
}