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

const int Maxn = 200005;

int n, m;
int a[Maxn];
int b[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		int ind = upper_bound(a, a + n, b[i]) - a;
		printf("%d%c", ind, i + 1 < m? ' ': '\n');
	}
	return 0;
}