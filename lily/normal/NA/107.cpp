#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

	string s;
	int n;
void check() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i ] != s[n - i - 1]) return;
	}
	cout << "YES";
	exit(0);
}

int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		char x = s[i];
		 s[i] = s[n - i - 1];
		if (x != s[n - i - 1] || i + i + 1 == n)check();
		s[i] = x;
	}
	cout << "NO";

}