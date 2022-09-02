#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();	

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == ')') continue;
		int maxop = 1;
		int minop = 1;
		bool can = true;
		for (int j = i+1; j < n; ++j) {
			 if (str[j] == ')') {
				--maxop;
				if (minop == 0) {
					minop = 1;
				} else {
					--minop;
				}
				if (maxop < minop) can = false;
			} else if (str[j] == '(') {
				++maxop;
				++minop;
			} else {
				++maxop;
				if (minop == 0) {
					minop = 1;
				} else {
					--minop;
				}
			}
			// cout << i << ' ' << j << ' ' << minop << ' ' << maxop << '\n';
			if (!can) break;
			if (minop == 0) ++ans;
		}
	}
	cout << ans << '\n';
}