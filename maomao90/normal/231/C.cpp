#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[100005];
int maxans, maxnum;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0, r = 0;
	int curk = k, curans = 0, curnum = 0;
	while (r < n) {
		while (r < n && curk >= (long long) curans * (a[r] - curnum)) {
			curk -= curans * (a[r] - curnum);
			curans++;
			curnum = a[r++];
		}
		if (curans > maxans) {
			maxans = curans;
			maxnum = curnum;
		}
		if (l < r) {
			curk += curnum - a[l++];
			curans--;
		}
		if (curans > maxans) {
			maxans = curans;
			maxnum = curnum;
		}
	}
	printf("%d %d\n", maxans, maxnum);
	return 0;
}