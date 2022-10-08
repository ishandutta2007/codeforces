#include <iostream>
#include <stack>
#include <set>

using namespace std;

int n;
int arr[50];
stack<int> s1;
set<int> s2;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = n - 1; i >= 0; i--) {
		if(s2.find(arr[i]) == s2.end()) {
			s2.insert(arr[i]);
			s1.push(arr[i]);
		}
	}
	cout << s1.size() << endl;
	while(!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
}