#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 60005;

int n;
vector <int> res;

int main()
{
	scanf("%d", &n);
	ll sum = ll(n) * (n + 1) / 2;
	ll a = sum / 2, b = (sum + 1) / 2;
	ll tk = 0;
	for (int i = n; i >= 1; i--) if (tk + i <= a) {
		tk += i; res.push_back(i);
	}
	printf("%I64d\n", sum - tk - tk);
	printf("%d", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf(" %d", res[i]);
	printf("\n");
	return 0;
}