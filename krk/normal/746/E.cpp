#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

set <int> S;
int n, m;
int a[Maxn];
int ev, od;
int nxe, nxo;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (S.find(a[i]) != S.end()) { a[i] = -1; res++; }
		else { 
			S.insert(a[i]); 
			if (a[i] % 2 == 0) ev++;
			else od++;
		}
	}
	nxe = 2, nxo = 1;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			if (a[i] % 2 == 1 && od > n / 2) { a[i] = -1; od--; res++; }
			else if (a[i] % 2 == 0 && ev > n / 2) { a[i] = -1; ev--; res++; }
	for (int i = 0; i < n; i++)
		if (a[i] == -1)
			if (ev <= od) {
				while (S.find(nxe) != S.end()) nxe += 2;
				if (nxe > m) { printf("-1\n"); return 0; }
				a[i] = nxe; nxe += 2; ev++;
			} else {
				while (S.find(nxo) != S.end()) nxo += 2;
				if (nxo > m) { printf("-1\n"); return 0; }
				a[i] = nxo; nxo += 2; od++;
			}
	printf("%d\n", res);
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	return 0;
}