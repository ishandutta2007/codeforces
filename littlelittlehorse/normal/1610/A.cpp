#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m;

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d%d", &n, &m);
		if (n == 1 && m == 1)
			printf("0\n");
		else
			if (n == 1 || m == 1)
				printf("1\n");
			else
				printf("2\n");
	}
}