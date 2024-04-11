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

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;
const int Maxm = 20;

int m, n;
int p[Maxn];
vector <int> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
int tot[Maxn];
ll delt[Maxn];
ll res;

void Traverse(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		L[u] = L[v] + 1; P[u][0] = v;
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
	scanf("%d", &m); n = m + 1;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p[i]);
		neigh[p[i]].push_back(i);
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	int a = 1, b = 1, cur = 0;
	vector <int> check, great;
	check.push_back(1);
	for (int i = 2; i <= n; i++) {
		int d1 = getDist(a, i), d2 = getDist(b, i);
		if (max(d1, d2) >= cur) check.push_back(i);
		if (d1 > cur) { b = i; great.push_back(i); cur = d1; }
		else if (d2 > cur) { a = i; great.push_back(i); cur = d2; }
		tot[i] = cur;
	}
	for (int i = 0; i < check.size(); i++) {
		int ind = check[i];
		int lef = 0, rig = int(great.size()) - 1;
		int ans = great.size();
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (great[mid] <= ind) lef = mid + 1;
			else if (getDist(ind, great[mid]) != tot[great[mid]]) { ans = mid; rig = mid - 1; }
				 else lef = mid + 1;
		}
		delt[ind]++;
		if (ans < great.size()) delt[great[ans]]--;
	}
	for (int i = 1; i <= n; i++) {
		res += delt[i];
		if (i >= 2) printf("%lld\n", res);
	}
	return 0;
}