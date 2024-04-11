#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; ++i) cout << str[i];
	for (int i = n-2; i >= 0; --i) cout << str[i];
	cout << '\n';
}