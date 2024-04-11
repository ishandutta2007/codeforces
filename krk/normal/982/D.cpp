#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii a[Maxn];
int par[Maxn], siz[Maxn];
int places;
map <int, int> M;
int best = 0;
int bk = 1;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (siz[a] < siz[b]) swap(siz[a], siz[b]);
	if (--M[siz[a]] == 0) M.erase(siz[a]);
	if (--M[siz[b]] == 0) M.erase(siz[b]);
	siz[a] += siz[b]; par[b] = a;
	M[siz[a]]++;
}

void Add(int x)
{
	par[x] = x; siz[x] = 1; places++; M[1]++;
	if (x > 0 && siz[x - 1] > 0) {
		unionSet(x - 1, x);
		places--;
	}
	if (x + 1 < n && siz[x + 1] > 0) {
		unionSet(x, x + 1);
		places--;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0, j; i < n; i++) {
		j = i;
		while (j < n && a[i].first == a[j].first) {
			Add(a[j].second); j++;
		}
		if (places > best && M.begin()->first == M.rbegin()->first) {
			best = places; bk = a[i].first + 1;
		}
	}
	printf("%d\n", bk);
	return 0;
}