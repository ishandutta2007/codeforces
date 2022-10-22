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

int x, y;

int main()
{
	scanf("%d %d", &x, &y);
	if (y < 1) { printf("No\n"); return 0; }
	int got = y - 1;
	if (got == x || got > 0 && got < x && (x - got) % 2 == 0)
		printf("Yes\n");
	else printf("No\n");
	return 0;
}