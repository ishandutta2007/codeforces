#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();
	int res = n/2;
	if (n % 2 == 1) {
		for (int i = 1; i < n; ++i) {
			if (str[i] == '1') {
				++res;
				break;
			}
		}
	}
	cout << res << '\n';
}