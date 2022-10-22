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

	string a, b;
	cin >> a >> b;
	ll n = a.size(), dist = 0, i;
	for (i = 0; i < n; i++)
		dist += a[i] != b[i];
	if (dist & 1)
		cout << "impossible";
	else {
		dist >>= 1;
		for (i = 0; i < n; i++)
			if ((dist > 0) && (a[i] != b[i])) {
				dist--;
				cout << (char)('1' - a[i] + '0');
			}
			else
				cout << a[i];
	}

	return 0;
}