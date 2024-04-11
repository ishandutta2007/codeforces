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
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
priority_queue <ll> Q;
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		Q.push(-a);
	}
	if (n % 2 == 0) Q.push(0);
	while (Q.size() > 1) {
		ll v1 = -Q.top(); Q.pop();
		ll v2 = -Q.top(); Q.pop();
		ll v3 = -Q.top(); Q.pop();
		ll got = v1 + v2 + v3;
		res += got;
		Q.push(-got);
	}
	printf("%I64d\n", res);
	return 0;
}