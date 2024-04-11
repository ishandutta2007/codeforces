#include <iostream>
using namespace std;

const int C = 26;
int apps[C];

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		++apps[str[i]-'a'];
	}
	int ones = 0;
	for (int c = 0; c < C; ++c) {
		if (apps[c] == 1) ++ones;
	}
	if (n > 1 && ones == n) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}