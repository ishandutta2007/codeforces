#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
bool f[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> s;
	for (char c : s) f[c - 'a' + 1] = 1;
	
	int cur = 1;
	int cnt = 0;
	int res = 0;
	while (cur <= 26) {
		if (f[cur]) {
			res += cur;
			cur += 2;
			cnt++;
			if (cnt == k) return cout << res << '\n',0; 
		}
		else {
			cur++;
		}
	}
	cout << -1;
}