#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
int res;

int main()
{
	cin >> n;
	ll a = 1, b = 2;
	int res = 0;
	while (b <= n) {
		ll p = a; a = b; b = p + a;
		res++;
	}
	printf("%d\n", res);
	return 0;
}