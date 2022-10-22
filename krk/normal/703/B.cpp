#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k;
int c[Maxn];
bool cap[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	while (k--) {
		int v; scanf("%d", &v);
		cap[v] = true;
	}
	ll res1 = 0, res2 = 0;
	for (int i = 1; i < n; i++)
		if (!cap[i] && !cap[i + 1]) res1 += ll(c[i]) * c[i + 1];
	if (!cap[n] && !cap[1]) res1 += ll(c[n]) * c[1];
	ll a = 0, b = 0;
	for (int i = 1; i <= n; i++)
		if (cap[i]) a += c[i];
		else b += c[i];
	res1 += a * b;
	for (int i = 1; i <= n; i++)
		if (cap[i]) res2 += ll(c[i]) * (a - c[i]);
	cout << res1 + res2 / 2 << endl;
	return 0;
}