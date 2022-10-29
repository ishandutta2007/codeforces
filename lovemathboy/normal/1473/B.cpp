#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char s1[30], s2[30];
		scanf("%s\n%s", s1, s2);
		int n1 = 0, n2 = 0;
		for (; s1[n1] != '\0'; n1++);
		for (; s2[n2] != '\0'; n2++);
		int sz = (n1 * n2) / gcd(n1, n2);
		vector<char> ans;
		for (int i = 0; i < sz/n1; i++) {
			for (int j = 0; j < n1; j++) {
				ans.push_back(s1[j]);
			}
		}
		bool valid = true;
		for (int i = 0; i < sz; i++) {
			if (ans[i] != s2[i%n2]) {
				valid = false;
				break;
			}
		}
		if (valid) {
			for (int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}