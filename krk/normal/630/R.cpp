#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	ll n; scanf("%I64d", &n);
	printf("%d\n", n % 2? 1: 2);
	return 0;
}