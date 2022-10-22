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

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;
const int Maxm = 21;
const int Maxmy = 500005;

int n;
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int distA[Maxn], distB[Maxn];
int trunk[Maxn];
vector <int> my[Maxmy];
ll res;
vector <iii> ans;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == P[v][0]) continue;
		P[u][0] = v; L[u] = L[v] + 1;
		Traverse(u);
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

int getDist(int a, int b)
{
	return L[a] + L[b] - 2 * L[getLCA(a, b)];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	int best = -1, a = -1, b = -1;
	for (int i = 1; i <= n; i++) {
		int cand = getDist(1, i);
		if (cand > best) { best = cand; a = i; }
	}
	best = -1;
	for (int i = 1; i <= n; i++) {
		distA[i] = getDist(a, i);
		if (distA[i] > best) { best = distA[i]; b = i; }
	}
	for (int i = 1; i <= n; i++)
		distB[i] = getDist(b, i);
	for (int i = 1; i <= n; i++)
		if (distA[i] + distB[i] == distA[b]) trunk[distA[i]] = i;
		else my[distA[i] + distB[i]].push_back(i);
	for (int i = Maxmy - 1; i >= 0; i--)
		for (int j = 0; j < my[i].size(); j++) {
			int v = my[i][j];
			if (distA[v] >= distB[v]) { res += distA[v]; ans.push_back(iii(ii(a, v), v)); }
			else { res += distB[v]; ans.push_back(iii(ii(b, v), v)); }
		}
	for (int i = distA[b]; i > 0; i--) {
		res += i; ans.push_back(iii(ii(a, trunk[i]), trunk[i]));
	}
	printf("%I64d\n", res);
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
	return 0;
}