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

typedef long long ll;

int n;

int main()
{
	scanf("%d", &n);
	ll pw = 1, sub = 0;
	while (n >= 10) {
		sub += pw * ll(n % 10);
		pw *= 10ll; n /= 10ll;
	}
	printf("%I64d\n", pw - sub);
	return 0;
}