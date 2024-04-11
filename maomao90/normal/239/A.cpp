#include <cstdio>
#include <vector>

using namespace std;

int y, k, n;
vector <int> ans;

int main() {
	scanf("%d%d%d", &y, &k, &n);
	for (int i = k - (y % k); i <= n; i += k) {
		if (i + y <= n && (i + y) % k == 0) {
            ans.push_back(i);
		}
	}
	if (ans.empty()) {
        printf("-1\n");
	} else {
        for (int i : ans) {
            printf("%d ", i);
        }
        printf("\n");
	}
	return 0;
}