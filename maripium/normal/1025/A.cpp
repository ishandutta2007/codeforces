#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	if (n == 1) return cout << "YES\n",0;
	for (char c : s) {
		cnt[c - 'a']++;
		if (cnt[c - 'a'] >= 2) return cout << "YES\n",0;
	}
	cout << "NO";
}