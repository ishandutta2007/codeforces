
#include <iostream>
#include <sstream>

using namespace std;

int n;
string str;

int main() {
	cin >> n >> str;
	stringstream ss;
	int count = 0;
	for(int i = 0; i < n; i += 2) {
		if(str[i] == str[i + 1]) {
			count++;
			i--;
		}else {
			ss << str[i] << str[i + 1];
		}
	}
	str = ss.str();
	if((n - count) % 2 == 1) {
		count++;
		cout << count << endl << str.substr(0, str.length() - 2);
	}else{
		cout << count << endl << str << endl;
	}
}