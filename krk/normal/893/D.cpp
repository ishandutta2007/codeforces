#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, d;
int a[Maxn];
int M[Maxn];

int main()
{
	scanf("%d %d", &n, &d);
	int cur = 0;
	M[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cur += a[i];
		M[i] = cur;
	}
	for (int i = n - 1; i >= 0; i--)
		M[i] = max(M[i], M[i + 1]);
	if (M[0] > d) { printf("-1\n"); return 0; }
	cur = 0;
	int was = 0;
	int tk = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		if (a[i] == 0 && cur < 0) {
			int add = d - (M[i] + tk);
			tk += add; cur += add; was++;
		} 
		if (a[i] == 0 && cur < 0) { printf("-1\n"); return 0; }
	}
	printf("%d\n", was);
	return 0;
}