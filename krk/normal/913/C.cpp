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

const int Maxb = 31;
const ll Inf = 1000000000000000000ll;

int n, L;
ll C[Maxb];

int main()
{
	scanf("%d %d", &n, &L);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &C[i]);
	for (int i = n; i < Maxb; i++)
		C[i] = Inf;
	for (int i = 0; i < Maxb; i++) {
		for (int j = i + 1; j < Maxb; j++)
			C[i] = min(C[i], C[j]);
		if (i > 0)
			C[i] = min(C[i], C[i - 1] + C[i - 1]);
	}
	ll res = Inf;
	ll cur = 0;
	for (int i = Maxb - 1; i >= 0; i--)
		if (!(L & 1 << i))
			res = min(res, cur + C[i]);
		else cur += C[i];
	res = min(res, cur);
	printf("%I64d\n", res);
	return 0;
}