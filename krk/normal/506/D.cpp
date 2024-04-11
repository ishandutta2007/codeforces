#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxp = 300;

int n, m;
vector <ii> E[Maxn];
int q;
ii Q[Maxn];
map <int, int> byFirst[Maxn];
int tkfrom[Maxn];
int res[Maxn];

int par[Maxn], siz[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
int seq[Maxn], slen;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a != b)
		if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
		else { siz[b] += siz[a]; par[a] = b; }
}

void Traverse(int v)
{
	if (tk[v]) return;
	tk[v] = true; seq[slen++] = v;
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		E[c].push_back(ii(a, b));
	}
	map <int, int>::iterator it;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &Q[i].first, &Q[i].second);
		if (Q[i].first > Q[i].second) swap(Q[i].first, Q[i].second);
		it = byFirst[Q[i].first].find(Q[i].second);
		if (it != byFirst[Q[i].first].end()) tkfrom[i] = it->second;
		else { byFirst[Q[i].first][Q[i].second] = i; tkfrom[i] = i; }
	}
	for (int i = 1; i <= m; i++) if (!E[i].empty())
		if (E[i].size() > Maxp) {
			for (int j = 1; j <= n; j++) 
				par[j] = j, siz[j] = 1;
			for (int j = 0; j < E[i].size(); j++)
				unionSet(E[i][j].first, E[i][j].second);
			for (int j = 0; j < q; j++)
				if (getPar(Q[j].first) == getPar(Q[j].second))
					res[j]++;
		} else {
			for (int j = 0; j < E[i].size(); j++) {
				neigh[E[i][j].first].clear(); neigh[E[i][j].second].clear();
				tk[E[i][j].first] = tk[E[i][j].second] = 0;
			}
			for (int j = 0; j < E[i].size(); j++) {
				neigh[E[i][j].first].push_back(E[i][j].second);
				neigh[E[i][j].second].push_back(E[i][j].first);
			}
			for (int j = 0; j < E[i].size(); j++)
				if (!tk[E[i][j].first]) {
					slen = 0; Traverse(E[i][j].first);
					for (int ai = 0; ai < slen; ai++)
						for (int bi = ai + 1; bi < slen; bi++) {
							int a = min(seq[ai], seq[bi]), b = max(seq[ai], seq[bi]);
							it = byFirst[a].find(b);
							if (it != byFirst[a].end()) res[it->second]++;
						}
				}
		}
	for (int i = 0; i < q; i++)
		printf("%d\n", res[tkfrom[i]]);
	return 0;
}