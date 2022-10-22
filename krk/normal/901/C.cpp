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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

int n, m;
int A[Maxn], B[Maxn];
int par[Maxn], siz[Maxn];
vector <int> E[Maxn];
ii P[Maxn];
int L[Maxn];
vector <ii> neigh[Maxn];
int mx[Maxn];
ll sum[Maxn];
int q;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (P[v].first == u.first) continue;
		P[u.first] = ii(v, u.second); L[u.first] = L[v] + 1;
		Traverse(u.first);
	}
}

void unionSet(int a, int b, int ind)
{
	int para = getPar(a), parb = getPar(b);
	if (para == parb) {
		int small = min(a, b), big = max(a, b);
		while (a != b)
			if (L[a] > L[b]) {
				a = P[a].first;
				small = min(small, a); big = max(big, a);
			} else {
				b = P[b].first;
				small = min(small, b); big = max(big, b);
			}
		mx[small] = min(mx[small], big - 1);
	} else {
		if (siz[para] < siz[parb]) { swap(para, parb); swap(a, b); }
		for (int i = 0; i < E[parb].size(); i++) {
			int e = E[parb][i];
			neigh[A[e]].clear(); neigh[B[e]].clear();
		}
		for (int i = 0; i < E[parb].size(); i++) {
			int e = E[parb][i];
			neigh[A[e]].push_back(ii(B[e], e));
			neigh[B[e]].push_back(ii(A[e], e));
			E[para].push_back(e);
		}
		E[parb].clear();
		P[b] = ii(a, ind); L[b] = L[a] + 1;
		Traverse(b);
		siz[para] += siz[parb]; par[parb] = para;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		par[i] = i; siz[i] = 1;
		mx[i] = n;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &A[i], &B[i]);
		unionSet(A[i], B[i], i);
	}
	for (int i = n - 1; i > 0; i--)
		mx[i] = min(mx[i], mx[i + 1]);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + mx[i];
	scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		ll res = ll(r - l + 2) * (r - l + 1) / 2;
		int lef = l, rig = r;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (mx[mid] < r) lef = mid + 1;
			else rig = mid - 1;
		}
		lef--;
		ll cnt = lef - l + 1;
		res -= (cnt * r - sum[lef] + sum[l - 1]);
		printf("%I64d\n", res);
	}
	return 0;
}