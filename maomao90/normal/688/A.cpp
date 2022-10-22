#include <bits/stdc++.h>
using namespace std;

int n, d;
int cur, ans;

int main() {
	scanf("%d%d", &n, &d);
	for (int i = 0; i < d; i++) {
		bool isPossible = false;
		for (int j = 0; j < n; j++) {
			char a; scanf(" %c", &a);
			if (a == '0') isPossible = true;
		}
		if (isPossible) cur++;
		else cur = 0;
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}