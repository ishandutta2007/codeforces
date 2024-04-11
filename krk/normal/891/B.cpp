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

typedef pair <int, int> ii;

const int Maxn = 23;

int n;
ii a[Maxn];
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	res[a[n - 1].second] = a[0].first;
	for (int i = 0; i + 1 < n; i++)
		res[a[i].second] = a[i + 1].first;
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}