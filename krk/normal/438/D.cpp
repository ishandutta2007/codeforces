#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;

int n, m;
int A[Maxn];
ll sum[Maxm];
ii mx[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) { mx[v] = ii(A[l], l); sum[v] = A[l]; }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		sum[v] = sum[2 * v] + sum[2 * v + 1];
		mx[v] = mx[2 * v] > mx[2 * v + 1]? mx[2 * v]: mx[2 * v + 1];
	}
}

ll getSum(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		ll res = 0ll;
		int m = l + r >> 1;
		if (a <= m) res += getSum(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += getSum(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

ii getMax(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mx[v];
	else {
		ii mx = ii(0, 0), cand;
		int m = l + r >> 1;
		if (a <= m) { 
			cand = getMax(2 * v, l, m, a, min(m, b));
			if (cand > mx) mx = cand;
		}
		if (m + 1 <= b) {
			cand = getMax(2 * v + 1, m + 1, r, max(m + 1, a), b);
			if (cand > mx) mx = cand;
		}
		return mx;
	}
}

void Update(int v, int l, int r, int x, int val)
{
	if (l == r) { sum[v] = val; mx[v] = ii(val, l); A[l] = val; }
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		sum[v] = sum[2 * v] + sum[2 * v + 1];
		mx[v] = mx[2 * v] > mx[2 * v + 1]? mx[2 * v]: mx[2 * v + 1];
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	Create(1, 1, n);
	int typ, a, b, c;
	while (m--) {
		scanf("%d %d %d", &typ, &a, &b);
		if (typ == 1) printf("%I64d\n", getSum(1, 1, n, a, b));
		else if (typ == 2) {
			scanf("%d", &c);
			ii el = getMax(1, 1, n, a, b);
			while (el.first >= c) {
				Update(1, 1, n, el.second, el.first % c);
				el = getMax(1, 1, n, a, b);
			}
		} else Update(1, 1, n, a, b);
	}
	return 0;
}