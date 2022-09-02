#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i+1 < n; ++i) {
		if (str[i] == str[i+1]) continue;
		else {
			cout << "YES\n";
			cout << str[i] << str[i+1] << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}