#include <iostream>
#include <string>

using namespace std;

int n, x, r;
string s;

int main() {
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'x') {
			x++;
		}else {
			r += max(0, x - 2);
			x = 0;
		}
	}
	cout << r + max(0, x - 2) << endl;
}