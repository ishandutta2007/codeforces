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
int res;

int main()
{
	scanf("%d", &n);
	for (int a = 1; a <= n; a++)
		for (int b = a; b <= n; b++) {
			int c = (a ^ b);
			if (b <= c && c <= n && c < a + b)
				res++;
		}
	printf("%d\n", res);
	return 0;
}