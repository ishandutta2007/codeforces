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

int n, k;

int main() 
{
	scanf("%d %d", &n, &k);
	int lft = 240 - k;
	int i = 1;
	while (i <= n && 5 * i <= lft) { lft -= 5 * i; i++; }
	printf("%d\n", i - 1);
    return 0;
}