#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, q;
int BIT[Maxn];
int val[Maxn];
int L, R;
bool inv;

void Add(int x, int val)
{
	for (int i = x + 1; i < Maxn; i += i & -i)
		BIT[i] += val;
}

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int Get(int l, int r) { return Get(r) - Get(l); }

void foldLeft(int p)
{
	int off = 2 * L + 2 * p - 1;
	for (int i = L; i < L + p; i++) {
		val[off - i] += val[i]; Add(off - i, val[i]);
	}
	L += p;
}

void foldRight(int p)
{
	int off = 2 * R - 2 * p - 1;
	for (int i = R - p; i < R; i++) {
		val[off - i] += val[i]; Add(off - i, val[i]);
	}
	R -= p;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		val[i] = 1; Add(i, 1);
	}
	L = 0; R = n;
	inv = false;
	while (q--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int p; scanf("%d", &p);
			int len = R - L;
			if (!inv)
				if (p < len - p) foldLeft(p);
				else { foldRight(len - p); inv = true; }
			else if (p < len - p) foldRight(p);
				 else { foldLeft(len - p); inv = false; }
		} else {
			int l, r; scanf("%d %d", &l, &r);
			if (!inv) { l += L; r += L; }
			else { l = R - l; r = R - r; swap(l, r); }
			printf("%d\n", Get(l, r));
		}
	}
	return 0;
}