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

	int mn = 256;
	for (int i = 0; i < n; ++i) {
		if (str[i] <= mn) cout << "Mike\n";
		else cout << "Ann\n";
		mn = min(mn, (int)str[i]);
	}
}