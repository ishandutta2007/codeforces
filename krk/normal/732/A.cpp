#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k, r;
int cur;
int res;

int main()
{
	scanf("%d %d", &k, &r);
	res = 1; cur = k % 10;
	while (cur != r && cur != 0) {
		res++; cur = (cur + k) % 10;
	}
	printf("%d\n", res);
	return 0;
}