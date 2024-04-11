#include <iostream>

using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;
	int idx = 0;
	for(int i = 0; idx < n; i++) {
		cout << s[idx];
		idx += (i + 1);
	}
}