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

int A;

int main()
{
	scanf("%d", &A);
	if (A == 1) { printf("1 1\n1\n"); return 0; }
	else {
		printf("%d 2\n", (A - 1) * 2);
		printf("1 2\n");
	}
	return 0;
}