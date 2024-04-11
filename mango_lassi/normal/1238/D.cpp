#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	// GOOD iff all characters in a palindrome
	// ONLY letters A, B
	//	-> String is good if
	//		1. It contains at least two of both characters
	//		2. It contains only one A, but it's not at the edges
	//		3. It contains no A's and has at least two b's

	ll res = 0;
	int lx = 0;
	int ly = 1;
	for (int i = 1; i < n; ++i) {
		if (str[i] == str[i-1]) ++ly;
		else {
			lx = ly;
			ly = 1;
		}
		if (ly == 1) {
			res += i+1 - (lx + ly);
		} else if (lx > 0) {
			res += i-1;
		} else {
			res += i;
		}
	}
	cout << res << '\n';
}