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

const int Maxn = 200005;
const int Maxk = 5;

int n, k;
vector <int> neigh[Maxn];
int L[Maxn], cnt[Maxn][Maxk], tcnt[Maxn];
ll sum[Maxn];
ll tot;

void Traverse(int v, int p = 0)
{
	cnt[v][L[v] % k]++; tcnt[v]++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		L[u] = L[v] + 1; Traverse(u, v);
		sum[u] += cnt[u][L[v] % k];
		tot += sum[v] * ll(tcnt[u]) + sum[u] * ll(tcnt[v]);
		for (int j = 0; j < k; j++)
			for (int l = 0; l < k; l++) {
				int a = (j - L[v] % k + k) % k;
				int b = (l - L[v] % k + k) % k;
				int tk = (a + b) / k + int((a + b) % k > 0);
				tot += ll(tk) * ll(cnt[v][j]) * ll(cnt[u][l]); 
			}
		sum[v] += sum[u]; tcnt[v] += tcnt[u];
		for (int j = 0; j < k; j++)
			cnt[v][j] += cnt[u][j];
	}

}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	printf("%I64d\n", tot);
	return 0;
}