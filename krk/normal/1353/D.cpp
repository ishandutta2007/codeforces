#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxn = 200005;

int T;
int n;
int res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		priority_queue <iiii> Q;
		scanf("%d", &n);
		Q.push(iiii(ii(n, 0), ii(0, n - 1)));
		for (int i = 1; i <= n; i++) {
			ii p = Q.top().second; Q.pop();
			int m = p.first + p.second >> 1;
			res[m] = i;
			if (p.first < m) {
				ii u = ii(p.first, m - 1);
				Q.push(iiii(ii((u.second - u.first + 1), -u.first), u));
			}
			if (m < p.second) {
				ii u = ii(m + 1, p.second);
				Q.push(iiii(ii((u.second - u.first + 1), -u.first), u));
			}
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}