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

int n;

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i += 2)
		printf("%d ", i);
	int st = n % 2? n - 2: n - 1;
	for (int i = st; i >= 1; i -= 2)
		printf("%d ", i);
	for (int i = 2; i <= n; i += 2)
		printf("%d ", i);
	st = n % 2? n - 1: n - 2;
	for (int i = st; i >= 1; i -= 2)
		printf("%d ", i);
	printf("%d\n", n);
    return 0;
}