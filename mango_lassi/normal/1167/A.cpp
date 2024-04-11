#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 11;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		bool succ = false;
		for (int i = 0; i + N <= n; ++i) {
			if (str[i] == '8') succ = true;
		}
		if (succ) cout << "YES\n";
		else cout << "NO\n";
	}
}