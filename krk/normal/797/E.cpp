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

const int Maxp = 320;
const int Maxn = 100005;

int n;
int a[Maxn];
int res[Maxp][Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = Maxp - 1; i > 0; i--)
		for (int j = n; j > 0; j--)
			if (j + a[j] + i > n) res[i][j] = 1;
			else res[i][j] = 1 + res[i][j + a[j] + i];
	int q; scanf("%d", &q);
	while (q--) {
		int p, k; scanf("%d %d", &p, &k);
		if (k < Maxp) printf("%d\n", res[k][p]);
		else {
			int res = 0;
			while (p <= n) {
				res++; p = p + a[p] + k;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}