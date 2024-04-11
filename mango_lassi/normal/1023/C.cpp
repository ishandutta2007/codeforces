#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cerr << "QAQ QAQ QAQ\n";

	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	vector<int> ends(n+1);
	ends[n] = 0;
	for (int i = n-1; i >= 0; --i) {
		ends[i] = ends[i+1];
		if (str[i] == ')') ++ends[i];
	}

	int open = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '(' && ends[i+1] >= open + 1 && k >= open + 2) {
			cout << str[i];
			++open;
			--k;
		} else if (str[i] == ')' && open > 0) {
			cout << str[i];
			--open;
			--k;
		}
	}
	cout << '\n';
}