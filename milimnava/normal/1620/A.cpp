#include <bits/stdc++.h>
using namespace std;

char c[55];

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		scanf("%s", c + 1);
		int n = strlen(c + 1), cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (c[i] == 'N');
		if (cnt == 1) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
	return 0;
}