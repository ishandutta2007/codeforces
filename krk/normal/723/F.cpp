#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;

int n, m;
int a[Maxn], b[Maxn];
int s, t;
int ds, dt;
bool wasst;
vector <int> SE, TE;
int par[Maxn], siz[Maxn];
int tos[Maxn], tot[Maxn];
vector <ii> res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &a[i], &b[i]);
	scanf("%d %d %d %d", &s, &t, &ds, &dt);
	for (int i = 1; i <= n; i++)
		siz[i] = 1, par[i] = i;
	if (s > t) { swap(s, t); swap(ds, dt); }
	for (int i = 0; i < m; i++) {
		if (a[i] > b[i]) swap(a[i], b[i]);
		if (a[i] == s && b[i] == t) wasst = true;
		else if (a[i] == s) SE.push_back(b[i]);
		else if (a[i] == t) TE.push_back(b[i]);
		else if (b[i] == s) SE.push_back(a[i]);
		else if (b[i] == t) TE.push_back(a[i]);
		else if (unionSet(a[i], b[i])) res.push_back(ii(a[i], b[i]));
	}
	for (int i = 0; i < SE.size(); i++)
		tos[getPar(SE[i])] = SE[i];
	for (int i = 0; i < TE.size(); i++)
		tot[getPar(TE[i])] = TE[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (getPar(i) == i)
			if (tos[i] && !tot[i]) {
				if (ds > 0) { res.push_back(ii(s, tos[i])); ds--; }
				else { printf("No\n"); return 0; }
			} else if (!tos[i] && tot[i]) {
				if (dt > 0) { res.push_back(ii(t, tot[i])); dt--; }
				else { printf("No\n"); return 0; }
			} else if (tos[i] && tot[i]) cnt++;
	if (!ds || !dt) { printf("No\n"); return 0; }
	if (cnt + 2 <= ds + dt && wasst) {
		res.push_back(ii(s, t)); ds--; dt--;
		for (int i = 1; i <= n; i++)
			if (getPar(i) == i && tos[i] && tot[i])
				if (ds > 0) { res.push_back(ii(s, tos[i])); ds--; }
				else { res.push_back(ii(t, tot[i])); dt--; }
	} else if (cnt + 1 <= ds + dt && cnt > 0) {
		bool was = false;
		for (int i = 1; i <= n; i++)
			if (getPar(i) == i && tos[i] && tot[i])
				if (!was) { 
					res.push_back(ii(s, tos[i])); ds--; 
					res.push_back(ii(t, tot[i])); dt--;
					was = true;
				} else if (ds > 0) { res.push_back(ii(s, tos[i])); ds--; }
				else { res.push_back(ii(t, tot[i])); dt--; }
	} else { printf("No\n"); return 0; }
	printf("Yes\n");
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}