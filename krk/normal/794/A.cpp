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

int a, b, c;
int n;
int res;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &n);
	while (n--) {
		int x; scanf("%d", &x);
		res += b < x && x < c;
	}
	printf("%d\n", res);
	return 0;
}