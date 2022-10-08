
#include <iostream>

using namespace std;

int n;
string str;

int main() {
	cin >> n >> str;
	for(int i = 1; i < n; i++) {
		if(str[i] < str[i - 1]) {
			cout << "YES" << endl << i << " " << (i + 1) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}