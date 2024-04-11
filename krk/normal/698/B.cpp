#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int p[Maxn];
int cur, rp[Maxn], tk[Maxn];
int res, root;

void Fill(int v)
{
	if (tk[v] == 1) {
		if (cur++ == 0) { res++; p[v] = v; rp[v] = v; }
		else { res++; p[v] = rp[root]; rp[v] = rp[root]; }
	} else if (tk[v] == 2) return;
	else {
		tk[v] = 1;
		if (p[v] != v) { Fill(p[v]); rp[v] = rp[p[v]]; }
		else if (cur++ == 0) rp[v] = v;
			 else { res++; p[v] = rp[root]; rp[v] = rp[root]; }
		tk[v] = 2;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	root = 1;
	for (int i = 1; i <= n; i++)
		if (p[i] == i) { root = i; Fill(i); break; }
	for (int i = 1; i <= n; i++) if (!tk[i])
		Fill(i);
	printf("%d\n", res);
	for (int i = 1; i <= n; i++)
		printf("%d%c", p[i], i + 1 <= n? ' ': '\n');
	return 0;
}