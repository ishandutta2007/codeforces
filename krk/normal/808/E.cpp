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
using namespace std;

typedef long long ll;

const int Maxm = 300015;
const int Maxw = 3;

int n, m;
ll best[Maxm];
vector <int> seq[Maxw];

ll Solve()
{
	int i = 0, j = 0;
	ll cur = 0, w = 0;
	ll res = best[m];
	if (i < seq[0].size() && 1 <= m) res = max(res, seq[0][i] + best[m - 1]);
	while (i + 2 <= seq[0].size() || j + 1 <= seq[1].size()) {
		if (i + 2 <= seq[0].size() && (j + 1 > seq[1].size() || seq[0][i] + seq[0][i + 1] > seq[1][j])) {
			cur += seq[0][i] + seq[0][i + 1]; w += 2; i += 2;
		} else {
			cur += seq[1][j]; w += 2; j++;
		}
		if (w <= m) res = max(res, cur + best[m - w]);
		if (w + 1 <= m) {
			if (i < seq[0].size()) res = max(res, cur + ll(seq[0][i]) + best[m - w - 1]);
			if (i > 0 && j < seq[1].size()) res = max(res, cur + ll(seq[1][j]) - ll(seq[0][i - 1]) + best[m - w - 1]);
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int w, c; scanf("%d %d", &w, &c);
		seq[w - 1].push_back(c);
	}
	for (int i = 0; i < Maxw; i++)
		sort(seq[i].rbegin(), seq[i].rend());
	ll cur = 0;
	for (int i = 0; i < seq[2].size(); i++) {
		cur += seq[2][i];
		best[3 * (i + 1)] = cur;
	}
	for (int i = 0; i + 1 <= m; i++)
		best[i + 1] = max(best[i + 1], best[i]);
	printf("%I64d\n", Solve());
	return 0;
}