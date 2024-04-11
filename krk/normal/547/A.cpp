#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int m;
int h1, a1;
int x1, y1;
int h2, a2;
int x2, y2;

int has[Maxn], has2[Maxn];

int getNext(int x1, int h1, int y1, int tim = 1)
{
	while (tim--)
		h1 = (ll(x1) * h1 + y1) % m;
	return h1;
}

int Get(int x1, int h1, int y1, int a1, int &b1, int &p1)
{
	fill(has, has + Maxn, -1);
	int t = 0;
	while (h1 != a1 && has[h1] == -1) {
		has[h1] = t++;
		h1 = getNext(x1, h1, y1);
	}
	if (h1 != a1) return 0;
	b1 = t;
	fill(has, has + Maxn, -1);
	t = 0;
	while (has[h1] == -1) {
		has[h1] = t++;
		h1 = getNext(x1, h1, y1);
	}
	if (h1 != a1) return 1;
	p1 = t - has[a1];
	return 2;
}

int main()
{
	scanf("%d", &m);
	scanf("%d %d", &h1, &a1);
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &h2, &a2);
	scanf("%d %d", &x2, &y2);
	int b1, p1; int st1 = Get(x1, h1, y1, a1, b1, p1);
	int b2, p2; int st2 = Get(x2, h2, y2, a2, b2, p2);
	if (st1 == 0 || st2 == 0) printf("-1\n");
	else if (st1 == 1) {
		h1 = getNext(x1, h1, y1, b1);
		h2 = getNext(x2, h2, y2, b1);
		printf("%d\n", h1 == a1 && h2 == a2? b1: -1);
	} else if (st2 == 1) {
		h1 = getNext(x1, h1, y1, b2);
		h2 = getNext(x2, h2, y2, b2);
		printf("%d\n", h1 == a1 && h2 == a2? b2: -1);
	} else {
		fill(has, has + Maxn, -1);
		ll res = b1;
		int cur = getNext(x2, h2, y2, b1);
		int my = getNext(x2, cur, y2, p1);
		while (has[cur] == -1) {
			has[cur] = my;
			cur = getNext(x2, cur, y2);
			my = getNext(x2, my, y2);
		}
		fill(has2, has2 + Maxn, -1);
		cur = getNext(x2, h2, y2, b1);
		while (cur != a2 && has2[cur] == -1) {
			has2[cur] = 1;
			res += p1; cur = has[cur];
		}
		printf("%I64d\n", cur == a2? res: -1ll);
	}
	return 0;
}