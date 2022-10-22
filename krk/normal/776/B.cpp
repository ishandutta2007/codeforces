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
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return false;
	return true;
}

int main() 
{
	int n; scanf("%d", &n);
	printf("%d\n", n <= 2? 1: 2);
	for (int i = 2; i <= n + 1; i++)
		printf("%d%c", Prime(i)? 1: 2, i + 1 <= n + 1? ' ': '\n');
    return 0;
}