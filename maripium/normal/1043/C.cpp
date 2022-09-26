#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	string s; cin >> s; int n = s.size();
	vector<int> a(n, 0);
	int last = s[0] - 'a';
	for (int i = 1; i < n; ++i) {
		if (s[i] - 'a' != last) {
			a[i - 1] = 1;
		}
		last = s[i] - 'a';
	}
	if (last == 0) a[n - 1] = 1;
	for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << '\n';  
}