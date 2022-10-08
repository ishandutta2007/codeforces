
#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main() {
	cin >> str;
	int sum = 0;
	for(unsigned int i = 0; i < str.length(); i++) {
		sum += (str[i] == 'a');
	}
	cout << min((int) str.length(), 2 * sum - 1) << endl;
}