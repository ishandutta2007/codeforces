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

int n, x;
int a;

int main()
{
	scanf("%d %d", &n, &x); x -= (n - 1);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		x -= a;
	}
	printf("%s\n", x == 0? "YES": "NO");
	return 0;
}