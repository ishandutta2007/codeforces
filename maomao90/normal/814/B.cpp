#include <cstdio>
#include <vector>

using namespace std;

int n;
int a[1005], b[1005];
bool used[1005];
vector <int> diff, pos;
bool afirst;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) diff.push_back(i);
		else used[a[i]] = true;
	}
	for (int i = 1; i <= n; i++) if (!used[i]) pos.push_back(i);
	if (diff.size() == 1) {
		for (int i = 0; i < n; i++) {
			if (i != diff[0]) printf("%d ", a[i]);
			else {
				for (int j : pos) {
					if (j != a[i] && j != b[i]) {
						printf("%d ", j);
						break;
					}
				}
			}
		}
	} else {
	    if (!used[a[diff[0]]] && !used[b[diff[1]]] && a[diff[0]] != b[diff[1]]) afirst = true;
		for (int i = 0; i < n; i++) {
			if (i != diff[0] && i != diff[1]) printf("%d ", a[i]);
			else if ((i == diff[0] && afirst) || (i == diff[1] && !afirst)) printf("%d ", a[i]);
			else printf("%d ", b[i]);
		}
	}
	printf("\n");
	return 0;
}