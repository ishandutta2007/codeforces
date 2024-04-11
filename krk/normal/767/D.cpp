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

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 10000005;
const ll Inf = 1000000000000000000ll;

int n, m, k;
int has[Maxm];
ii shop[Maxn];
int seq[Maxn], slen;

int main() 
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int f; scanf("%d", &f); f++;
		has[f]++;
	}
	for (int i = 1; i < Maxm; i++) {
		has[i] += has[i - 1];
		if (ll(k) * i < has[i]) { printf("-1\n"); return 0; }
	}
	for (int i = 0; i < m; i++) {
		int f; scanf("%d", &f); f++;
		shop[i] = ii(f, i);
	}
	ll lft = Inf;
	int pnt = Maxm;
	sort(shop, shop + m);
	for (int i = m - 1; i >= 0; i--) {
		while (pnt > shop[i].first) {
			pnt--; lft = min(lft, ll(k) * pnt - has[pnt]);
		}
		if (lft > 0) { seq[slen++] = shop[i].second; lft--; }
	}
	printf("%d\n", slen);
	for (int i = 0; i < slen; i++)
		printf("%d%c", seq[i] + 1, i + 1 < slen? ' ': '\n');
    return 0;
}