#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 1e5 + 5;

int n, m, x, a[N];

typedef pair<int, int> PII;

priority_queue<PII, vector<PII>, greater<PII> > q;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		read(n); read(m); read(x);
		for (int i = 1; i <= n; i++) read(a[i]);
		puts("YES");
		while (q.size()) q.pop();
		for (int i = 1; i <= m; i++) q.push(mp(0, i));
		for (int i = 1; i <= n; i++) {
			PII u = q.top(); q.pop();
			printf("%d ", u.second);
			q.push(mp(u.first + a[i], u.second));
		}
		puts("");
	}
	return 0;
}