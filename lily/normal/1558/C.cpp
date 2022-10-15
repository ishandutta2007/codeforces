#include <bits/stdc++.h>
using namespace std;
const int N = 2055;

int n;
int a[N];


int pos(int x) {
	for (int i = 1; i <= n; i++) if (a[i] == x) return i;
	return -1;
}
void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) if ( i % 2 != a[i] % 2) {
		puts("-1");
		return;
	}
	vector <int> ans;
	for ( ; n > 1; n -= 2) {
		int p1 = pos(n);
		reverse(a + 1, a + p1 + 1);
		ans.push_back(p1);
		int p2 = pos(n - 1);
		if (p2 > 2)	{
			reverse(a + 1, a + (p2 - 1) + 1), ans.push_back(p2 - 1);
			reverse(a + 1, a + (p2 + 1) + 1), ans.push_back(p2 + 1);
			reverse(a + 1, a + 4); ans.push_back(3);
		}
		reverse(a + 1, a + n + 1);
		ans.push_back(n);
	}
	printf("%d\n", (int)ans.size());
	for (auto i : ans) printf("%d ", i);
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}