#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int X1, Y1, X2, Y2;

int main()
{
	scanf("%d %d", &X1, &Y1);
	scanf("%d %d", &X2, &Y2);
	int dx = max(2, abs(X1 - X2) + 1);
	int dy = max(2, abs(Y1 - Y2) + 1);
	printf("%d\n", 2 * dx + 2 * dy);
	return 0;
}