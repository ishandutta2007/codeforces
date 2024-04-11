#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, k;
ll res;

int main()
{
	scanf("%d %d", &n, &k);
	int add = n - 1;
	while (add > 0 && k) {
		res += add; add--;
		res += add; add--;
		k--;
	}
	printf("%I64d\n", res);
	return 0;
}