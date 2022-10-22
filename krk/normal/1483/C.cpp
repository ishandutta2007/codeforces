#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxm = 2097152;
const ll Inf = 1000000000000000000ll;

int n;
int H[Maxn];
int B[Maxn];
int L[Maxn], R[Maxn];
ll fl[Maxm];
ll mx[Maxm];
vector <int> S;

void downOn(int v, ll val)
{
	fl[v] = max(fl[v], val);
	mx[v] = max(mx[v], val);
}

void Down(int v)
{
	if (fl[v] > -Inf) {
		downOn(2 * v, fl[v]);
		downOn(2 * v + 1, fl[v]);
		fl[v] = -Inf;
	}
}

void Union(int v)
{
	mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

void Create(int v, int l, int r)
{
	fl[v] = mx[v] = -Inf;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
	}
}

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mx[v];
	else {
		Down(v);
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

void Insert(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(v, val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Insert(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Insert(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &H[i]);
		while (!S.empty() && H[S.back()] > H[i]) {
			R[S.back()] = i - 1;
			S.pop_back();
		}
		L[i] = S.empty()? 0: S.back() + 1;
		S.push_back(i);
	}
	while (!S.empty()) {
		R[S.back()] = n - 1;
		S.pop_back();
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);
	Create(1, 0, n);
	Insert(1, 0, n, 0, 0, 0);
	for (int i = 0; i < n; i++) {
		ll got = Get(1, 0, n, L[i], i);
		Insert(1, 0, n, i + 1, R[i] + 1, got + B[i]);
	}
	printf("%I64d\n", Get(1, 0, n, n, n));
    return 0;
}