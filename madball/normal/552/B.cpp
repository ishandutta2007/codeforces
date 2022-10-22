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
	ll n, res = 0, mult = 1, cnt = 1;
	cin >> n;
	while (n > 0) {
		res += mult * min(cnt * 9, n);
		n -= cnt * 9;
		cnt *= 10;
		mult++;
	}
	cout << res;
	return 0;
}