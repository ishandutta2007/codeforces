#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 2005;
const int Maxm = 2 * Maxn;
const int Inf = 2000000000;

int n;
iii rc[Maxn];
vector <int> un;
map <int, int> neigh[Maxm];
map <ii, vector <int> > M;
int dp[Maxm], par[Maxm];

int getDP(int l, int r, int ind)
{
	for (int i = l; i <= r; i++)
		dp[i] = 0;
	for (int i = l; i < r; i++) {
		if (dp[i] > dp[i + 1]) { dp[i + 1] = dp[i]; par[i + 1] = i; }
		for (map <int, int>::iterator it = neigh[i].begin(); it != neigh[i].end(); it++)
			if (it->first <= r && dp[i] + it->second > dp[it->first]) {
				dp[it->first] = dp[i] + it->second; par[it->first] = i;
			}
		}
	int v = r;
	while (dp[v]) {
		int u = par[v];
		map <ii, vector <int> >::iterator it = M.find(ii(u, v));
		if (it != M.end())
			for (int i = 0; i < it->second.size(); i++)
				M[ii(l, r)].push_back(it->second[i]);
		v = u;
	}
	if (ind) M[ii(l, r)].push_back(ind);
	return dp[r] + (ind > 0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &rc[i].first.second, &rc[i].first.first); rc[i].second = i + 1;
		un.push_back(rc[i].first.second - rc[i].first.first);
		un.push_back(rc[i].first.second + rc[i].first.first);
	}
	un.push_back(-Inf); un.push_back(Inf);
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	rc[n].first.second = 0; rc[n].first.first = Inf;
	sort(rc, rc + n);
	for (int i = 0; i <= n; i++) {
		int l = lower_bound(un.begin(), un.end(), rc[i].first.second - rc[i].first.first) - un.begin();
		int r = lower_bound(un.begin(), un.end(), rc[i].first.second + rc[i].first.first) - un.begin();
		int res = getDP(l, r, rc[i].second);
		neigh[l][r] += res;
	}
	printf("%d\n", neigh[0][un.size() - 1]);
	map <ii, vector <int> >::iterator it = M.find(ii(0, un.size() - 1));
	for (int i = 0; i < it->second.size(); i++)
		printf("%d%c", it->second[i], i + 1 < it->second.size()? ' ': '\n');
	return 0;
}