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
	int d = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '(') ++d;
		cout << (d%2);
		if (str[i] == ')') --d;
	}
	cout << '\n';
}