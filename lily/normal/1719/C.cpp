#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

int n, Q;


void work() {
	read(n); read(Q);
	vector <int> a(n + 1);
	for (int i= 1; i <= n; i++) read(a[i]);
	queue <int> q;
	vector < vector <int>> wins(n + 1);
	int cur = 1;
	for (int i = 2; i <= n; i++) q.push(i);
	for (int r = 1; r <= n; r++) {
		int x = q.front(); q.pop();
		if (a[cur] > a[x]) q.push(x), wins[cur].push_back(r);
		else q.push(cur), wins[x].push_back(r), cur = x;
	}
	while (Q--) {
		int i, k;
		read(i); read(k);
		if (k <= n) {
			printf("%d\n", int(upper_bound(wins[i].begin(), wins[i].end(), k) - wins[i].begin()));
		} else {
			printf("%d\n", (int)wins[i].size() + (cur == i ? k - n : 0));
		}
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();
}