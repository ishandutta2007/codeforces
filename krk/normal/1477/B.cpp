#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;

char tmp[Maxn];
int T;
int n, q;
string A;
string B;
int L[Maxn], R[Maxn];
int fl[Maxm], cnt[Maxm];

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

void downOn(int v, int sz, int val)
{
	fl[v] = val;
	if (val == 0) cnt[v] = 0;
	else cnt[v] = sz;
}

void Down(int v, int l, int m, int r)
{
	if (fl[v] != -1) {
		downOn(2 * v, m + 1 - l, fl[v]);
		downOn(2 * v + 1, r - m, fl[v]);
		fl[v] = -1;
	}
}

void Union(int v)
{
	cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
}

void Create(int v, int l, int r)
{
	fl[v] = -1;
	if (l == r) cnt[v] = B[l] - '0';
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) downOn(v, r - l + 1, val);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

int Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return cnt[v];
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		int res = 0;
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

bool Solve()
{
	for (int i = q - 1; i >= 0; i--) {
		int ones = Get(1, 0, n - 1, L[i], R[i]);
		int zers = R[i] - L[i] + 1 - ones;
		if (ones > zers) Update(1, 0, n - 1, L[i], R[i], 1);
		else if (ones < zers) Update(1, 0, n - 1, L[i], R[i], 0);
		else return false;
	}
	for (int i = 0; i < n; i++)
		if (Get(1, 0, n - 1, i, i) != A[i] - '0')
			return false;
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &q);
		Read(A);
		Read(B);
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &L[i], &R[i]);
			L[i]--; R[i]--;
		}
		Create(1, 0, n - 1);
		printf("%s\n", Solve()? "YES": "NO");
	}
    return 0;
}