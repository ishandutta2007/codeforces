#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;

int main()
{
	scanf("%d", &n);
	printf("%I64d\n", 2ll * ((1ll << n) - 1));
	return 0;
}