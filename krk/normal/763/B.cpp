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

const int Maxn = 500005;

int n;

int main() 
{
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int c = 0;
		if (x1 % 2) c |= 1;
		if (y1 % 2) c |= 2;
		printf("%d\n", c + 1);
	}
    return 0;
}