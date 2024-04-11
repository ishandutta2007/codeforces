#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll r;
int l[Maxn], t[Maxn];
vector <ll> res;

ll Count(int ind, ll ap)
{
	if (ind >= n) return 0;
	if (ap >= l[ind]) return Count(ind + 1, ap - l[ind]);
	ll b = 2 * l[ind] - 2 * t[ind] - ap;
	if (b <= 0) return Count(ind + 1, 0);
	ll x = l[ind] - ap - b; ap += x;
	if (ap == l[ind]) return Count(ind + 1, 0);
	ll tk = (l[ind] - ap) / (2 * r) + bool((l[ind] - ap) % (2 * r) != 0);
	ap += tk * 2ll * r;
	return tk + Count(ind + 1, ap - l[ind]);
}

void Print(ll tim, int ind, ll ap)
{
	if (ind >= n) return;
	if (ap >= l[ind]) { Print(tim, ind + 1, ap - l[ind]); return; }
	ll b = 2 * l[ind] - 2 * t[ind] - ap;
	if (b <= 0) { tim += l[ind] - ap; Print(tim, ind + 1, 0); return; }
	ll x = l[ind] - ap - b;
	tim += x; ap += x;
	while (ap < l[ind]) {
		res.push_back(tim);
		tim += r; ap += 2 * r;
	}
	Print(tim, ind + 1, ap - l[ind]);
}

int main()
{
	scanf("%d %I64d", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]); l[i] *= 2;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		if (l[i] - t[i] > t[i]) { printf("-1\n"); return 0; }
	}
	ll ans = Count(0, 0);
	printf("%I64d\n", ans);
	if (ans <= 100000) {
		Print(0, 0, 0);
		assert(ans == res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%I64d%c", res[i], i + 1 < res.size()? ' ': '\n');
	}
	return 0;
}