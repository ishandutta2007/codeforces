#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i + 2 < n; i++)
		if (a[i] + a[i + 1] > a[i + 2]) { printf("YES\n"); return 0; }
	printf("NO\n");
    return 0;
}