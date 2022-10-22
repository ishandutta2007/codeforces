#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2000005;

int n;
int a[Maxn], b[Maxn];
vector <int> un;
int par[Maxn], siz[Maxn];
int val[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (siz[a] < siz[b]) swap(a, b);
	if (a != b) {
		siz[a] += siz[b]; par[b] = a;
		val[a] += val[b];
	}
	if (++val[a] > siz[a]) return false;
	return true;
}

bool Okay(int x)
{
	for (int i = 0; i < un.size(); i++) {
		par[i] = i; siz[i] = 1;
		val[i] = 0;
	}
	for (int i = 0; i < n; i++)
		if (b[i] <= x) {
			if (!unionSet(a[i], b[i])) return false;
		} else if (a[i] <= x) {
			int par = getPar(a[i]);
			if (++val[par] > siz[par]) return false;
		} else return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		un.push_back(a[i]);
		un.push_back(b[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
		b[i] = lower_bound(un.begin(), un.end(), b[i]) - un.begin();
	}
	int lef = 0, rig = int(un.size()) - 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Okay(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	rig++;
	if (rig >= un.size()) printf("-1\n");
	else printf("%d\n", un[rig]);
	return 0;
}