
#include <iostream>

using namespace std;

int n;
string str;

int main() {
	cin >> n >> str;
	int count = 0;
	for(int i = 0; i < n; i++) {
		count += (str[i] == '+' ? 1 : -1);
		if(count < 0) count = 0;
	}
	cout << count << endl;
}