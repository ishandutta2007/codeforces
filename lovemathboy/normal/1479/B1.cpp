#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> pre, nxt, c;

int main() {
	scanf("%d", &n);
	a.resize(n);
	c.resize(100005, -1);
	pre.resize(n+1, -1);
	nxt.resize(n+1, n+1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (c[a[i]] != -1) {
			nxt[c[a[i]]] = i;
		}
		//pre[i] = c[a[i]];
		c[a[i]] = i;
	}
	int v1 = -1;
	int v2 = -1;
	int n1 = n+1, n2 = n+1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v1 == a[i] && v2 == a[i]) {
			n1 = nxt[i];
			n2 = nxt[i];
			continue;
		}
		else if (v1 == a[i]) {
			v2 = a[i];
			n2 = nxt[i];
			ans++;
		}
		else if (v2 == a[i]) {
			v1 = a[i];
			n1 = nxt[i];
			ans++;
		}
		else if (n1 < n2) {
			v1 = a[i];
			n1 = nxt[i];
			ans++;
		}
		else {
			v2 = a[i];
			n2 = nxt[i];
			ans++;
		}
	}
	//for (int i = 0; i < n; i++) printf("%d ", nxt[i]);
	printf("%d\n", ans);
	return 0;
}