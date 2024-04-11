
#include <iostream>
#include <stack>

using namespace std;

int n;
string str;
stack<bool> s;

int main() {
	cin >> n >> str;
	for(int i = 0; i < n; i++) {
		if(str[i] == '(') {
			if(s.empty()) {
				s.push(false);
				cout << 0;
			}else {
				s.push(!s.top());
				cout << s.top();
			}
		}else {
			cout << s.top();
			s.pop();
		}
	}
	cout << endl;
}