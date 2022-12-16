#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 5e5 + 10;
int T,n,a[maxn];
int c[maxn];
void upd(int pos, int val) {
	for (; pos <= n; pos += pos & (-pos)) c[pos] += val;
}
int ask(int pos) {
	int ret = 0;
	for (; pos; pos &= pos - 1) ret += c[pos];
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		ll v = 0;
		bool flag = 0;
		for (int i = n; i >= 1; --i) v += ask(a[i] - 1), flag |= (ask(a[i]) - ask(a[i] - 1) > 0), upd(a[i], 1);
		if (flag || v % 2 == 0) printf("YES\n");
		else printf("NO\n");
		for (int i = 1; i <= n; ++i) upd(a[i], -1);
	}
	return 0;
}