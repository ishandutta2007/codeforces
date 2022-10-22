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

const int Maxm = 1000002;
const ll Inf = 1000000000000000000ll;

int n, x, y, k;
ll sum[Maxm];
int cnt[Maxm];
ll res = Inf;

ll Mult(ll a, ll b)
{
	if (a == 0 || b == 0) return 0;
	if (a <= Inf / b) return a * b;
	return Inf;
}

int main()
{
	scanf("%d %d %d", &n, &x, &y); k = x / y + 1;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum[a] += a; cnt[a]++;
	}
	for (int i = 1; i < Maxm; i++) {
		sum[i] += sum[i - 1];
		cnt[i] += cnt[i - 1];
	}
	for (int i = 2; i < Maxm; i++) {
		int tk = min(i, k);
		int tcnt = 0; ll tsum = 0;
		for (int j = i; j < Maxm + i; j += i) {
			int got = cnt[min(j, Maxm - 1)] - cnt[min(j - tk, Maxm - 1)];
			tcnt += got; tsum += ll(j) * got - ll(sum[min(j, Maxm - 1)] - sum[min(j - tk, Maxm - 1)]);
		}
		res = min(res, Mult(n - tcnt, x) + Mult(tsum, y));
	}
	printf("%I64d\n", res);
	return 0;
}