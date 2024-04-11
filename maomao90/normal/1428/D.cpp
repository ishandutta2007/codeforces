#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n;
int a[100005];
set <ii> prv2, prv3, prv23;
vector <ii> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int curr = n;
	for (int i = n; i > 0; i--) {
		if (a[i] == 1) {
			prv23.emplace(curr, i);
			ans.emplace_back(curr--, i);
		} else if (a[i] == 2) {
			if (prv2.empty() && prv23.empty()) {
				printf("-1\n");
				return 0;
			}
			set<ii>::iterator it;
			if (!prv2.empty()) it = prv2.begin();
			else it = prv23.begin();
			ans.emplace_back(it -> first, i);
			if (!prv2.empty()) prv2.erase(it);
			else prv23.erase(*it);
			prv3.emplace(it -> first, i);
		} else if (a[i] == 3) {
			if (prv3.empty() && prv23.empty()) {
				printf("-1\n");
				return 0;
			}
			set<ii>::iterator it;
			if (!prv3.empty()) it = prv3.begin();
			else it = prv23.begin();
			ans.emplace_back(curr, i);
			ans.emplace_back(curr, it -> second);
			if (!prv3.empty()) prv3.erase(it);
			else prv23.erase(it);
			prv3.emplace(curr--, i);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}