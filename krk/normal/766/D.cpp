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

const int Maxn = 100005;
const int Maxl = 30;

int n, m, q;
char str[Maxl], str2[Maxl];
map <string, int> ID;
int par[Maxn], siz[Maxn];
int val[Maxn];

ii getPar(int v)
{
	if (v == par[v]) return ii(v, 0);
	int p = par[v];
	ii res = getPar(p);
	par[v] = res.first; val[v] ^= res.second;
	return ii(par[v], val[v]); 
}

bool unionSet(int a, int b, int v)
{
	ii para = getPar(a), parb = getPar(b);
	if (para.first == parb.first) return (para.second ^ parb.second ^ v) == 0;
	if (siz[para.first] >= siz[parb.first]) {
		siz[para.first] += siz[parb.first]; par[parb.first] = para.first; val[parb.first] = para.second ^ parb.second ^ v;
	} else {
		siz[parb.first] += siz[para.first]; par[para.first] = parb.first; val[para.first] = para.second ^ parb.second ^ v;
	}
	return true;
}

int main() 
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf("%s", str); ID[str] = i;
		par[i] = i; siz[i] = 1; val[i] = 0;
	}
	while (m--) {
		int val; scanf("%d", &val); val--;
		scanf("%s %s", str, str2);
		if (unionSet(ID[str], ID[str2], val))
			printf("YES\n");
		else printf("NO\n");
	}
	while (q--) {
		scanf("%s %s", str, str2);
		ii a = getPar(ID[str]), b = getPar(ID[str2]);
		if (a.first != b.first) printf("3\n");
		else if (a.second != b.second) printf("2\n");
		else printf("1\n");
	}
    return 0;
}