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

const int Maxn = 100005;
const int Maxm = 20;

int n, k;
int G[Maxn][Maxm];
ll res;

int gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int Get(int ind)
{
	int my = ind + 1;
	int cur = G[ind][0];
	if (cur == k) return n - ind;
	for (int i = Maxm - 1; i >= 0; i--) if (my + (1 << i) <= n) {
		int g = gcd(ll(G[my][i]) * cur, ll(k));
		if (g < k) { my += 1 << i; cur = g; }
	}
	return n - my;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		G[i][0] = gcd(a, k);
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			G[i][j] = gcd(ll(G[i][j - 1]) * G[i + (1 << j - 1)][j - 1], ll(k));
	for (int i = 0; i < n; i++)
		res += Get(i);
	cout << res << endl;
	return 0;
}