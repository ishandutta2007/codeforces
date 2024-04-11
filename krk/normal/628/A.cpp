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

int n, b, p;

int Solve(int n)
{
	if (n == 1) return 0;
	int pw = 0;
	while (1 << pw <= n) pw++;
	pw--;
	int pl = (1 << pw) / 2;
	int res = pl * (2 * b + 1);
	res += Solve(n - (1 << pw) + pl);
	return res;
}

int main() 
{
	scanf("%d %d %d", &n, &b, &p);
	printf("%d %d\n", Solve(n), n * p);
    return 0;
}