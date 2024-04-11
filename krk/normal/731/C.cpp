#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n, m, k;
int c[Maxn];
vector <int> neigh[Maxn];
int freq[Maxn];
bool tk[Maxn];
vector <int> cur;
int res;

void Fill(int v)
{
	if (tk[v]) return;
	tk[v] = true; freq[c[v]]++; cur.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i]);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		neigh[l].push_back(r);
		neigh[r].push_back(l);
	}
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		cur.clear(); Fill(i);
		int mx = 0;
		for (int j = 0; j < cur.size(); j++) {
			mx = max(mx, freq[c[cur[j]]]); freq[c[cur[j]]] = 0;
		}
		res += int(cur.size()) - mx;
	}
	printf("%d\n", res);
	return 0;
}