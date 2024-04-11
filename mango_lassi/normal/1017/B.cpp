#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;
	
	ll cou[4];
	for (int i = 0; i < 4; ++i) cou[i] = 0;
	for (int i = 0; i < n; ++i) {
		int v = (a[i] == '1') + 2 * (b[i] == '1');
		++cou[v];
	}
	// Swap changes something, if one of the a's contains a one-bit, and not both of the b's contains a one-bit
	ll res = cou[0] * cou[1] + cou[2] * cou[1] + cou[3] * cou[0];
	cout << res << '\n';
}