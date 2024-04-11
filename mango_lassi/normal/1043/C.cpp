#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();
	
	// We can move a character to the front by reversing the prefix before it, then reversing its prefix
	// bbabab
	// babba
	// abbabb
	
	vector<int> ans(n, 0);
	for (int i = n-1; i >= 0; --i) {
		if (str[i] == 'a') {
			ans[i] ^= 1;
			if (i > 0) ans[i-1] ^= 1;
		}
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << '\n';
}