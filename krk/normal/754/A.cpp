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

const int Maxn = 105;

int n;
int a[Maxn], sum;

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); sum += a[i];
	}
	if (sum != 0) {
		printf("YES\n");
		printf("1\n");
		printf("1 %d\n", n);
		return 0;
	}
	int i = 0;
	while (i < n && a[i] == 0) i++;
	if (i < n) {
		printf("YES\n");
		printf("2\n");
		printf("1 %d\n", i + 1);
		printf("%d %d\n", i + 2, n);
		return 0;
	}
	printf("NO\n");
    return 0;
}