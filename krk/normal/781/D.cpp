#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int Maxb = 61;
const int Maxp = 9;
const ll Inf = 1000000000000000000ll;

int n, m;
ll A[Maxb][Maxn][Maxp], B[Maxb][Maxn][Maxp];
ll IA[Maxb][Maxn][Maxp], IB[Maxb][Maxn][Maxp];
ll myA[Maxn][Maxp], myB[Maxn][Maxp];
ll newA[Maxn][Maxp], newB[Maxn][Maxp];
ll res;

void Add(ll A[], ll B[], int a, int b)
{
	int ind = b / Maxb;
	A[ind] |= 1ll << ll(b % Maxb);
	ind = a / Maxb;
	B[ind] |= 1ll << ll(a % Maxb);
}

bool Check(ll A[], ll B[])
{
	for (int i = 0; i < Maxp; i++)
		if (A[i] & B[i]) return true;
	return false;
}

void Join(ll A[][Maxp], ll B[][Maxp], ll C[][Maxp], ll D[][Maxp])
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Check(A[i], B[j])) Add(C[i], D[j], i, j);
}

bool Empty(ll A[][Maxp])
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < Maxp; j++)
			if (A[i][j]) return false;
	return true;
}

void Copy(ll A[][Maxp], ll B[][Maxp])
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < Maxp; j++)
			A[i][j] = B[i][j];
}

void Clear(ll A[][Maxp])
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < Maxp; j++)
			A[i][j] = 0;
}

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u, t; scanf("%d %d %d", &v, &u, &t);
		if (t == 0) Add(A[0][v], B[0][u], v, u);
		else if (t == 1) Add(IA[0][v], IB[0][u], v, u);
	}
	for (int i = 0; i + 1 < Maxb; i++) {
		Join(A[i], IB[i], A[i + 1], B[i + 1]);
		Join(IA[i], B[i], IA[i + 1], IB[i + 1]);
	}
	int p = Maxb - 1;
	while (p >= 0 && Empty(A[p])) p--;
	if (p == Maxb - 1) { printf("-1\n"); return 0; }
	if (p < 0) { printf("0\n"); return 0; }
	Copy(myA, A[p]); Copy(myB, B[p]); res += 1ll << ll(p);
	bool inv = true;
	for (int i = p - 1; i >= 0; i--)
		if (inv) {
			Join(myA, IB[i], newA, newB);
			if (!Empty(newA)) {
				Copy(myA, newA); Copy(myB, newB); res += 1ll << ll(i);
				Clear(newA); Clear(newB);
				inv = false;
			}
		} else {
			Join(myA, B[i], newA, newB);
			if (!Empty(newA)) {
				Copy(myA, newA); Copy(myB, newB); res += 1ll << ll(i);
				Clear(newA); Clear(newB);
				inv = true;
			}
		}
	if (res > Inf) printf("-1\n");
	else printf("%I64d\n", res);
    return 0;
}