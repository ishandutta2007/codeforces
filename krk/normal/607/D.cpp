#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;
const int Maxm = 1048576;

int n, q;
int val[Maxn];
int a[Maxn], b[Maxn], c[Maxn];
vector <int> neigh[Maxn];
int ch[Maxn];
int P[Maxn], cur, L[Maxn], R[Maxn];
int mult[Maxm];
int fl[Maxm], sum[Maxm];

void Traverse(int v)
{
	L[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
	R[v] = cur;
}

void createMult(int v, int l, int r)
{
	mult[v] = 1;
	if (l < r) {
		int m = l + r >> 1;
		createMult(2 * v, l, m); createMult(2 * v + 1, m + 1, r);
	}
}

void updMult(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) mult[v] = ll(mult[v]) * val % mod;
	else {
		int m = l + r >> 1;
		if (a <= m) updMult(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) updMult(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

int getMult(int v, int l, int r, int x)
{
	int res = mult[v];
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res = ll(res) * getMult(2 * v, l, m, x) % mod;
		else res = ll(res) * getMult(2 * v + 1, m + 1, r, x) % mod;
	}
	return res;
}

void Union(int v)
{
	sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
}

void downOn(int v, int val)
{
	fl[v] = ll(fl[v]) * val % mod;
	sum[v] = ll(sum[v]) * val % mod;
}

void Down(int v)
{
	if (fl[v] != 1) {
		downOn(2 * v, fl[v]); downOn(2 * v + 1, fl[v]);
		fl[v] = 1;
	}
}

void createSum(int v, int l, int r)
{
	fl[v] = 1;
	if (l == r) sum[v] = val[l];
	else {
		int m = l + r >> 1;
		createSum(2 * v, l, m); createSum(2 * v + 1, m + 1, r);
		Union(v);
	}
}

int getSum(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		Down(v);
		int m = l + r >> 1;
		int res = 0;
		if (a <= m) res = (res + getSum(2 * v, l, m, a, min(m, b))) % mod;
		if (m + 1 <= b) res = (res + getSum(2 * v + 1, m + 1, r, max(m + 1, a), b)) % mod;
		return res;
	}
}

void multSum(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) downOn(v, val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) multSum(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) multSum(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

void addSum(int v, int l, int r, int x, int val)
{
	if (l == r) sum[v] = val;
	else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) addSum(2 * v, l, m, x, val);
		else addSum(2 * v + 1, m + 1, r, x, val);
		Union(v);
	}
}

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	n = 1; scanf("%d %d", &val[n], &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a[i], &b[i]);
		if (a[i] == 1) {
			scanf("%d", &c[i]);
			n++; P[n] = b[i];
			neigh[b[i]].push_back(n);
		}
	}
	Traverse(1);
	createMult(1, 1, R[1]);
	createSum(1, 1, R[1]);
	n = 1;
	for (int i = 0; i < q; i++)
		if (a[i] == 1) {
			n++; 
			ch[b[i]]++;
			int tomult = ll(ch[b[i]] + 1) * Inv(ch[b[i]]) % mod;
			updMult(1, 1, R[1], L[b[i]], R[b[i]], tomult);
			multSum(1, 1, R[1], L[b[i]], R[b[i]], tomult);
			val[n] = c[i];
			tomult = getMult(1, 1, R[1], L[n]);
			addSum(1, 1, R[1], L[n], ll(tomult) * val[n] % mod);
		} else {
			int res = getSum(1, 1, R[1], L[b[i]], R[b[i]]);
			if (P[b[i]]) {
				int tomult = Inv(getMult(1, 1, R[1], L[P[b[i]]]));
				res = ll(res) * tomult % mod;
			}
			printf("%d\n", res);
		}
	return 0;
}