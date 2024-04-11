#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int query(const string& str) {
	cout << str << endl;
	int res;
	cin >> res;
	if (res == 0) exit(0);
	return res;
}

const int N = 300;

int main() {
	string all_a(N, 'a');
	string all_b(N, 'b');
	int as = N - query(all_a);
	int bs = N - query(all_b);
	int n = as + bs;

	if (as == 0) query(string(n, 'b'));
	else if (bs == 0) query(string(n, 'a'));

	int cur = bs;
	string pref = "";
	string suff = string(as, 'a');
	while(true) {
		string que = pref + 'b' + suff;
		if (query(que) < cur) {
			// Happens at most bs times
			--cur;
			pref.push_back('b');
		} else {
			// Happens at most as times
			pref.push_back('a');
			suff.pop_back();
		}
	}
	// -> in total, at most n+2 operations
}