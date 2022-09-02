#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int as = 0;
	int bs = 0;
	int cs = 0;
	bool can = true;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'a') {
			++as;
			if (bs > 0 || cs > 0) {
				can = false;
				break;
			}
		} else if (str[i] == 'b') {
			++bs;
			if (cs > 0) {
				can = false;
				break;
			}
		} else if (str[i] == 'c') {
			++cs;
		} else {
			can = false;
			break;
		}
	}
	if (as == 0 || bs == 0) can = false;
	if (cs != as && cs != bs) can = false;
	if (can) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}