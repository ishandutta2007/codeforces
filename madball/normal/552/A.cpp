#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/
	ll n, x1, y1, x2, y2, res = 0;
	for (cin >> n; n; n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		res += (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	cout << res;
	return 0;
}