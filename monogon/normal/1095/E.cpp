#include <iostream>

#define M 1000000

using namespace std;

int n;
string s;

int l[M];
int r[M];

int main() {
	cin >> n >> s;
	int count = 0;
	int max0 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') {
			count++;
		}else {
			if(count > 0) {
				count--;
			}else {
				max0++;
			}
		}
		l[i] = count;
	}
	count = 0;
	int max1 = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == ')') {
			count++;
		}else {
			if(count > 0) {
				count--;
			}else {
				max1++;
			}
		}
		r[i] = count;
	}

	count = 0;
	if(max0 == 0 && max1 == 2) {
		for(int i = 1; i < n - 1; i++) {
			if(s[i] == '(' && l[i - 1] == r[i + 1] + 1) {
				count++;
			}
		}
		count += s[n - 1] == '(' && l[n - 2] == 1;
	}else if(max0 == 2 && max1 == 0) {
		for(int i = 1; i < n - 1; i++) {
			if(s[i] == ')' && l[i - 1] + 1 == r[i + 1]) {
				count++;
			}
		}
		count += s[0] == ')' && r[1] == 1;
	}
	cout << count << endl;
}