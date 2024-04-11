#include <bits/stdc++.h>

const int N = 110;
using namespace std;
int n;
string a[N];

int main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> a[i]; }
	sort(a + 1, a + n + 1, [](string a, string b) { return a.length() < b.length(); });
	auto check = [&](string a, string b) {
		for (int i = 0; i <= a.size() - b.size(); i++) {
			bool fl = true;
			for (int j = 0; j < b.size() && fl; j++) { fl &= a[i + j] == b[j]; }
			if (fl) { return true; }
		}
		return false;
	};
	for (int i = 1; i < n; i++) {
		if (!check(a[i + 1], a[i])) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) { cout << a[i] << endl; }
}