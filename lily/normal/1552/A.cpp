#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >>  T;
	while (T--) {
		string s, t;
		int n;
		cin >> n;
		cin >> s;
		t = s;
		sort(t.begin(), t.end());
		int cnt = 0;
		for (int i = 0; i < t.size(); i++) {
			cnt += s[i] != t[i];
		}
		cout << cnt << endl;
	}
}