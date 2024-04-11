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
char str[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%s", str); str[n - 1] = '0';
	for (int i = 0, j; i < n; i = j + 1) {
		j = i;
		while (j < n && str[j] == '1') j++;
		sort(a + i, a + j + 1);
	} 
	for (int i = 1; i < n; i++)
		if (a[i - 1] >= a[i]) { printf("NO\n"); return 0; }
	printf("YES\n");
	return 0;
}