#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int n, c;
int L[Maxn];
vector <int> W[Maxn];
int delt[Maxn];

int Add(int l, int r)
{
	if (l <= r) { delt[l]++; delt[r + 1]--; }
	else {
		delt[l]++; delt[c]--;
		delt[0]++; delt[r + 1]--;
	}
}

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &L[i]); W[i].resize(L[i]);
		for (int j = 0; j < L[i]; j++) {
			scanf("%d", &W[i][j]); W[i][j]--;
		}
	}
	for (int i = 1; i < n; i++) {
		int j = 0;
		while (j < W[i].size() && j < W[i + 1].size() && W[i][j] == W[i + 1][j]) j++;
		if (j < W[i].size() && j < W[i + 1].size()) {
			Add((c - W[i][j]) % c, (c - W[i + 1][j] - 1) % c);
		} else if (j < W[i].size() && j >= W[i + 1].size()) { printf("-1\n"); return 0; }
		  else Add(0, c - 1);
	}
	int cur = 0;
	for (int i = 0; i < c; i++) {
		cur += delt[i];
		if (cur == n - 1) { printf("%d\n", i); return 0; }
	}
	printf("-1\n");
	return 0;
}