#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 2 * Maxn;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

int n, m;
int rtk[Maxn], ctk[Maxn];
int par[Maxm], siz[Maxm];
int mx[Maxm];
vector <iii> seq;
vector <vector <int> > res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++) {
		par[i] = i, siz[i] = 1;
		mx[i] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int a; scanf("%d", &a);
			seq.push_back(iii(a, ii(i, j)));
		}
	res.assign(n, vector <int>(m));
	sort(seq.begin(), seq.end());
	for (int i = 0, j; i < seq.size(); i = j) {
		j = i;
		while (j < seq.size() && seq[i].first == seq[j].first) j++;
		for (int l = i; l < j; l++) {
			ii p = seq[l].second;
			unionSet(p.first, n + p.second);
		}
		for (int l = i; l < j; l++) {
			ii p = seq[l].second;
			int cand = max(rtk[p.first], ctk[p.second]) + 1;
			mx[getPar(p.first)] = max(mx[getPar(p.first)], cand);
		}
		for (int l = i; l < j; l++) {
			ii p = seq[l].second;
			int val = mx[getPar(p.first)];
			res[p.first][p.second] = val;
			rtk[p.first] = ctk[p.second] = val;
		}
		for (int l = i; l < j; l++) {
			ii p = seq[l].second;
			par[p.first] = p.first; siz[p.first] = 1; mx[p.first] = 0;
			par[n + p.second] = n + p.second; siz[n + p.second] = 1; mx[n + p.second] = 0;
		}
	}
	for (int i = 0; i < res.size(); i++)
		for (int j = 0; j < res[i].size(); j++)
			printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
	return 0;
}