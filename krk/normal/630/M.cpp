#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll x;

int main()
{
	scanf("%I64d", &x);
	x %= 360;
	x = (x + 360) % 360;
	x %= 315;
	printf("%I64d\n", (x + 44) / 90);
	return 0;
}