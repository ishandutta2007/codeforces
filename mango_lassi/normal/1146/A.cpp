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
	int as = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'a') ++as;
	}
	cout << min(n, 2*as - 1) << '\n';
}