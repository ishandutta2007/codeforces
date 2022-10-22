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

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxm = 524288;

int n;
int a[Maxn];
vector <int> un;
int BIT[Maxn];
int myL[Maxn], myR[Maxn];
vector <int> st[Maxm];
vector <int> L[Maxm], M[Maxm], R[Maxm];
vector <int> L2[Maxm], R2[Maxm];
vector <int> T[Maxm];
int res;

void Insert(int ind)
{
	ind++;
	for (int i = ind; i <= un.size(); i += i & -i)
		BIT[i]++;
}

int Get(int ind)
{
	ind++;
	int res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

void Union(int v, int ind, int ind2, int ind3)
{
	int lc = 2 * v, rc = 2 * v + 1;
	M[v][ind] = (M[lc][ind2] + M[rc][ind3]) % mod;
	L[v][ind] = (L[lc][ind2] + L[rc][ind3]) % mod;
	R[v][ind] = (R[lc][ind2] + R[rc][ind3]) % mod;

	L2[v][ind] = (L2[lc][ind2] + L2[rc][ind3]) % mod;
	L2[v][ind] = (L2[v][ind] + ll(L[lc][ind2]) * M[rc][ind3]) % mod;
	R2[v][ind] = (R2[lc][ind2] + R2[rc][ind3]) % mod;
	R2[v][ind] = (R2[v][ind] + ll(M[lc][ind2]) * R[rc][ind3]) % mod;

	T[v][ind] = (T[lc][ind2] + T[rc][ind3]) % mod;
	T[v][ind] = (T[v][ind] + ll(L[lc][ind2]) * R2[rc][ind3]) % mod;
	T[v][ind] = (T[v][ind] + ll(L2[lc][ind2]) * R[rc][ind3]) % mod;
}

void Copy(int v, int ind, int c, int ind2)
{
	M[v][ind] = M[c][ind2];
	L[v][ind] = L[c][ind2];
	R[v][ind] = R[c][ind2];
	L2[v][ind] = L2[c][ind2];
	R2[v][ind] = R2[c][ind2];
	T[v][ind] = T[c][ind2];
}

void Update(int v, int val)
{
	int ind = lower_bound(st[v].begin(), st[v].end(), val) - st[v].begin();
	int ind2 = lower_bound(st[2 * v].begin(), st[2 * v].end(), st[v][ind]) - st[2 * v].begin();
	int ind3 = lower_bound(st[2 * v + 1].begin(), st[2 * v + 1].end(), st[v][ind]) - st[2 * v + 1].begin();
	if (ind2 < st[2 * v].size() && st[2 * v][ind2] == st[v][ind])
		if (ind3 < st[2 * v + 1].size() && st[2 * v + 1][ind3] == st[v][ind])
			Union(v, ind, ind2, ind3);
		else Copy(v, ind, 2 * v, ind2);
	else if (ind3 < st[2 * v + 1].size() && st[2 * v + 1][ind3] == st[v][ind])
			Copy(v, ind, 2 * v + 1, ind3);
		else printf("error\n");
}

void Create(int v, int l, int r)
{
	if (l == r) {
		st[v].push_back(a[l]);
		M[v].push_back(1);
		L[v].push_back(myL[l]);
		R[v].push_back(myR[l]);
		L2[v].push_back(0);
		R2[v].push_back(0);
		T[v].push_back(0);
	} else {
		int m = l + r >> 1;
		int lc = 2 * v, rc = 2 * v + 1;
		Create(lc, l, m); Create(rc, m + 1, r);
		int i = 0, j = 0;
		while (i < st[lc].size() || j < st[rc].size()) {
			M[v].push_back(0);
			L[v].push_back(0);
			R[v].push_back(0);
			L2[v].push_back(0);
			R2[v].push_back(0);
			T[v].push_back(0);
			if (i < st[lc].size() && (j == st[rc].size() || st[lc][i] < st[rc][j])) {
				Copy(v, st[v].size(), lc, i); st[v].push_back(st[lc][i]); i++;
			} else if (j < st[rc].size() && (i == st[lc].size() || st[rc][j] < st[lc][i])) {
				Copy(v, st[v].size(), rc, j); st[v].push_back(st[rc][j]); j++;
			} else {
				Union(v, st[v].size(), i, j); st[v].push_back(st[lc][i]); i++; j++;
			}
		}
	}
}

void Update(int v, int l, int r, int x)
{
	if (l == r)
		if (!M[v][0]) {
			M[v][0] = 1; L[v][0] = myL[x]; R[v][0] = myR[x];
		} else {
			M[v][0] = 0; L[v][0] = 0; R[v][0] = 0;
		}
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x);
		else Update(2 * v + 1, m + 1, r, x);
		Update(v, a[x]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		myL[i] = Get(a[i]); Insert(a[i]);
	}
	fill(BIT, BIT + un.size() + 1, 0);
	for (int i = n; i > 0; i--) {
		myR[i] = Get(a[i]); Insert(a[i]);
	}
	Create(1, 1, n);
	for (int i = 0; i < st[1].size(); i++)
		res = (res + T[1][i]) % mod;
	int q; scanf("%d", &q);
	while (q--) {
		int typ, x; scanf("%d %d", &typ, &x);
		int ind = lower_bound(st[1].begin(), st[1].end(), a[x]) - st[1].begin();
		res = (res - T[1][ind] + mod) % mod;
		Update(1, 1, n, x);
		res = (res + T[1][ind]) % mod;
		printf("%d\n", res); 
	}
	return 0;
}