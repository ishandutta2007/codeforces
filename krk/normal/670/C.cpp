#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
map <int, int> M;
int b[Maxn], c[Maxn];
ii res = ii(-1, -1);
int bi;

int Get(int x)
{
	return M.find(x) == M.end()? 0: M[x];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int l; scanf("%d", &l);
		M[l]++;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) 
		scanf("%d", &b[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &c[i]);
		ii cand = ii(Get(b[i]), Get(c[i]));
		if (cand > res) { res = cand; bi = i; }
	}
	printf("%d\n", bi);
	return 0;
}