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

const int Maxn = 10005;

int n;
int par[Maxn], siz[Maxn];
int comp;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
	comp--;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
	comp = n;
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		unionSet(i, a);
	}
	printf("%d\n", comp);
    return 0;
}