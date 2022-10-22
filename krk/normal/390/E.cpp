#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 8388608;

struct node {
	ll sum, flag;
	node(ll sum = 0ll, ll flag = 0ll): sum(sum), flag(flag) {}
};

int n, m, w;
node st[2][Maxm];

void Down(int t, int v, int l, int m, int r)
{
	if (st[t][v].flag) {
		st[t][2 * v].sum += st[t][v].flag * (m - l + 1); st[t][2 * v].flag += st[t][v].flag;
		st[t][2 * v + 1].sum += st[t][v].flag * (r - m); st[t][2 * v + 1].flag += st[t][v].flag;
		st[t][v].flag = 0;
	}
}

void Update(int t, int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) { st[t][v].sum += val * (r - l + 1); st[t][v].flag += val; }
	else {
		int m = l + r >> 1;
		Down(t, v, l, m, r);
		if (a <= m) Update(t, 2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		st[t][v].sum = st[t][2 * v].sum + st[t][2 * v + 1].sum;
	}
}

ll Get(int t, int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[t][v].sum;
	else {
		int m = l + r >> 1;
		Down(t, v, l, m, r);
		ll res = 0ll;
		if (a <= m) res += Get(t, 2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i < w; i++) {
		int typ, X1, Y1, X2, Y2, val;
		scanf("%d %d %d %d %d", &typ, &X1, &Y1, &X2, &Y2);
		if (typ == 0) {
			scanf("%d", &val);
			Update(0, 1, 0, n, X1, X2, ll(Y2 - Y1 + 1) * val);
			Update(1, 1, 0, m, Y1, Y2, ll(X2 - X1 + 1) * val);
		} else {
			ll res = -Get(1, 1, 0, m, 0, Y1 - 1) + Get(1, 1, 0, m, 0, Y2) - Get(1, 1, 0, m, 0, m) + Get(0, 1, 0, n, X1, X2);
			printf("%I64d\n", res);
		}
	}
	return 0;
}