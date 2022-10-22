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

const int Maxn = 200005;

int n;
int a[Maxn];
int p[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i]);
	int savi = -1;
	for (int i = 1; i <= n; i++)
		if (a[i] > 1 && a[i - 1] > 1) savi = i;
	if (savi == -1) printf("perfect\n");
	else {
		printf("ambiguous\n");
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++)
				p[sum + j] = sum;
			sum += a[i];
		}
		for (int i = 1; i <= sum; i++)
			printf("%d%c", p[i], i + 1 <= sum? ' ': '\n');
		sum = 0;
		for (int i = 0; i < savi; i++)
			sum += a[i];
		p[sum + 1] = sum - 1;
		for (int i = savi; i <= n; i++)
			sum += a[i];
		for (int i = 1; i <= sum; i++)
			printf("%d%c", p[i], i + 1 <= sum? ' ': '\n');
	}
	return 0;
}