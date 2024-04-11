#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxv = 4;
const int Maxm = 1 << 3;
const int Maxk = 10005;

int cnt[Maxm];
vector <int> neigh[Maxm];
vector <int> divs[Maxn];
int t;
int ulen;
int un[Maxk], vals[Maxk];
int has[Maxk][Maxm], all[Maxk][Maxm];
int cur[Maxm];

int main()
{
	for (int i = 1; i < Maxn; i++)
		for (int j = i; j < Maxn; j += i)
			divs[j].push_back(i);
	for (int i = 0; i < Maxm; i++) {
		for (int j = 0; j < Maxm; j++) if ((i & j) == j)
			neigh[i].push_back(j);
		for (int j = 0; j < 3; j++)
			cnt[i] += bool(i & 1 << j);
	}
	scanf("%d", &t);
	while (t--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		ulen = 0;
		int i = 0, j = 0, k = 0;
		while (i < divs[a].size() || j < divs[b].size() || k < divs[c].size()) {
			int add = Maxn;
			if (i < divs[a].size()) add = min(add, divs[a][i]);
			if (j < divs[b].size()) add = min(add, divs[b][j]);
			if (k < divs[c].size()) add = min(add, divs[c][k]);
			int mask = 0;
			if (i < divs[a].size() && divs[a][i] == add) { i++; mask |= 1; }
			if (j < divs[b].size() && divs[b][j] == add) { j++; mask |= 2; }
			if (k < divs[c].size() && divs[c][k] == add) { k++; mask |= 4; }
			un[ulen] = add; vals[ulen] = mask; ulen++;
		}
		fill(has[ulen], has[ulen] + Maxm, 0);
		fill(all[ulen], all[ulen] + Maxm, 0);
		for (int i = ulen - 1; i >= 0; i--) {
			for (int j = 0; j < Maxm; j++) {
				has[i][j] = has[i + 1][j];
				all[i][j] = all[i + 1][j];
			}
			all[i][vals[i]]++;
			for (int j = 0; j < neigh[vals[i]].size(); j++) {
				int got = neigh[vals[i]][j];
				has[i][got]++;
			}
		}
		fill(cur, cur + Maxm, 0);
		ll res = 0;
		for (int i = 0; i < ulen; i++) {
			if (cnt[vals[i]] == 3) res++;
			for (int j = 1; j < Maxm; j++) {
				if (cnt[vals[i]] >= 2 && cnt[vals[i] | j] == 3)
					res += cur[j] + all[i + 1][j];
				if (cnt[vals[i] | j] >= 2)
					if (cnt[vals[i] | j] == 3)
						if (cnt[j] == 1)
							res += ll(cur[j]) * (ulen - 1 - i - all[i + 1][j]);
						else if (cnt[vals[i]] == 1)
							res += ll(cur[j]) * (ulen - 1 - i - all[i + 1][vals[i]]);
						else res += ll(cur[j]) * (ulen - 1 - i);
					else res += ll(cur[j]) * has[i + 1][(Maxm - 1) ^ (vals[i] | j)];
			}
			cur[vals[i]]++;
		}
		printf("%I64d\n", res);
	}
	return 0;
}