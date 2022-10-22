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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 4000000000000000000ll;

int n;
ll b[Maxn];
ll a[Maxn];
int p[Maxn], k[Maxn];
vector <int> neigh[Maxn];

ll Mult(ll a, ll b)
{
	return a <= Inf / b? a * b: Inf;
}

ll Get(int v)
{
	ll st = b[v] - a[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		st += Get(neigh[v][i]);
		if (st <= -Inf) return -Inf;
	}
	if (v != 1 && st < 0) {
		ll nw = Mult(-st, k[v]);
		return -nw;
	}
	return st;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 2; i <= n; i++) {
		scanf("%d %d", &p[i], &k[i]);
		neigh[p[i]].push_back(i);
	}
	printf("%s\n", Get(1) >= 0? "YES": "NO");
	return 0;
}