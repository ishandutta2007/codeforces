#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> ans;
bool has[105];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (!has[a]) {
			ans.push_back(i + 1);
			has[a] = true;
		}
	}
	if (ans.size() < k) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 0; i < k; i++) printf("%d ", ans[i]);
	}
	return 0;
}