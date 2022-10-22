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

const int Maxn = 1000006;
const ll Inf = 9000000000000000000ll;

int n;
int p[Maxn];
ll A[Maxn], B[Maxn];

void Insert(int l, int r, int val, int delt)
{
	A[l] += val; B[l] += delt;
	A[r + 1] -= (val + delt * (r + 1 - l)); B[r + 1] -= delt;
}

void smartInsert(int l, int r, int ind, int val, int delt)
{
	if (ind <= l) Insert(l - ind, r - ind, val, delt);
	else if (ind > r) Insert(l - ind + n, r - ind + n, val, delt);
	else {
		Insert(l - ind + n, n - 1, val, delt);
		val += (ind - l) * delt;
		Insert(0, r - ind, val, delt);
	} 
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]); p[i]--;
	}
	for (int i = 0; i < n; i++) {
		smartInsert(p[i], n - 1, i, 0, 1);
		smartInsert(0, p[i], i, p[i], -1);
	}
	ll res = Inf;
	int wth;
	ll val = 0, delt = 0;
	for (int i = 0; i < n; i++) {
		val += A[i];
		if (val < res) { res = val; wth = i; }
		delt += B[i]; val += delt;
	}
	printf("%I64d %d\n", res, wth);
	return 0;
}