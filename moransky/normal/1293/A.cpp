#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
set<int> st;
int n, s, k;
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		st.clear();
		scanf("%d%d%d", &n, &s, &k);
		for (int i = 1; i <= k; i++) {
			int x; scanf("%d", &x);
			st.insert(x);
		}

		int t = min(n, s + k), ans = 2e9;
		for (int i = max(1, s - k); i <= t; i++) {
			if (!st.count(i)) ans = min(ans, abs(s - i));
		}
		printf("%d\n", ans);
	}
	return 0;
}