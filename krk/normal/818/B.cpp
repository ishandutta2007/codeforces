#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int a[Maxn];
int my[Maxn], was[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]); a[i]--;
	}
	for (int i = 0; i + 1 < m; i++) {
		int dif = a[i + 1] - a[i];
		if (dif <= 0) dif += n;
		if (my[a[i]] == 0) { 
			my[a[i]] = dif; 
			if (++was[dif] > 1) { printf("-1\n"); return 0; } 
		} else if (my[a[i]] != dif) { printf("-1\n"); return 0; }
	}
	int nxt = 1;
	for (int i = 0; i < n; i++) {
		if (my[i] == 0) {
			while (was[nxt] != 0) nxt++;
			my[i] = nxt; was[nxt]++;
		}
		printf("%d%c", my[i], i + 1 < n? ' ': '\n');
	}
	return 0;
}