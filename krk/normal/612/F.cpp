#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

typedef pair <char, int> ci;

const int Maxn = 2005;
const int Inf = 1000000000;

int n, s;
int a[Maxn];
vector <int> un;
vector <int> ind[Maxn];
int lef[Maxn], rig[Maxn];
int dp[Maxn][2][Maxn], par[Maxn][2][Maxn], wth[Maxn][2][Maxn];
vector <ci> res;

int Rot(int a, int b)
{
	if (a <= b) return b - a;
	return n + b - a;
}

int Best(int a, int b)
{
	return min(Rot(a, b), Rot(b, a));
}

void Get(int i, int f, int k)
{
	if (i < 0) return;
	if (f == 0) {
		int j = par[i][f][k];
		Get(i - 1, 1, j);
		if (Best(j, k) == Rot(j, k)) res.push_back(ci('+', Rot(j, k)));
		else res.push_back(ci('-', Rot(k, j)));
	} else if (par[i][f][k] == k) Get(i, 0, k);
	else {
		int j = par[i][f][k];
		Get(i, 0, j);
		int n = ind[i].size();
		int kind = lower_bound(ind[i].begin(), ind[i].end(), k) - ind[i].begin();
		vector <int> tmp;
		if (wth[i][f][k] == -1) {
			for (int z = 1; z <= n; z++)
				tmp.push_back(ind[i][(kind + z) % n]);
			int jind;
			for (int z = 0; z < tmp.size(); z++)
				if (tmp[z] == j) { jind = z; break; }
			int lst = j;
			for (int z = jind - 1; z >= 0; z--) {
				res.push_back(ci('-', Rot(tmp[z], lst)));
				lst = tmp[z];
			}
			for (int z = jind + 1; z < tmp.size(); z++) {
				res.push_back(ci('+', Rot(lst, tmp[z])));
				lst = tmp[z];
			}
		} else {
			for (int z = 0; z < n; z++)
				tmp.push_back(ind[i][(kind + z) % n]);
			int jind;
			for (int z = 0; z < tmp.size(); z++)
				if (tmp[z] == j) { jind = z; break; }
			int lst = j;
			for (int z = jind + 1; z < tmp.size(); z++) {
				res.push_back(ci('+', Rot(lst, tmp[z])));
				lst = tmp[z];
			}
			for (int z = jind - 1; z >= 0; z--) {
				res.push_back(ci('-', Rot(tmp[z], lst)));
				lst = tmp[z];
			}
		}
	}
}

int main() 
{
	scanf("%d %d", &n, &s); s--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); un.push_back(a[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		ind[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++)
		if (ind[a[i]].size() > 1) {
			int my = lower_bound(ind[a[i]].begin(), ind[a[i]].end(), i) - ind[a[i]].begin();
			my = (my - 1 + ind[a[i]].size()) % ind[a[i]].size();
			lef[i] = ind[a[i]][my];
			my = (my + 2) % ind[a[i]].size();
			rig[i] = ind[a[i]][my];
		}
	fill((int*)dp, (int*)dp + Maxn * 2 * Maxn, Inf);
	for (int i = 0; i < ind[0].size(); i++) {
		dp[0][0][ind[0][i]] = Best(s, ind[0][i]);
		par[0][0][ind[0][i]] = s;
	}
	for (int i = 0; i < un.size(); i++) {
		for (int z = 0; z < ind[i].size(); z++) {
			int j = ind[i][z];
			if (ind[i].size() == 1) { dp[i][1][j] = dp[i][0][j]; par[i][1][j] = j; }
			else for (int c = 0; c < ind[i].size(); c++) {
				int k = ind[i][c];
				if (k == j) continue;
				int cand = dp[i][0][j] + 2 * Rot(rig[k], j) + Rot(j, k);
				if (cand < dp[i][1][k]) {
					dp[i][1][k] = cand; par[i][1][k] = j; wth[i][1][k] = -1;
				}
				cand = dp[i][0][j] + 2 * Rot(j, lef[k]) + Rot(k, j);
				if (cand < dp[i][1][k]) {
					dp[i][1][k] = cand; par[i][1][k] = j; wth[i][1][k] = 1;
				}
			}
		}
		for (int z = 0; z < ind[i].size(); z++) {
			int j = ind[i][z];
			for (int c = 0; c < ind[i + 1].size(); c++) {
				int k = ind[i + 1][c];
				int cand = dp[i][1][j] + Best(j, k);
				if (cand < dp[i + 1][0][k]) {
					dp[i + 1][0][k] = cand; par[i + 1][0][k] = j;
				}
			}
		}
	}
	int best = Inf, bj;
	for (int j = 0; j < n; j++) 
		if (dp[un.size() - 1][1][j] < best) { best = dp[un.size() - 1][1][j]; bj = j; }
	printf("%d\n", best);
	Get(un.size() - 1, 1, bj);
	for (int i = 0; i < res.size(); i++)
		printf("%c%d\n", res[i].first, res[i].second);
    return 0;
}