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

	ll k, n, w;
	cin >> k >> n >> w;
	cout << max((ll)0, w * (w + 1) * k / 2 - n);

	return 0;
}