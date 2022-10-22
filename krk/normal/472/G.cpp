#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int Maxn = 200005;
const int Maxb = 64;
const int Maxp = 448;

char A[Maxn], B[Maxn];
int alen, blen;
ull abits[Maxn], bbits[Maxn];
short has[Maxp][Maxn];
int q;

int goTriv(int &a, int &b, int len)
{
	int res = 0;
	while (len >= Maxb) { 
		res += __builtin_popcountll(abits[a] ^ bbits[b]);
		a += Maxb; b += Maxb; len -= Maxb;
	}
	while (len) {
		res += A[a] != B[b];
		a++; b++; len--;
	}
	return res;
}

int main()
{
	scanf("%s", A); alen = strlen(A);
	scanf("%s", B); blen = strlen(B);
	for (int i = alen - 1; i >= 0; i--)
		abits[i] = (ull(A[i] == '1') << Maxb - 1) | (abits[i + 1] >> 1);
	for (int i = blen - 1; i >= 0; i--)
		bbits[i] = (ull(B[i] == '1') << Maxb - 1) | (bbits[i + 1] >> 1);
	for (int i = 0, p = 0; p < alen; i++, p += Maxp) {
		int lim = min(alen, p + Maxp);
		for (int j = 0; j < blen; j++)
			for (int a = p, b = j; a < lim && b < blen; a += Maxb, b += Maxb)
				has[i][j] += __builtin_popcountll(abits[a] ^ bbits[b]);
	}
	scanf("%d", &q);
	while (q--) {
		int p1, p2, len; scanf("%d %d %d", &p1, &p2, &len);
		int need = (Maxp - p1 + p1 / Maxp * Maxp) % Maxp;
		int togo = min(len, need);
		int res = goTriv(p1, p2, togo); len -= togo;
		int bl = p1 / Maxp;
		while (len >= Maxp) {
			res += has[bl][p2];
			bl++; p1 += Maxp; p2 += Maxp; len -= Maxp;
		}
		res += goTriv(p1, p2, len);
		printf("%d\n", res);
	}
	return 0;
}