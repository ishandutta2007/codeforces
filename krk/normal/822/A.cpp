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

ll a, b;

int main()
{
	cin >> a >> b;
	ll res = 1;
	for (int i = 2; i <= min(a, b); i++)
		res *= i;
	printf("%I64d\n", res);
	return 0;
}