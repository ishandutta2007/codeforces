
#include <iostream>
#include <stack>

using namespace std;

int n;
string str;
bool unmatched[300000];

int main() {
	cin >> n >> str;
	if(n % 2 == 1 || str[0] == ')' || str[n - 1] == '(') {
		cout << ":(" << endl;
		return 0;
	}
	str[0] = '(';
	str[n - 1] = ')';

	// unmatched lefts, rights
	stack<int> s, s2;
	for(int i = 1; i < n - 1; i++) {
		if(str[i] == '(') {
			s.push(i);
			unmatched[i] = true;
		}else if(str[i] == ')') {
			if(s.empty()) {
				s2.push(i);
				unmatched[i] = true;
			}else {
				unmatched[s.top()] = false;
				s.pop();
			}
		}
	}
	int count = 0;
	for(int i = 1; i < n - 1; i++) {
		if(str[i] == '(' && unmatched[i]) {
			count++;
		}else if(str[i] == '?' && count > 0) {
			str[i] = ')';
			count--;
		}
	}
	if(count > 0) {
		cout << ":(" << endl;
		return 0;
	}
	int qs = 0;
	for(int i = n - 2; i > 0; i--) {
		if(str[i] == ')' && unmatched[i]) {
			count++;
		}else if(str[i] == '?' && count > 0) {
			str[i] = '(';
			count--;
		}else if(str[i] == '?') {
			qs++;
		}
	}
	if(count > 0) {
		cout << ":(" << endl;
		return 0;
	}
	for(int i = 1; i < n - 1; i++) {
		if(str[i] == '?') {
			if(count < qs / 2) {
				str[i] = '(';
			}else {
				str[i] = ')';
			}
			count++;
		}
	}
	cout << str << endl;
}