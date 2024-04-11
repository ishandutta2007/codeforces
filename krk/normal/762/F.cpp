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
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 1000007;
const int arg2 = 821;
const int Maxm = 13;

int s;
vector <int> sneigh[Maxn];
int t;
vector <int> tneigh[Maxn];
set <ii> ACC;
map <multiset <ii>, int> tmp[Maxn][Maxm];
map <ii, int> dp[Maxn][Maxm];
int res;

ii Join(const ii &a, const ii &b)
{
	ii c = ii((ll(a.first) * arg1 + ll(b.first)) % mod1, (ll(a.second) * arg2 + ll(b.second)) % mod2);
	return ii((ll(c.first) * arg1 ^ ll(b.first)) % mod1, (ll(c.second) * arg2 ^ ll(b.second)) % mod2);
}

ii Traverse(int v, int p)
{
	vector <ii> V;
	for (int i = 0; i < tneigh[v].size(); i++) {
		int u = tneigh[v][i];
		if (u == p) continue;
		V.push_back(Traverse(u, v));
	}
	ii res = ii(1, 1);
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
		res = Join(res, V[i]);
	return res;
}

ii Hash(const multiset <ii> &S)
{
	ii res = ii(1, 1);
	for (multiset <ii>::iterator it = S.begin(); it != S.end(); it++)
		res = Join(res, *it);
	return res;
}

void Count(int v, int p)
{
	multiset <ii> I;
	tmp[v][1][I] = 1;
	for (int i = 0; i < sneigh[v].size(); i++) {
		int u = sneigh[v][i];
		if (u == p) continue;
		Count(u, v);
		for (int j = t - 1; j >= 1; j--)
			for (map <multiset<ii>, int>::iterator it = tmp[v][j].begin(); it != tmp[v][j].end(); it++)
				for (int k = 1; j + k <= t; k++)
					for (map <ii, int>::iterator it2 = dp[u][k].begin(); it2 != dp[u][k].end(); it2++) {
						multiset <ii> newS = it->first; newS.insert(it2->first);
						int val = ll(it->second) * it2->second % mod1;
						tmp[v][j + k][newS] = (tmp[v][j + k][newS] + val) % mod1;
					}
	}
	for (int i = 1; i < t; i++)
		for (map <multiset <ii>, int>::iterator it = tmp[v][i].begin(); it != tmp[v][i].end(); it++)
			dp[v][i][Hash(it->first)] = (dp[v][i][Hash(it->first)] + it->second) % mod1;
	for (map <multiset <ii>, int>::iterator it = tmp[v][t].begin(); it != tmp[v][t].end(); it++)
		if (ACC.find(Hash(it->first)) != ACC.end()) res = (res + it->second) % mod1;
}

int main() 
{
	scanf("%d", &s);
	for (int i = 0; i < s - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		sneigh[a].push_back(b);
		sneigh[b].push_back(a);
	}
	scanf("%d", &t);
	for (int i = 0; i < t - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		tneigh[a].push_back(b);
		tneigh[b].push_back(a);
	}
	for (int i = 1; i <= t; i++)
		ACC.insert(Traverse(i, 0));
	Count(1, 0);
	printf("%d\n", res);
    return 0;
}