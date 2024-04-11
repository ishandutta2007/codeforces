#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

int n;
void work() {
	read(n);
	set <int> w;
	int cur = 0, ans = 0;
	w.insert (0);
	for (int i = 1; i <= n; i++) {
		int x;
		read(x);
		cur ^= x;
		if (w.count(cur)) {
			w.clear();
		}
		else {
			ans ++;
		}
		w.insert (cur);
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}