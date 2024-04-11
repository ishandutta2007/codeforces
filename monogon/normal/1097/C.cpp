#include <iostream>
#include <set>

using namespace std;

int n;
string s;

int getLeft() {
	int res = 0;
	int count = 0;
	for(unsigned int i = 0; i < s.length(); i++) {
		if(s[i] == '(') {
			count++;
		}else if(count == 0) {
			res++;
		}else {
			count--;
		}
	}
	return res;
}

int getRight() {
	int res = 0;
	int count = 0;
	for(int i = s.length() - 1; i >= 0; i--) {
		if(s[i] == ')') {
			count++;
		}else if(count == 0) {
			res++;
		}else {
			count--;
		}
	}
	return res;
}

multiset<pair<int, int> > nums;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		int x = getLeft();
		int y = getRight();
		if(x == 0 || y == 0) {
			nums.insert(make_pair(x, y));
		}
	}
	int count = 0;
	while(!nums.empty()) {
		pair<int, int> p = *nums.begin();
		nums.erase(nums.begin());
		auto it = nums.find(make_pair(p.second, p.first));
		if(it != nums.end()) {
			count++;
			nums.erase(it);
		}
	}
	cout << count;
}