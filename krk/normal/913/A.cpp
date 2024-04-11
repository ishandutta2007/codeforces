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

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	if (n < 29) m = m & ((1 << n) - 1);
	printf("%d\n", m);
	return 0;
}