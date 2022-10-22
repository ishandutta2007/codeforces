#include <bits/stdc++.h>

using namespace std;
int T, n;
int cnt[26];
void work() {
	memset(cnt, 0, sizeof(cnt));
	string s;
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	sort(s.begin(), s.end());
	for(int i = 0; i < n; i++) {
		if(cnt[s[i] - 'a'] == 1) {
			cout << s[i];
			s.erase(s.begin() + i);
			cout << s << endl;
			return;
		}
	}
	string a, b, c;
	int now = 0, only = -1;
	a += s[0];
	for(int i = 1; i < n; i++) {
		if(s[i - 1] != s[i]) {
			now++;
		}
		if(now == 0) a += s[i];
		if(now == 1) b += s[i];
		if(now >= 2) c += s[i];
	}
	if(a.length() == n) {
		cout << a << endl;
		return;
	}
	if(a.length() == 1) {
		cout << a + b + c << endl;
		return;
	}
	if(a.length() - 1 <= b.length() + c.length() + 1) {
		b += c;
		string t;
		t += a[0];
		t += a[0];
		a.pop_back(), a.pop_back();
		reverse(b.begin(), b.end());
		for(int i = 2; i < n; i++) {
			if(t.back() != t[0] && !a.empty()) {
				t.push_back(t[0]);
				a.pop_back();
			} else {
				t.push_back(b.back());
				b.pop_back();
			}
		}
		cout << t << endl;
	} else {
		a.pop_back();
		if(c.length() == 0) {
			cout << a[0] + b + a << endl;
		} else {
			cout << a[0] << b[0] << a << c[0];
			b.pop_back();
			cout << b;
			c.erase(c.begin(), c.begin() + 1);
			cout << c << endl;
		}
	}
	return;
}

int main() {
	cin >> T;
	for(; T--; ) work();
	return 0;
}