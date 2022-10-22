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

int main()
{
	scanf("%d", &n);
	int md = n % 10;
	if (md <= 4) n -= md;
	else n += 10 - md;
	printf("%d\n", n);
	return 0;
}