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

bool Prime(int x)
{
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main() 
{
	int n; scanf("%d", &n);
	for (int i = 1; ; i++)
		if (!Prime(n * i + 1)) {
			printf("%d\n", i); return 0;
		}
    return 0;
}