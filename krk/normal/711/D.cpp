#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int pw[Maxn];
int n;
int a[Maxn];
int res = 1;
int tk[Maxn];
bool cyc[Maxn];

void Take(int v)
{
	if (tk[v] == 2) return;
	if (tk[v] == 1) {
		int cnt = 0;
		int cur = v;
		while (!cyc[cur]) {
			cyc[cur] = true; cnt++;
			cur = a[cur];
		}
		cnt = (pw[cnt] - 2 + mod) % mod;
		res = ll(res) * cnt % mod;
		return;
 	}
 	tk[v] = 1;
 	Take(a[v]);
 	tk[v] = 2;
}


int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = 2 * pw[i - 1] % mod;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		Take(i);
	for (int i = 1; i <= n; i++)
		if (!cyc[i]) res = 2 * res % mod;
	printf("%d\n", res);
	return 0;
}