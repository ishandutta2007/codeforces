#include <cstdio>
#include <vector>

using namespace std;

int n;
vector <int> cnt[100005];
int ans[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a].push_back(i);
	}

	for (int i = 2; i < 100005; i++) {
		if (cnt[i].size() > cnt[i - 1].size()) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i < 100005; i++) {
		for (int j = 0; j < cnt[i].size(); j++) {
			ans[cnt[i][j]] = j + 1;
		}
	}
	printf("%d\n", cnt[1].size());
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}