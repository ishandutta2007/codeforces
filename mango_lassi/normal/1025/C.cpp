#include <iostream>
using namespace std;

int main() {
	// abc | def
	// -> cba | fed
	// ab | cdef
	// -> ba | fedc

	// Moving the split point allows us to modify the cycle of the string
	// Therefore answer is maximum over any cycle of the string
	
	string str;
	cin >> str;
	int n = str.size();
	int res = 0;
	int curr = 1;

	int start_curr = -1;
	int end_curr = -1;
	for (int i = 1; i < n; ++i) {
		if (str[i] == str[i-1]) {
			if (start_curr == -1) start_curr = curr;
			res = max(res, curr);
			curr = 1;
		} else {
			++curr;
		}
	}
	
	if (start_curr == -1) start_curr = curr;
	end_curr = curr;
	res = max(res, curr);

	if (str[0] != str[n-1]) res = max(min(n, start_curr + end_curr), res);
	cout << res << '\n';
}