#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	// Take first 2 and last 2 letters. Some pair of them has to match. Repeat.
	// When the ranges overlap, take any central character.

	string pref;
	string suff;
	int a = 0;
	int b = n-2;
	while(a+1 < b) {
		if (str[a] == str[b] || str[a] == str[b+1]) {
			pref.push_back(str[a]);
			suff.push_back(str[a]);
		} else {
			pref.push_back(str[a+1]);
			suff.push_back(str[a+1]);
		}
		a += 2;
		b -= 2;
	}
	if (a <= b+1) pref.push_back(str[a]);

	if (pref.size() + suff.size() >= n/2) {
		for (int j = 0; j < pref.size(); ++j) cout << pref[j];
		for (int j = (int)suff.size()-1; j >= 0; --j) cout << suff[j];
		cout << '\n';
	} else {
		cout << "IMPOSSIBLE\n";
	}
}