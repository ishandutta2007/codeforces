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

const int Maxn = 1505;

int a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (a == 1 || a == 2 && b == 2 || a == 3 && b == 3 && c == 3 || a == 2 && b == 4 && c == 4)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}