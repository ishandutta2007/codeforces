#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

bool contains(int a, int b, const string& str) {
	for (int i = a; i <= b; ++i) {
		for (int k = 1; i+2*k <= b; ++k) {
			if (str[i] == str[i+k] && str[i+k] == str[i+2*k]) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	int j = 0;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		while(j < n && !contains(i, j, str)) ++j;
		res += n-j;
	}
	cout << res << '\n';
}