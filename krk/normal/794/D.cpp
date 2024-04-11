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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 1000007;
const int arg2 = 1000003;
const int Maxn = 300005;

int pw1[Maxn], pw2[Maxn];
ii h[Maxn];
int n, m;
int A[Maxn], B[Maxn];
int par[Maxn], siz[Maxn];
vector <int> neigh[Maxn];
set <ii> S;
int res[Maxn];

void Add(int v, int u)
{
	h[v].first = (ll(h[v].first) + ll(u) * pw1[u]) % mod1;
	h[v].second = (ll(h[v].second) + ll(u) * pw2[u]) % mod2;
}

void Rem(int v, int u)
{
	h[v].first = (ll(h[v].first) - ll(u) * pw1[u] % mod1 + mod1) % mod1;
	h[v].second = (ll(h[v].second) - ll(u) * pw2[u] % mod2 + mod2) % mod2;
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
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
		pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &A[i], &B[i]);
		Add(A[i], B[i]); Add(B[i], A[i]);
	}
	for (int i = 0; i < m; i++) {
		Rem(A[i], B[i]); Rem(B[i], A[i]);
		if (h[A[i]] == h[B[i]]) unionSet(A[i], B[i]);
		Add(A[i], B[i]); Add(B[i], A[i]);
	}
	for (int i = 0; i < m; i++)
		if (getPar(A[i]) != getPar(B[i])) {
			ii p = ii(getPar(A[i]), getPar(B[i]));
			if (p.first > p.second) swap(p.first, p.second);
			if (S.find(p) == S.end()) {
				neigh[p.first].push_back(p.second);
				neigh[p.second].push_back(p.first);
				S.insert(p);
			}
		}
	int root = -1;
	for (int i = 1; i <= n; i++)
		if (par[i] == i)
			if (neigh[i].size() <= 1) root = i;
			else if (neigh[i].size() > 2) { printf("NO\n"); return 0; }
	int col = 1;
	int av = -1;
	while (root != -1 && !res[root]) {
		res[root] = col++;
		int nxt;
		if (neigh[root].empty()) nxt = -1;
		else if (neigh[root].size() == 1)
				if (neigh[root][0] == av) nxt = -1;
				else nxt = neigh[root][0];
			else if (neigh[root][0] == av) nxt = neigh[root][1];
				 else nxt = neigh[root][0];
		av = root; root = nxt;
	}
	if (root != -1) { printf("NO\n"); return 0; }
	for (int i = 1; i <= n; i++)
		if (!res[getPar(i)]) { printf("NO\n"); return 0; }
	for (int i = 0; i < m; i++)
		if (abs(res[getPar(A[i])] - res[getPar(B[i])]) > 1) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[getPar(i)], i + 1 <= n? ' ': '\n');
	return 0;
}