#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 405;
const int Inf = 1000000000;

int n, m;
int dist[Maxn][Maxn];
vector <int> V[Maxn];
ld prob[Maxn], mx[Maxn];
ld res;
int seq[Maxn], slen;
int bseq[Maxn], blen;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i != j) * Inf;
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			V[j].clear();
		for (int j = 1; j <= n; j++)
			V[dist[i][j]].push_back(j);
		ld my = 0.0;
		for (int j = 0; j <= n; j++) if (!V[j].empty()) {
			ld best = 1 / ld(n);
			
			fill(prob, prob + n + 1, 0);
			slen = 0;
			for (int z = 0; z < V[j].size(); z++) {
				int v = V[j][z];
				int neighs = 0;
				for (int c = 1; c <= n; c++)
					if (dist[v][c] == 1) neighs++;
				for (int c = 1; c <= n; c++)
					if (dist[v][c] == 1) { 
						if (prob[c] < 1e-9) seq[slen++] = c;
						prob[c] += 1 / ld(neighs); 
					}
			}
			for (int l = 1; l <= n; l++) {
				for (int z = 0; z < blen; z++)
					mx[bseq[z]] = 0;
				blen = 0;
				for (int z = 0; z < slen; z++) {
					int d = dist[l][seq[z]];
					if (mx[d] < 1e-9) bseq[blen++] = d;
					mx[d] = max(mx[d], prob[seq[z]]);
				}
				ld cand = 0.0;
				for (int z = 0; z < blen; z++)
					cand += mx[bseq[z]];
				best = max(best, cand / n);
			}
			my += best;
		}
		res = max(res, my);
	}
	printf("%.15lf\n", double(res));
	return 0;
}