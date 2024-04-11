
#include <iostream>

using namespace std;

int n, x, y;
string str;

int main() {
	cin >> n >> x >> y;
	cin >> str;
	int count = 0;
	for(int i = n - 1; i >= n - x; i--) {
		count += (str[i] == '1' && i != n - y - 1) || (str[i] == '0' && i == n - y - 1);
	}
	cout << count << endl;
}