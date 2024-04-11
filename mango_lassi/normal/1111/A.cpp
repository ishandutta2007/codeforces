#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool vocal(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	bool match = true;
	if (a.size() != b.size()) {
		match = false;
	} else {
		for (int i = 0; i < a.size(); ++i) {
			if (vocal(a[i]) != vocal(b[i])) match = false;
		}
	}
	if (match) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}