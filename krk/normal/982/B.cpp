#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int w[Maxn];
priority_queue <ii> mn, mx;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		mn.push(ii(-w[i], i));
	}
	for (int i = 1; i <= 2 * n; i++) {
		char ch; scanf(" %c", &ch);
		if (ch == '0') {
			int ind = mn.top().second; mn.pop();
			mx.push(ii(w[ind], ind));
			printf("%d%c", ind, i + 1 <= 2 * n? ' ': '\n');
		} else {
			int ind = mx.top().second; mx.pop();
			printf("%d%c", ind, i + 1 <= 2 * n? ' ': '\n');
		}
	}
	return 0;
}