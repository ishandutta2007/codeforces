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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int mod = 1000000007;

int n;
vector <ii> neigh[Maxn];

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod; 
	}
	return res;
}

ii Traverse(int v, int p, int L)
{
	if (neigh[v].size() == 1) return ii(0, 0);
	int A = 0, B = 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		ii g = Traverse(u.first, v, u.second);
		A = (A + g.first) % mod;
		B = (B + (u.second + g.second) % mod) % mod;
	}
	int inv = Inv((neigh[v].size() - A + mod) % mod);
	return ii(inv, ll(B + L) * inv % mod);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	printf("%d\n", Traverse(0, -1, 0).second);
	return 0;
}