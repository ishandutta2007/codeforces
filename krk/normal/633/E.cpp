#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1000005;

int n, k;
int v[Maxn];
int c[Maxn];
int parv[Maxn];
int parc[Maxn];
vector <int> Vv, Vc;
int res[Maxn];
ld dv[Maxn];
ld prob;
int lft;
ld E;

int Get(int par[], int x) { return par[x] == x? x: par[x] = Get(par, par[x]); }

int GetV(int x) { return 100 * v[Get(parv, x)]; }

int GetC(int x) { return c[Get(parc, x)]; }

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = n - 1; i >= 0; i--) {
		parv[i] = i; parc[i] = i;
		while (!Vv.empty() && v[i] >= v[Vv.back()]) {
			parv[Vv.back()] = i; Vv.pop_back();
		}
		while (!Vc.empty() && c[i] <= c[Vc.back()]) {
			parc[Vc.back()] = i; Vc.pop_back();
		}
		Vv.push_back(i); Vc.push_back(i);
		int cur = max(min(GetV(i), GetC(i)), min(GetV(n - 1), GetC(n - 1)));
		cur = 0;
		int l = i, r = n - 1;
		while (l <= r) {
			int m = l + r >> 1;
			int cand = min(GetV(m), GetC(m));
			cur = max(cur, cand);
			if (cand == GetV(m)) l = m + 1;
			else r = m - 1;
		}
		res[i] = cur;
	}
	sort(res, res + n);
	dv[n - k] = 1;
	for (int i = n - k + 1; i <= n; i++)
		dv[i] = dv[i - 1] * ld(i);
	prob = 1; lft = n;
	for (int i = 2; i <= k; i++) {
		prob *= i;
		while (prob > 1 && lft > n - k) { prob /= lft; lft--; }
	}
	for (int i = n - k; i >= 0; i--) {
		ld val = prob * res[i] / ld(n - i) * ld(k) / dv[lft];
		E += val;
		prob *= ld(n - i + 1) / ld(n - i + 1 - k);
		while (prob > 1 && lft > n - k) { prob /= lft; lft--; }
	}
	cout << fixed << setprecision(10) << E << endl;
	return 0;
}