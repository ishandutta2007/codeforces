#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 4;
const int MaxN = 1 << Maxn;

int n, k;
bool was[MaxN];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			mask |= a << j;
		}
		was[mask] = true;
	}
	for (int i = 1; i < 1 << MaxN; i++) {
		int st[Maxn] = {};
		bool ok = true;
		for (int j = 0; j < MaxN; j++) if (i & 1 << j)
			if (!was[j]) { ok = false; break; }
			else for (int l = 0; l < Maxn; l++)
					if (j & 1 << l) st[l]--;
					else st[l]++;
		for (int l = 0; l < Maxn; l++)
			if (st[l] < 0) { ok = false; break; }
		if (ok) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}