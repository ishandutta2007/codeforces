#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int w, l;
int a[Maxn];
int has[Maxn];
map <int, int> M;
int res;

void Add(int x)
{
	if (x + l >= w) { res += has[x]; return; }
	map <int, int>::iterator it = M.upper_bound(x + l);
	while (it != M.begin() && has[x] > 0) {
		it--;
		if (it->first <= x) break;
		int tk = min(has[x], it->second);
		has[it->first] += tk; has[x] -= tk; it->second -= tk;
		if (it->second == 0) M.erase(it++);
	}
}

int main()
{
	scanf("%d %d", &w, &l);
	for (int i = 1; i < w; i++) {
		scanf("%d", &a[i]);
		M[i] = a[i];
	}
	has[0] = 2000000000;
	for (int i = 0; i < w; i++)
		Add(i);
	printf("%d\n", res);
	return 0;
}