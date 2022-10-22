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
int x;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		bool got = false;
		for (int i = 0; i <= 100; i++)
			for (int j = 0; j <= 100; j++)
				got |= 3 * i + 7 * j == x;
		printf("%s\n", got? "YES": "NO");
	}
	return 0;
}