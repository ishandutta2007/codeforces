#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,d,a[maxn],ans;
multiset <int> seg,pos;

void work() {
	pos.clear(), seg.clear();
	scanf("%d%d", &n, &d);
	pos.insert(0);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pos.insert(a[i]), seg.insert(a[i] - a[i - 1] - 1);
	ans = *seg.begin();
	for (int i = 1; i <= n; ++i) {
		pos.erase(pos.find(a[i]));
		seg.erase(seg.find(a[i] - a[i - 1] - 1));
		if (i < n) seg.erase(seg.find(a[i + 1] - a[i] - 1)), seg.insert(a[i + 1] - a[i - 1] - 1);
		ans = max(ans, min(*seg.begin(), ((*--seg.end()) - 1) / 2));
		if (pos.find(d) == pos.end()) ans = max(ans, min(*seg.begin(), d - (*--pos.end()) - 1));
		pos.insert(a[i]);
		seg.insert(a[i] - a[i - 1] - 1);
		if (i < n) seg.insert(a[i + 1] - a[i] - 1), seg.erase(seg.find(a[i + 1] - a[i - 1] - 1));
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}