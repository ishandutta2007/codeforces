#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n, m, k;

int main()
{
	scanf("%d %d %d", &n, &m, &k); k--;
	int lan = k / (2 * m); k %= (2 * m);
	int desk = k / 2; k %= 2;
	printf("%d %d %c\n", lan + 1, desk + 1, k? 'R': 'L');
	return 0;
}