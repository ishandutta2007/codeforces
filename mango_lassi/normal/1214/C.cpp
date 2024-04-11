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

	bool fail = false;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '(') ++sum;
		else --sum;
		if (sum < -1) fail = true;
	}
	if (sum != 0) fail = true;

	if (fail) cout << "No\n";
	else cout << "Yes\n";
}