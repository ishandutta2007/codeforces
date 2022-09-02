#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	ll cou1 = 0;
	ll cou2 = 0;
	ll cou3 = 0;
	for (int i = 0; i < n; ++i) {
		if (i+1 < n && str[i] == 'v' && str[i+1] == 'v') {
			++cou1;
			cou3 += cou2;
		} else if (str[i] == 'o') {
			cou2 += cou1;
		}
	}
	cout << cou3 << '\n';
}