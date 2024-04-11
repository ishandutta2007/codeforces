#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1ll << 51ll;

vector <ll> my, val;
ll n, l, r;
int res;

int Get(ll n, ll tk, ll ind)
{
	if (n <= 1) return n;
	ll ntk = tk / 2;
	if (ind <= ntk) return Get(n / 2, ntk, ind);
	if (ntk + 1 == ind) return n % 2;
	return Get(n / 2, ntk, ind - ntk - 1);
}

int main() 
{
	scanf("%I64d %I64d %I64d", &n, &l, &r);
	my.push_back(0); val.push_back(1);
	my.push_back(1); val.push_back(1);
	while (my.back() < Inf) {
		my.push_back(2ll * my.back());
		val.push_back(2ll * val.back() + 1ll);
	}
	ll tk = val[upper_bound(my.begin(), my.end(), n) - my.begin() - 1];
	for (ll i = l; i <= r; i++)
		res += Get(n, tk, i);
	printf("%d\n", res);
    return 0;
}