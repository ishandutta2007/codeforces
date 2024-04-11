#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;
const int Maxb = 20;

struct node {
	int mask;
	int hm[Maxb][2];
	ll sum;
	node(int mask = 0, ll sum = 0ll): mask(mask), sum(sum) { fill((int*)hm, (int*)hm + Maxb * 2, 0); }
};

int n, a[Maxn];
node st[Maxm];
int m;

void Create(int v, int l, int r)
{
	if (l == r) {
		for (int i = 0; i < Maxb; i++)
			if (a[l] & 1 << i) { st[v].hm[i][1] = 1; st[v].sum += 1 << i; }
			else st[v].hm[i][0] = 1;
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		for (int i = 0; i < Maxb; i++) {
			st[v].hm[i][0] = st[2 * v].hm[i][0] + st[2 * v + 1].hm[i][0];
			st[v].hm[i][1] = st[2 * v].hm[i][1] + st[2 * v + 1].hm[i][1];
			st[v].sum += ll(st[v].hm[i][1]) * ll(1 << i);
		}
	}
}

void Down(int v, bool lst)
{
	if (!lst) { st[2 * v].mask ^= st[v].mask; st[2 * v + 1].mask ^= st[v].mask; }
	st[v].sum = 0ll;
	for (int i = 0; i < Maxb; i++) {
		if (st[v].mask & 1 << i) swap(st[v].hm[i][0], st[v].hm[i][1]);
		st[v].sum += ll(st[v].hm[i][1]) * ll(1 << i);
	}
	st[v].mask = 0;
}

ll getSum(int v, int l, int r, int a, int b)
{
	Down(v, l == r);
	if (a == l && b == r) return st[v].sum;
	else {
		ll res = 0ll;
		int m = l + r >> 1;
		if (a <= m) res += getSum(2 * v, l, m, a, min(m, b));
		else Down(2 * v, l == m);
		if (m + 1 <= b) res += getSum(2 * v + 1, m + 1, r, max(m + 1, a), b);
		else Down(2 * v + 1, m + 1 == r);
		st[v].sum = 0ll;
		for (int i = 0; i < Maxb; i++) {
			st[v].hm[i][0] = st[2 * v].hm[i][0] + st[2 * v + 1].hm[i][0];
			st[v].hm[i][1] = st[2 * v].hm[i][1] + st[2 * v + 1].hm[i][1];
			st[v].sum += ll(st[v].hm[i][1]) * ll(1 << i);
		}
		return res;
	}
}

void Update(int v, int l, int r, int a, int b, int x)
{
	if (a == l && b == r) {
		st[v].mask ^= x;
		Down(v, l == r);
	} else {
		Down(v, l == r);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), x);
		else Down(2 * v, l == m);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
		else Down(2 * v + 1, m + 1 == r);
		st[v].sum = 0ll;
		for (int i = 0; i < Maxb; i++) {
			st[v].hm[i][0] = st[2 * v].hm[i][0] + st[2 * v + 1].hm[i][0];
			st[v].hm[i][1] = st[2 * v].hm[i][1] + st[2 * v + 1].hm[i][1];
			st[v].sum += ll(st[v].hm[i][1]) * ll(1 << i);
		} 
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		int t, l, r, x; scanf("%d %d %d", &t, &l, &r);
		if (t == 1) printf("%I64d\n", getSum(1, 1, n, l, r));
		else { scanf("%d", &x); Update(1, 1, n, l, r, x); }
	}
	return 0;
}