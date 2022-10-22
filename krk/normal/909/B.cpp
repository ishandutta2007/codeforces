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
	cin >> n;
	int res = (n + 2) / 2 * ((n + 1) / 2);
	printf("%d\n", res);
	return 0;
}