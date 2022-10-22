#include <bits/stdc++.h>
using namespace std;

const int MaxB = 12;
const int Maxn = 20;
const int Maxa = 9;
const int Maxb = 3;
const int Maxw = 102;

char tmp[Maxn];
int n, m, q;
int w[MaxB];
int cost[1 << MaxB];
int has[1 << MaxB][Maxw];

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i < 1 << MaxB; i++) {
		int b = __builtin_popcount((i & -i) - 1);
		cost[i] = min(Maxw - 1, cost[i ^ 1 << b] + w[b]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", tmp);
		int mask = 0;
		for (int j = 0; j < n; j++)
			mask |= (tmp[j] == '1') << j;
		for (int j = 0; j < 1 << Maxa; j++) {
			int sw = (j ^ ((1 << Maxa) - 1));
			has[mask ^ sw][cost[j]]++;
		}
	}
	for (int i = 0; i < q; i++) {
		scanf("%s", tmp);
		int mask = 0;
		for (int j = 0; j < n; j++)
			mask |= (tmp[j] == '1') << j;
		int k; scanf("%d", &k);
		int res = 0;
		for (int j = 0; j < 1 << Maxb; j++) {
			int sw = (j ^ ((1 << Maxb) - 1));
			int my = (mask ^ (sw << Maxa));
			int c = cost[j << Maxa];
			for (int l = 0; l < Maxw && l + c <= k; l++)
				res += has[my][l];
		}
		printf("%d\n", res);
	}
	return 0;
}