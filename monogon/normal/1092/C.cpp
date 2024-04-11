#include <iostream>

using namespace std;

int n;
string s[200];
int a[100][2];
string str;

bool isPrefix(string p) {
	int len = p.length();
	for(int j = 0; j < len; j++) {
		if(p[j] != str[j]) {
			return false;
		}
	}
	return true;
}
bool isSuffix(string p) {
	int len = p.length();
	for(int j = 0; j < len; j++) {
		if(p[j] != str[n - len + j]) {
			return false;
		}
	}
	return true;
}

bool consistent() {
	for(int i = 1; i < n; i++) {
		if(isPrefix(s[a[i][0]]) && isSuffix(s[a[i][1]])) {
			continue;
		}else if(isSuffix(s[a[i][0]]) && isPrefix(s[a[i][1]])) {
			swap(a[i][0], a[i][1]);
		}else {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		a[i][0] = a[i][1] = -1;
	}
	for(int i = 0; i < 2 * n - 2; i++) {
		cin >> s[i];
		if(a[s[i].length()][0] == -1) {
			a[s[i].length()][0] = i;
		}else {
			a[s[i].length()][1] = i;
		}
	}

	str = s[a[n - 1][0]] + s[a[n - 1][1]][n - 2];
	if(!consistent()) {
		str = s[a[n - 1][1]] + s[a[n - 1][0]][n - 2];
		consistent();
	}

	// print
	for(int i = 0; i < 2 * n - 2; i++) {
		if(i == a[s[i].length()][0]) {
			cout << "P";
		}else {
			cout << "S";
		}
	}
}