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

int n, k;
int a[Maxn], b[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	sort(b, b + k);
	bool ok = false;
	int p = k - 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) a[i] = b[p--];
		if (i && a[i - 1] >= a[i]) ok = true;
	}
	printf("%s\n", ok? "Yes": "No");
	return 0;
}