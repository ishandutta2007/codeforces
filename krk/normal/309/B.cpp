#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 22;

int n, r, c;
string w[Maxn];
int sum[Maxn];
int E[Maxn][Maxm];
int best = 0, bi = n;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> n >> r >> c;
	for (int i = 0; i < n; i++) {
		cin >> w[i]; sum[i + 1] = sum[i] + w[i].length();
	}
	for (int i = 0; i < n; i++) {
		int lef = i + 1, rig = n, res = i;
		while (lef <= rig) {
			int mid = lef + rig >> 1;
			if (sum[mid] - sum[i] + mid - i - 1 <= c) { res = mid; lef = mid + 1; }
			else rig = mid - 1;
		}
		E[i][0] = res;
	}
	fill(E[n], E[n] + Maxm, n);
	for (int j = 1; j < Maxm; j++)
		for (int i = 0; i < n; i++)
			E[i][j] = E[E[i][j - 1]][j - 1];
	for (int i = 0; i < n; i++) {
		int cur = i, lef = r;
		for (int j = Maxm - 1; j >= 0; j--)
			if (1 << j <= lef) { cur = E[cur][j]; lef -= 1 << j; }
		if (cur - i > best) { best = cur - i; bi = i; }
	}
	while (bi < n && r) {
		for (int i = bi; i < E[bi][0]; i++)
			cout << w[i] << (i + 1 < E[bi][0]? ' ': '\n');
		bi = E[bi][0]; r--;
	}
	return 0;
}