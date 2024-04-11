#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int cnt[Maxn];
ld res[Maxn];

void Traverse1(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse1(u);
		cnt[v] += cnt[u];
	}
}

void Traverse2(int v, ld ex)
{
	ex += 1.0; res[v] += ex;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse2(u, ex + ld(cnt[v] - 1 - cnt[u]) / 2.0l);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	Traverse1(1);
	Traverse2(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%.10lf%c", double(res[i]), i + 1 <= n? ' ': '\n');
	return 0;
}