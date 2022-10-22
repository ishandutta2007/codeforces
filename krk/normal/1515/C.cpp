#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n, m, x;
int h[Maxn];
int cur[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &x);
		fill(cur, cur + m + 1, 0);
		priority_queue <ii> Q;
		for (int i = 1; i <= m; i++)
			Q.push(ii(-cur[i], i));
		printf("YES\n");
		for (int i = 1; i <= n; i++) {
			int ind = Q.top().second; Q.pop();
			printf("%d%c", ind, i + 1 <= n? ' ': '\n');
			scanf("%d", &h[i]);
			cur[ind] += h[i];
			Q.push(ii(-cur[ind], ind));
		}
	}
    return 0;
}