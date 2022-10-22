#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, q;
int par[Maxn], siz[Maxn];
int P[Maxn], S[Maxn];
int nxt[Maxn];

int getP(int x) { return P[x] == x? x: P[x] = getP(P[x]); }

void unionNxt(int a, int b)
{
	a = getP(a), b = getP(b);
	if (a == b) return;
	if (S[a] >= S[b]) { S[a] += S[b]; P[b] = a; nxt[a] = max(nxt[a], nxt[b]); }
	else { S[b] += S[a]; P[a] = b; nxt[b] = max(nxt[b], nxt[a]); }
}

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		par[i] = i; siz[i] = 1;
		P[i] = nxt[i] = i; S[i] = 1;
	}
	while (q--) {
		int typ, x, y; scanf("%d %d %d", &typ, &x, &y);
		if (typ == 1) unionSet(x, y);
		else if (typ == 2)
			while (nxt[getP(x)] < y) {
				unionSet(x, nxt[getP(x)] + 1);
				unionNxt(x, nxt[getP(x)] + 1);
			}
		else printf("%s\n", getPar(x) == getPar(y)? "YES": "NO");
	}
	return 0;
}