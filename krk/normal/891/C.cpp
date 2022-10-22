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
typedef pair <int, ii> iii;

const int Maxn = 500005;
const int Maxm = 22;

int n, m;
int u[Maxn], v[Maxn], w[Maxn];
vector <iii> E;
int par[Maxn], siz[Maxn];
vector <ii> spar, ssiz;
vector <ii> add[Maxn];
vector <int> tosolve[Maxn];
int q;
vector <int> quer[Maxn];
int pnt[Maxn];
bool res[Maxn];

int safegetPar(int x) { return par[x] == x? x: safegetPar(par[x]); }

bool safeunionSet(int a, int b)
{
	a = safegetPar(a), b = safegetPar(b);
	if (a == b) return false;
	if (siz[a] < siz[b]) swap(a, b);
	ssiz.push_back(ii(a, siz[a]));
	spar.push_back(ii(b, par[b]));
	siz[a] += siz[b]; par[b] = a;
	return true;
}

bool Less(const int &a, const int &b)
{
	return w[a] < w[b];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		add[w[i]].push_back(ii(u[i], v[i]));
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int slen; scanf("%d", &slen);
		vector <int> tmp(slen);
		for (int j = 0; j < slen; j++)
			scanf("%d", &tmp[j]);
		sort(tmp.begin(), tmp.end(), Less);
		quer[i] = tmp;
		for (int j = 0; j < tmp.size(); j++)
			if (j == 0 || w[tmp[j - 1]] < w[tmp[j]]) tosolve[w[tmp[j]]].push_back(i);
		res[i] = true;
	}
	for (int i = 0; i < Maxn; i++) {
		for (int j = 0; j < tosolve[i].size(); j++) {
			int ind = tosolve[i][j];
			int restpar = spar.size(), restsiz = ssiz.size();
			while (pnt[ind] < quer[ind].size() && w[quer[ind][pnt[ind]]] == i) {
				int tk = quer[ind][pnt[ind]];
				if (!safeunionSet(u[tk], v[tk])) res[ind] = false;
				pnt[ind]++;
			}
			while (spar.size() > restpar) {
				par[spar.back().first] = spar.back().second;
				spar.pop_back();
			}
			while (ssiz.size() > restsiz) {
				siz[ssiz.back().first] = ssiz.back().second;
				ssiz.pop_back();
			}
		}
		for (int j = 0; j < add[i].size(); j++) {
			int a = add[i][j].first, b = add[i][j].second;
			safeunionSet(a, b);
		}
	}
	for (int i = 0; i < q; i++)
		printf("%s\n", res[i]? "YES": "NO");
	return 0;
}