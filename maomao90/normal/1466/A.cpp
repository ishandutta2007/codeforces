#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int x[55];
set<int> st;

int main() {
	scanf("%d", &t);
	while (t--) {
		st.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				st.insert(x[j] - x[i]);
			}
		}
		printf("%d\n", st.size());
	}
	return 0;
}