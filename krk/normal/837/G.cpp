#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 16777216;
const int mod = 1000000000;

int n;
int slen;
int L[Maxm], R[Maxm];
ll A[Maxm], B[Maxm];
int my[Maxn];

void createNew()
{
	L[slen] = R[slen] = -1;
	A[slen] = B[slen] = 0; 
	slen++;
}

int getLst() { return slen - 1; }

void Create(int v, int l, int r) 
{
	if (l < r) {
		int m = l + r >> 1;
		createNew(); L[v] = getLst(); Create(L[v], l, m);
		createNew(); R[v] = getLst(); Create(R[v], m + 1, r);
	}
}

void Insert(int v1, int v2, int l, int r, int a, int b, int valA, int valB)
{
	A[v1] = A[v2]; B[v1] = B[v2];
	L[v1] = L[v2]; R[v1] = R[v2];
	if (l == a && r == b) A[v1] += valA, B[v1] += valB;
	else {
		int m = l + r >> 1;
		if (b <= m) {
			createNew(); L[v1] = getLst();
			Insert(L[v1], L[v2], l, m, a, b, valA, valB);
		} else if (m + 1 <= a) {
			createNew(); R[v1] = getLst();
			Insert(R[v1], R[v2], m + 1, r, a, b, valA, valB);
		} else {
			createNew(); L[v1] = getLst();
			createNew(); R[v1] = getLst();
			Insert(L[v1], L[v2], l, m, a, m, valA, valB);
			Insert(R[v1], R[v2], m + 1, r, m + 1, b, valA + valB * (m + 1 - a), valB);
		}
	}
}

ll Get(int v, int l, int r, int x)
{
	ll res = A[v] + B[v] * (x - l);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res += Get(L[v], l, m, x);
		else res += Get(R[v], m + 1, r, x);
	}
	return res;
}

int main()
{
	createNew(); my[0] = getLst();
	Create(my[0], 0, Maxn - 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		createNew(); int v1 = getLst();
		int x1, x2, y1, a, b, y2; scanf("%d %d %d %d %d %d", &x1, &x2, &y1, &a, &b, &y2);
		Insert(v1, my[i - 1], 0, Maxn - 1, 0, x1, y1, 0);
		createNew(); int v2 = getLst();
		Insert(v2, v1, 0, Maxn - 1, x1 + 1, x2, a * (x1 + 1) + b, a);
		createNew(); int v3 = getLst();
		Insert(v3, v2, 0, Maxn - 1, x2 + 1, Maxn - 1, y2, 0);
		my[i] = v3;
	}
	int lst = 0;
	int m; scanf("%d", &m);
	while (m--) {
		int l, r, x; scanf("%d %d %d", &l, &r, &x);
		x = (x + lst) % mod;
		x = min(x, Maxn - 1); 
		ll res = Get(my[r], 0, Maxn - 1, x) - Get(my[l - 1], 0, Maxn - 1, x);
		printf("%I64d\n", res);
		lst = res % mod;
	}
	return 0;
}