#include <bits/stdc++.h>
using namespace std;

int tc;
int n, k;
vector<int> a;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		a.clear(); a.resize(n);
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] % 2 == 0) even++;
			else odd++;
		}
		vector<bool> memo;
		memo.resize((odd + 2) * (even + 2) * 4 + 1, false); // alice - 1, bob - 2
		memo[0] = true;
		memo[1] = false;
		memo[2] = true;
		memo[3] = false;
		for (int i = 0; i <= odd; i++) {
			for (int j = 0; j <= even; j++) {
				if (i == 0 && j == 0) continue;
				for (int k = 0; k < 4; k++) {
					int state = i * (even + 1) * 4 + j * 4 + k;
					bool turn = (odd + even - i - j + 1) % 2;
					if (turn) { // alice
						memo[state] = false;
						if (i > 0) memo[state] = memo[state] || memo[state - (even + 1) * 4 - k + (k^1)];
						if (j > 0) memo[state] = memo[state] || memo[state - 4];
					} else {
						memo[state] = true;
						if (i > 0) memo[state] = memo[state] && memo[state - (even + 1) * 4 - k + (k^2)];
						if (j > 0) memo[state] = memo[state] && memo[state - 4];
					}
				}
			}
		}
		if (memo[(odd) * (even + 1) * 4 + even * 4]) printf("Alice\n");
		else printf("Bob\n");
		
	}
	return 0;
}