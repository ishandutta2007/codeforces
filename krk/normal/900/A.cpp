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

int n;
int neg, pos;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		if (x > 0) pos++;
		else neg++;
	}
	if (pos <= 1 || neg <= 1) printf("Yes\n");
	else printf("No\n");
	return 0;
}