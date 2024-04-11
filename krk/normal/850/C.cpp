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

int n;
int a[Maxn];
map <int, int> has;
map <int, int> M;

int Get(int mask)
{
	map <int, int>::iterator it = M.find(mask);
	if (it == M.end()) {
		set <int> S;
		int lst = 0;
		while ((1 << lst) <= mask) lst++;
		lst--;
		for (int i = 1; i <= lst; i++) {
			int nmask = 0;
			for (int j = 1; j < i; j++) if (mask & 1 << j)
				nmask |= 1 << j;
			for (int j = i + 1; j <= lst; j++) if (mask & 1 << j)
				nmask |= 1 << (j - i);
			S.insert(Get(nmask));
		}
		int res = 0;
		while (S.find(res) != S.end()) res++;
		M[mask] = res; return res;
	}
	return it->second;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 2; j * j <= a[i]; j++) {
			int cnt = 0;
			while (a[i] % j == 0) { a[i] /= j; cnt++; }
			has[j] |= 1 << cnt;
		}
		if (a[i] > 1) has[a[i]] |= 1 << 1;
	}
	int res = 0;
	for (map <int, int>::iterator it = has.begin(); it != has.end(); it++)
		res ^= Get(it->second);
	printf("%s\n", res? "Mojtaba": "Arpa");
	return 0;
}