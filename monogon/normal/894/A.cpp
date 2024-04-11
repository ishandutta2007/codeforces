
#include <iostream>
#include <cstring>

using namespace std;

string str;

int count(const char *str, const char *pattern) {
	if(strlen(str) < strlen(pattern)) {
		return 0;
	}
	if(strlen(pattern) == 0) {
		return 1;
	}
	int ret = count(str + 1, pattern);
	if(str[0] == pattern[0]) {
		ret += count(str + 1, pattern + 1);
	}
	return ret;
}

int main() {
	cin >> str;
	const char * str2 = str.c_str();
	const char * str3 = "QAQ";
	cout << count(str2, str3) << endl;
}