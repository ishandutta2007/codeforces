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
int a, b;

int main()
{
	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> a >> b;
	int dx = abs(X1 - X2); 
	int dy = abs(Y1 - Y2);
	if (dx % a == 0 && dy % b == 0)
		if ((dx / a) % 2 == (dy / b) % 2)
			printf("YES\n");
		else printf("NO\n");
	else printf("NO\n");
	return 0;
}