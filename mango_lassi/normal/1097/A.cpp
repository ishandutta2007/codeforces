#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool fail = true;

	string tar;
	cin >> tar;
	for (int j = 0; j < 5; ++j) {
		string car;
		cin >> car;
		if (car[0] == tar[0] || car[1] == tar[1]) fail = false;
	}
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}