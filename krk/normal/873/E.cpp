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

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 3005;
const int Maxm = 5005;
const int Maxd = 4;
const ll Inf = 4000000000000000000ll;

ll pw[Maxd];
int n;
vector <ii> a;
int res[Maxn];
ll dp[Maxd][Maxn];
int par[Maxd][Maxn];
ill seq[Maxn];
int beg, en;
ll best = -Inf;
int wth[Maxd];
int L, U;

void Clear() { beg = 0, en = 0; }

ill Get(int ind)
{
	while (beg < en && seq[beg].first - ind > U) beg++;
	return beg == en? ill(-1, -Inf): seq[beg];
}

void Insert(int ind, ll val)
{
	if (val < 0) return;
	while (beg < en && seq[en - 1].second <= val) en--;
	seq[en++] = ill(ind, val);
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxd; i++)
		pw[i] = ll(Maxm) * pw[i - 1];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		a.push_back(ii(num, i));
	}
	sort(a.rbegin(), a.rend()); a.push_back(ii(0, -1));
	for (L = 1; L <= n; L++) {
		U = 2 * L;
		for (int i = 1; i < Maxd; i++) {
			Clear();
			dp[i][n] = -Inf;
			for (int j = n - 1; j >= 0; j--) {
				if (j + L <= n) Insert(j + L, ll(a[j + L - 1].first - a[j + L].first) * pw[i - 1] + dp[i - 1][j + L]);
				ill got = Get(j);
				dp[i][j] = got.second; par[i][j] = got.first;
			}
		}
		if (dp[Maxd - 1][0] > best) {
			int i = Maxd - 1, j = 0;
			while (i > 0) {
				wth[i] = par[i][j]; j = par[i][j]; i--; 
			}
			best = dp[Maxd - 1][0];
		}
	}
	for (int i = 0; i < wth[3]; i++)
		res[a[i].second] = 1;
	for (int i = wth[3]; i < wth[2]; i++)
		res[a[i].second] = 2;
	for (int i = wth[2]; i < wth[1]; i++)
		res[a[i].second] = 3;
	for (int i = wth[1]; i < n; i++)
		res[a[i].second] = -1;
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}