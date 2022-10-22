#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, i, res = 0;
	cin >> n;
	vector<ll> val(n);
	for (i = 0; i < n; i++)
		cin >> val[i];
	sort(val.begin(), val.end());
	for (i = 1; i < n; i++)
		if (val[i] <= val[i - 1]) {
			res += val[i - 1] + 1 - val[i];
			val[i] = val[i - 1] + 1;
		}
	cout << res;
	return 0;
}